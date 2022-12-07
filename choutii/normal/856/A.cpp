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
#define VIZ {printf("digraph G{\n"); for(int i=1;i<=n;i++) for es(i,e) printf("%d->%d;\n",i,vb[e]); puts("}");}
#define VIZ2 {printf("graph G{\n"); for(int i=1;i<=n;i++) for es(i,e) if(vb[e]>=i)printf("%d--%d;\n",i,vb[e]); puts("}");}
#define SZ 666666
using namespace std;
int t,n,a[SZ];
bool s[1234567];
void sol()
{
	memset(s,0,sizeof s);
	scanf("%d",&n);
	for(int i=1;i<=n;++i)
		scanf("%d",a+i);
	sort(a+1,a+1+n);
	for(int i=1;i<=n;++i)
		for(int j=i+1;j<=n;++j)
			s[a[j]-a[i]]=1;
	for(int i=1;i<=100;++i)
	{
		int g=(rand()*32768+rand())
		%(1000000/n)+1;
		for(int j=1;j<=n;++j)
			if(s[g*j]) goto gg;
		puts("YES");
		for(int j=1;j<=n;++j)
			printf("%d ",g*j);
		puts("");
		return;
		gg:;
	}
	puts("NO");
}
int main()
{
	scanf("%d",&t);
	while(t--) sol();
}