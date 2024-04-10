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
const int INF=1e9+10;
int n,m,d[555][555],w[555555],x[555555],y[555555],T;
LL ans;
void doit(){
	scanf("%d%d",&n,&m);
	FOR(i,1,n) FOR(j,1,n) d[i][j]=INF;
	FOR(i,1,n) d[i][i]=0;
	FOR(i,1,m){
		scanf("%d%d%d",&x[i],&y[i],&w[i]);
		d[x[i]][y[i]]=1;
		d[y[i]][x[i]]=1;
	}
	FOR(i,1,n)
		FOR(j,1,n)
			FOR(k,1,n)
				d[j][k]=min(d[j][k],d[j][i]+d[i][k]);
	ans=1e18;
	FOR(i,1,m){
		int t;
		t=d[1][x[i]]+d[n][y[i]];
		FOR(j,1,n){
			t=min(t,d[x[i]][j]+1+d[j][1]+d[j][n]);
			t=min(t,d[y[i]][j]+1+d[j][1]+d[j][n]);
		}
		ans=min(ans,1ll*(t+1)*w[i]);
		swap(x[i],y[i]);
		t=d[1][x[i]]+d[n][y[i]];
		FOR(j,1,n){
			t=min(t,d[x[i]][j]+1+d[j][1]+d[j][n]);
			t=min(t,d[y[i]][j]+1+d[j][1]+d[j][n]);
		}
		ans=min(ans,1ll*(t+1)*w[i]);
	}
	printf("%lld\n",ans);
}
int main(){
	scanf("%d",&T);
	while (T--) doit();
	return 0;
}