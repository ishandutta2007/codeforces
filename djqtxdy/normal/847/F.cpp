//This disgusting code is wriiten by Juruo D0zingbear
//Please don't hack me! 0v0 <3
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
#include <assert.h>
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
const int Maxn=105;
int g[Maxn];
int vo[Maxn];
int lst[Maxn];
int ans[Maxn];
bool cmp(pair<int,pair<int,int> > x,pair<int,pair<int,int> > y){
	if (x.first!=y.first) return x.first>y.first;
	return x.second.first<y.second.first;
}
int main(){
	int n,k,m,a;
	scanf("%d %d %d %d",&n,&k,&m,&a);
	for (int i=1;i<=a;i++){
		scanf("%d",&g[i]);
		vo[g[i]]++;
		lst[g[i]]=i;
	}
	int rem=m-a;
	if (rem==0){
		vector<pair<int,pair<int,int> > > vvv;
		for (int i=1;i<=n;i++){
			vvv.pb(mp(vo[i],mp(lst[i],i)));
		}
		sort(vvv.begin(),vvv.end(),cmp);
		for (int i=0;i<k;i++){
			ans[vvv[i].second.second]=1;
		}
		for (int i=1;i<=n;i++){
			if (ans[i]==1 && vo[i]!=0){
				printf("1 ");
			}
			else{
				printf("3 ");
			}
		}
		return 0;
	}
	for (int i=1;i<=n;i++){
		rem=m-a;
		if (rem+vo[i]==0){
			printf("3 ");
		}
		else{
			int cnt=0;
			int nv=rem+vo[i];
			for (int j=1;j<=n;j++){
				if (i==j) continue;
				if (vo[j]>=nv) cnt++;
			}
			if (cnt>k-1){
				printf("3 ");
			}
			else{
				nv=vo[i];
				int cntt=0;
				vector<int> vv;
				for (int j=1;j<=n;j++){
					if (i==j) continue;
					if (vo[j]>vo[i] || (vo[j]==vo[i] && lst[j]<lst[i])){
						cntt++;
					}
					else{
						vv.pb(vo[j]);
					}
				}
				sort(vv.begin(),vv.end());
				reverse(vv.begin(),vv.end());
				for (int j=0;j<vv.size();j++){
					if (vv[j]+rem>vo[i]){
						cntt++;
						rem-=(vo[i]+1-vv[j]);
					}
				}
				if (cntt>k-1 || nv==0){
					printf("2 ");
				}
				else{
					printf("1 ");
				}
			}
		}
	}
	printf("\n");
	
}