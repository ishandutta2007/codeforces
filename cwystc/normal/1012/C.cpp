#include<cstdio>
#include<cstring>
#include<iostream>
#include<stdlib.h>
#include<ctime>
#include<string>
#include<cmath>
#include<algorithm>
#include<complex>
#include<vector>
#include<set>
#include<map>
#include<queue>
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define LL long long
#define FOR(i,a,b) for (int i=a;i<=b;++i)
#define FORD(i,a,b) for (int i=a;i>=b;--i)
using namespace std;
typedef pair<int,int> pa;
void getint(int &v){
    char ch,fu=0;
    for(ch='*'; (ch<'0'||ch>'9')&&ch!='-'; ch=getchar());
    if(ch=='-') fu=1, ch=getchar();
    for(v=0; ch>='0'&&ch<='9'; ch=getchar()) v=v*10+ch-'0';
    if(fu) v=-v;
}
const LL INF=1e18;
LL ans[5010],g[5010],f[5010][5010];
int n,K,a[5010];
int main(){
	cin>>n;
	FOR(i,1,n) getint(a[i]);
	if (n==1) return puts("0"),0;
	K=(n+1)/2;
	FOR(i,0,n)
		FOR(j,0,K)
			f[i][j]=INF;
	f[0][0]=0;
	FOR(i,0,K) g[i]=INF;
	g[0]=0;
	f[1][0]=0;
	f[1][1]=0;
	FOR(i,2,n){
		FOR(j,0,K){
			if (i-2>=1) f[i][j]=min(f[i][j],f[i-2][j-1]+ max(0,(a[i-1]-min(a[i]-1,a[i-2]-1)) ));
			if (i-3>=1) g[j-1]=min(g[j-1],f[i-3][j-1]+max(0,a[i-2]-(a[i-3]-1)));
			f[i][j]=min(f[i][j],g[j-1]+max(0,a[i-1]-(a[i]-1)));
		}
	}
	FOR(j,0,K) ans[j]=INF;
	FOR(i,0,n)
		FOR(j,1,K){
			LL t=f[i][j];
			if (i<n) t+=max(0,a[i+1]-(a[i]-1));
			ans[j]=min(ans[j],t);
			int tt=1;
		}
	FOR(i,1,K) printf("%lld ",ans[i]);
    return 0;
}