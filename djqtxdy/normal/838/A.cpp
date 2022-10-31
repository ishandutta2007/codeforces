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
const int Maxn=2505;
bool isp[Maxn];
vector<int> p;
void _init(){
	for (int i=2;i<Maxn;i++){
		isp[i]=true;
	}
	for (int i=2;i<Maxn;i++){
		if (isp[i]){
			p.push_back(i);
			for (int j=i+i;j<Maxn;j+=i){
				isp[j]=false;
			}
		}
	}
}
char c[Maxn*2][Maxn*2];
int sum[Maxn*2][Maxn*2];
int main(){
	_init();
	int n,m;
	scanf("%d %d",&n,&m);
	for (int i=0;i<n;i++){
		scanf("%s",c[i]);
	}
	for (int i=1;i<Maxn*2;i++){
		for (int j=1;j<Maxn*2;j++){
			sum[i][j]=sum[i-1][j]+sum[i][j-1]-sum[i-1][j-1]+(c[i-1][j-1]=='1');
		}
	}
	//cout<<sum[3][5]<<endl;
	int ans=1e9;
	for (int i=0;i<p.size();i++){
		int x=p[i];
		int nowans=0;
		for (int j=x;j<=n+x;j+=x){
			for (int k=x;k<=m+x;k+=x){
				int tt=sum[j][k]-sum[j][k-x]-sum[j-x][k]+sum[j-x][k-x];
				nowans+=min(tt,x*x-tt); 
			}
		}
	//	cout<<p[i]<<" "<<nowans<<endl;
		ans=min(ans,nowans);
	}
	printf("%d\n",ans);
	return 0;
}