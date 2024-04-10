#include<bits/stdc++.h>
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
const int dx[]={-1,0,0,1};
const int dy[]={0,-1,1,0};
char s[2010][2010];
int n,m,r,c,he,ta,x,y,ans,d[2010][2010];
pa q[10000010];
void bfs(){
	he=5000000;
	ta=5000001;
	q[ta]=mp(r,c);
	memset(d,-1,sizeof(d));
	d[r][c]=0;
	while (he!=ta){
		pa x=q[++he];
		FOR(D,0,3){
			pa y=mp(x.fi+dx[D],x.se+dy[D]);
			if (y.fi<1 || y.fi>n || y.se<1 || y.se>m) continue;
			if (d[y.fi][y.se]!=-1 || s[y.fi][y.se]=='*') continue;
			d[y.fi][y.se]=d[x.fi][x.se]+(x.se!=y.se);
			if (x.se!=y.se) q[++ta]=y;
			else q[he--]=y;
		}
	}
}
int main(){
	scanf("%d%d",&n,&m);
	cin>>r>>c>>x>>y;
	FOR(i,1,n){
		scanf("%s",s[i]+1);
	}
	bfs();
	FOR(i,1,n)
		FOR(j,1,m){
			int t=d[i][j];
			if (t==-1) continue;
			int R=(t+j-c)/2,L=t-R;
			if (R<=y && L<=x) ++ans;
		}
	cout<<ans<<endl;
	return 0;
}