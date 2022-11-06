#include<bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define SZ(x) ((int)x.size())
#define FOR(i,a,b) for (int i=a;i<=b;++i)
#define FORD(i,a,b) for (int i=a;i>=b;--i)
using namespace std;
typedef long long LL;
typedef pair<int,int> pa;
typedef vector<int> vec;
void getint(int &v){
    char ch,fu=0;
    for(ch='*'; (ch<'0'||ch>'9')&&ch!='-'; ch=getchar());
    if(ch=='-') fu=1, ch=getchar();
    for(v=0; ch>='0'&&ch<='9'; ch=getchar()) v=v*10+ch-'0';
    if(fu) v=-v;
}
vec V[300010],w[300010];
int ans,n,k,fa[500100],x,tp[500100],v[500010],f[500010][2],cst[500100];
char s[500010];
void fuzhi(int x,int TP){
	if (v[fa[x]]!=-1) return;
	ans-=cst[fa[x]];
	v[fa[x]]=tp[x]^TP;
	cst[fa[x]]=f[fa[x]][v[fa[x]]^1];
	ans+=cst[fa[x]];
}
void lnk(int x,int y,int TP){
	int X=fa[x],Y=fa[y];
	if (X==Y) return;
	if (SZ(V[X])<SZ(V[Y])) swap(X,Y),swap(x,y);
	int t=tp[y];
	if (v[Y]!=-1){
		v[X]=v[Y]^t^TP^tp[x];
	}
	FOR(i,0,SZ(V[Y])-1){
		int h=V[Y][i];
		fa[h]=X;
		tp[h]=tp[h]^t^TP^tp[x];
		f[X][tp[h]]++;
		V[X].pb(h);
	}
	ans-=cst[Y];
	V[Y].clear();
	ans-=cst[X];
	if (v[X]==-1) cst[X]=min(f[X][0],f[X][1]);
	else cst[X]=f[X][v[X]^1];
	ans+=cst[X];
}
int main(){
	cin>>n>>k;
	scanf("%s",s+1);
	FOR(i,1,k){
		int t;
		getint(t);
		while (t--){getint(x);w[x].pb(i);}
	}
	FOR(i,1,k) fa[i]=i,tp[i]=0,f[i][0]=1,f[i][1]=0,v[i]=-1,cst[i]=0,V[i].pb(i);
	FOR(i,1,n){
		if (SZ(w[i])==0){printf("%d\n",ans);continue;}
		if (SZ(w[i])==1){
			int h=w[i][0];
			if (s[i]=='1') fuzhi(h,0);
			else fuzhi(h,1);
			printf("%d\n",ans);
			continue;
		}
		int x=w[i][0],y=w[i][1];
		if (s[i]=='1') lnk(x,y,0);
		else lnk(x,y,1);
		printf("%d\n",ans);
	}
	return 0;
}