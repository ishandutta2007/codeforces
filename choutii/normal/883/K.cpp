#include <iostream>
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>
#include <string>
#include <bitset>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <algorithm>
#include <sstream>
#include <stack>
#include <iomanip>
using namespace std;
#define pb push_back
#define mp make_pair
typedef pair<int,int> pii;
typedef long long ll;
typedef double ld;
typedef vector<int> vi;
#define fi first
#define se second
#define fe first
#define FO(x) {freopen(#x".in","r",stdin);freopen(#x".out","w",stdout);}
#define Edg int M=0,fst[SZ],vb[SZ],nxt[SZ];void ad_de(int a,int b){++M;nxt[M]=fst[a];fst[a]=M;vb[M]=b;}void adde(int a,int b){ad_de(a,b);ad_de(b,a);}
#define Edgc int M=0,fst[SZ],vb[SZ],nxt[SZ],vc[SZ];void ad_de(int a,int b,int c){++M;nxt[M]=fst[a];fst[a]=M;vb[M]=b;vc[M]=c;}void adde(int a,int b,int c){ad_de(a,b,c);ad_de(b,a,c);}
#define es(x,e) (int e=fst[x];e;e=nxt[e])
#define esb(x,e,b) (int e=fst[x],b=vb[e];e;e=nxt[e],b=vb[e])
#define SZ 666666
int n,s[SZ],g[SZ],l[SZ],r[SZ],a[SZ];
int ss[SZ],sn=0;
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;++i)
		scanf("%d%d",s+i,g+i),
		l[i]=s[i]+i,r[i]=s[i]+g[i]+i;
	//l[i]-1
	for(int i=1;i<=n;++i)
	{
		while(sn&&r[ss[sn]]>=r[i]) --sn;
		ss[++sn]=i;
	}
	for(int i=1;i<=ss[1];++i) a[i]=r[ss[1]];
	for(int i=2;i<=sn;++i)
	{
		for(int j=ss[i-1]+1;j<=ss[i];++j)
			a[j]=min(a[j-1]+2,r[ss[i]]);
	}
	for(int i=1;i<=n;++i)
		if(a[i]<l[i])
		{
			puts("-1");
			return 0;
		}
	ll su=0;
	for(int i=1;i<=n;++i)
		a[i]-=i,su+=a[i]-s[i];
	printf("%lld\n",su);
	for(int i=1;i<=n;++i)
		printf("%d ",a[i]);
}
//h[i]=s[i]+x[i]+i