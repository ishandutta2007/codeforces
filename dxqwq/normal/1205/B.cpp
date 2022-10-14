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
#include <assert.h>
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
int n; ll a[SZ];
int dis[555][555],aa[555][555];
int main()
{
	memset(dis,127/4,sizeof dis);
	scanf("%d",&n);
	for(int i=1;i<=n;++i)
	{
		scanf("%lld",a+i);
		if(!a[i])
		{
			--n; --i;
			continue;
		}
	}
	if(n>3*64)
	{
		puts("3");
		return 0;
	}
	for(int i=1;i<=n;++i)
		for(int j=i+1;j<=n;++j)
			if((a[i]&a[j])) dis[i][j]=dis[j][i]=1;
	memcpy(aa,dis,sizeof aa);
	int ans=2e9;
	for(int k=1;k<=n;++k)
	{
		for(int i=1;i<k;++i)
			for(int j=i+1;j<k;++j)
				ans=min(ans,aa[i][k]+aa[k][j]+dis[i][j]);
		for(int i=1;i<=n;++i)
			for(int j=1;j<=n;++j)
				dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
	}
	if(ans>1e3) ans=-1;
	printf("%d\n",ans);
}