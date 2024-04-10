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
int n,m; char s[233],r[535];
bool rs[2333];
int main()
{
	scanf("%d%s%d",&n,s,&m);
	for(int i=0;i<n;++i)
		rs[s[i]]=1;
	int ff=-1;
	for(int i=1;i<=m;++i)
	{
		scanf("%s",r);
		bool val=1;
		for(int j=0;j<n;++j)
		{
			if(s[j]!='*'&&s[j]!=r[j]) val=0;
			else if(s[j]=='*'&&rs[r[j]]) val=0;
		}
		if(!val) continue;
		int oo=0;
		for(int j=0;j<n;++j)
			if(!rs[r[j]]) oo|=1<<(r[j]-'a');
		ff&=oo;
	}
	printf("%d\n",__builtin_popcount(ff));
}