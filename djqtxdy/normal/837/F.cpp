#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <vector>
#include <deque>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <algorithm>
#include <functional>
#include <utility>
#include <bitset>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include<windows.h>
#include <cstdio>
#include <cstring>
#include <climits>
#include <string.h>
#include <stdio.h>
#define LL long long
#define all(x) (x).begin(),(x).end()
#define pii pair<int,int>
#define piii pair<int, pii >
#define REP(i,n) for (int (i)=0;(i)<(n);(i)++)
#define vi vector<int>
#define vpi vector< pii >
#define INF 2147483647
#define big 19260817
#define pb push_back
#define mp make_pair
using namespace std;
const int Maxk=1005;
string mul(string a,string b){
	int res[Maxk];
	memset(res,0,sizeof(res));
	reverse(a.begin(),a.end());
	reverse(b.begin(),b.end());
	for (int i=0;i<a.length();i++){
		for (int j=0;j<b.length();j++){
			res[i+j]+=(a[i]-'0')*(b[j]-'0');
		}
	}
	for (int i=0;i<Maxk;i++){
		if (res[i]>=10) {
			res[i+1]+=(res[i]/10);
			res[i]%=10;
		}
	}
	string ret;
	bool flag=false;
	for (int i=Maxk-1;i>=0;i--){
		if (flag || res[i]){
			flag=true;
			ret=ret+(char)(res[i]+'0');
		}
	}
	if (ret=="") ret="0";
	return ret;
}
string add(string a,string b){
	if (a.length()<b.length()) swap(a,b);
	while (a.length()!=b.length()){
		b='0'+b;
	}
	for (int i=a.length()-1;i>=0;i--){
		a[i]+=(b[i]-'0');
		if (a[i]>'9' && i){
			a[i]-=10;
			a[i-1]++;
		}
	}
	if (a[0]>'9'){
		a[0]-=10;
		a='1'+a;
	}
	return a;
}

// cf IO: I64d
// atcoder IO: 
inline int read()
{
	int x = 0, f = 1; char ch = getchar();
	while (ch < '0' || ch > '9') { if (ch == '-') f = -1; ch = getchar(); }
	while (ch >= '0' && ch <= '9') { x = x * 10 + ch - '0'; ch = getchar(); }
	return x * f;
}
const int Maxn=200005;
long long a[Maxn*2];
LL sum[Maxn*2];
int main(){
	int n;
	scanf("%d",&n);
	long long k;
	scanf("%I64d",&k);
	for (int i=0;i<2*Maxn;i++) sum[i]=a[i]=0LL;
	for (int i=0;i<n;i++) scanf("%I64d",&a[i]);
	vector<int> pos;
	int cnt=0;
	for (int i=0;i<n;i++) if (a[i]!=0) cnt++,pos.pb(i);
	if (cnt==2 && pos[0]==pos[1]-1 && pos[1]==n-1){
		if (k<=a[pos[0]] || k<=a[pos[1]]) cout<<0<<endl;
		else{
			k-=a[pos[1]];
			printf("%I64d\n",(k+a[pos[0]]-1)/a[pos[0]]);
		}
		return 0;
	}
	if (cnt==2 && pos[0]==pos[1]-2 && pos[1]==n-1){
		pos[1]--;
		pos.pb(pos[1]+1);
		cnt++;
	}
	if (cnt==2 && pos[0]==pos[1]-1 && pos[1]==n-2){
		pos.pb(pos[1]+1);
		cnt++;
	}
	if (cnt==3 && pos[0]==pos[1]-1 && pos[1]==pos[2]-1 && pos[2]==n-1){
		if (k<=a[pos[0]] || k<=a[pos[1]] || k<=a[pos[2]]) cout<<0<<endl;
		else{
			k-=a[pos[2]];
			LL l=0,r=2e9;
			while (r-l>1){
				LL md=(l+r)>>1;
				if (md*(md+1)/2>2000000000000000000LL/a[pos[0]]) r=md;
				else{
					if (md*(md+1)/2*a[pos[0]]+md*a[pos[1]]>=k) r=md;
					else l=md;
				}
			}
			printf("%I64d\n",r);
		}
		return 0;
	}
	int t=0;
	while (a[t]==0) t++;
	for (int i=t;i<n;i++){
		a[i-t]=a[i];
	}
	n-=t;
	for (int i=0;i<=Maxn;i++) sum[i]=0LL; 
	for (int ans=0;;ans++){
		for (int i=0;i<n;i++){
			if (a[i]>=k){
				printf("%d\n",ans);
				return 0;
			}
		}
		for (int i=1;i<=n;i++){
			sum[i]=sum[i-1]+a[i-1];
		}
		for (int i=1;i<=n;i++){
			a[i-1]=sum[i];
		//	cout<<a[i-1]<<' ';
		}
		//cout<<endl;
	//	Sleep(200);
	}
}