#include<bits/stdc++.h>
//#define int long long
const int N=1005,inf=N;
using namespace std;

int a[N][N],n,m,ans,S[N][N],fl[N][N],sf[N][N],p;
char st[N];

#define _to e[i].to
#define fore(k) for(int i=hd[k];i;i=e[i].nx)
struct edge{
    int to,nx,w;
}e[N*N*10];int hd[N],sz=1,s,t;

void add(int fr,int to,int w){
    e[++sz]=(edge){to,hd[fr],w},hd[fr]=sz;
    e[++sz]=(edge){fr,hd[to],0},hd[to]=sz;
}
int d[N],hy[N]; 
bool bfs(){
    memcpy(hy,hd,sizeof(hd));
    memset(d,0,sizeof(d));
    queue<int> q;
    q.push(t),d[t]=inf;
    while(q.size()){
        int nw=q.front();q.pop();
        fore(nw)if(!d[_to]&&e[i^1].w){
            q.push(_to),d[_to]=d[nw]-1;
            if(_to==s)return 1;
        }
    }
    return 0;
}

int dfs(int k,int f){
    if(k==t)return f;
    int rf=f,s=0;
    for(int&i=hy[k];i;i=e[i].nx)
        if(d[_to]==d[k]+1&&e[i].w){
            int nw=dfs(_to,min(e[i].w,rf));
            if(!nw)d[_to]=0;
            s+=nw,rf-=nw,e[i].w-=nw,e[i^1].w+=nw;
        }
    return s;
}

void dinic(){
    while(bfs())
        ans-=dfs(s,inf);
}

int main(){
	ios::sync_with_stdio(false);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>st+1;
		for(int j=1;j<=m;j++)
			if(st[j]=='B')
				a[i][j]=1;
	}
	for(int i=n;i>=1;i--)
		for(int j=m;j>=1;j--){
			a[i][j]=a[i][j]^((S[i+1][j]^S[i+1][j+1]^S[i][j+1])&1);
			if(a[i][j])S[i][j]=1;
			S[i][j]=S[i][j]^S[i+1][j]^S[i+1][j+1]^S[i][j+1]; 
		}
	s=0,t=n+m+1;
	for(int i=1;i<=n;i++)add(s,i,1);
	for(int i=1;i<=m;i++)add(i+n,t,1);
	for(int i=1;i<n;i++)
		for(int j=1;j<m;j++)
			if(a[i][j]&a[i][m]&a[n][j])
				add(i,j+n,1);
	
	dinic();
	a[n][m]^=(-ans)&1;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			ans+=a[i][j];
	end:cout<<ans;
}