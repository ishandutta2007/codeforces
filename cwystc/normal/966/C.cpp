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
void getint(int &v){
    char ch,fu=0;
    for(ch='*'; (ch<'0'||ch>'9')&&ch!='-'; ch=getchar());
    if(ch=='-') fu=1, ch=getchar();
    for(v=0; ch>='0'&&ch<='9'; ch=getchar()) v=v*10+ch-'0';
    if(fu) v=-v;
}
LL a[500010];
vector<int> v[66];
bool u[500010];
int ts,n,tmp[500010],STK[500010],now,gg,g[500010],top,stk[500010];
int main(){
	cin>>n;
	FOR(i,1,n) cin>>a[i];
	FOR(i,1,n)
		FORD(j,59,0)
			if ((a[i]>>j)&1){
				v[j].pb(i);
			}
	FORD(j,59,0){
		ts=0;
		for (int i=0;i<v[j].size();++i){
			int t=v[j][i];
			if (u[t]) continue;
			u[t]=1;
			tmp[++ts]=t;
		}
		if (!ts) continue;
		STK[now=1]=tmp[ts--];
		FOR(i,1,top){
			STK[++now]=stk[i];
			if ((a[stk[i]]>>j)&1){
				if (ts) STK[++now]=tmp[ts--];
			}
		}
		if (ts) return puts("No"),0;
		top=now;
		FOR(i,1,top) stk[i]=STK[i]; 
	}
	puts("Yes");
	FOR(i,1,n) printf("%lld ",a[stk[i]]);
	return 0;
}