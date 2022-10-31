#include<bits/stdc++.h>
//#define int long long
const int N=1000500;
using namespace std;

#define _to e[i].to
#define fore(k) for(int i=hd[k];i;i=e[i].nx)
struct edge{
    int to,nx,w;
}e[N];int hd[N],S;
void add(int fr,int to,int w){
    e[++S]=(edge){to,hd[fr],w},hd[fr]=S;
}

int n,m,v[N],col[N],cnt,cw,fl;

void dfs(int k,int c){
	if(v[k]&&col[k]!=c)fl=-1;
	if(v[k])return;
	v[k]=1,col[k]=c;if(c)cw++;cnt++;
	fore(k)dfs(_to,c^e[i].w); 
}

void clear(){
	for(int i=1;i<=n;i++)
		hd[i]=v[i]=col[i]=0;
	S=0;
}

void solve(){
	cin>>n>>m;
	fl=0;
	for(int i=1,x,y;i<=m;i++){
		string s;
		cin>>x>>y>>s;
		if(s[0]=='i')add(x,y,1),add(y,x,1);
		else add(x,y,0),add(y,x,0);
	}
	int ans=0;
	for(int i=1;i<=n;i++){
		cnt=0,cw=0;
		if(!v[i])
			dfs(i,0);
		ans+=max(cw,cnt-cw);
	}
	if(fl==-1)
		cout<<-1<<endl;
	else  
		cout<<ans<<endl;
	clear();
}

int main(){
	ios::sync_with_stdio(false);
	int t;cin>>t;while(t--)solve();
}