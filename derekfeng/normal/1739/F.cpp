#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
int n,dg[12],cnt,tr[4004];
bool ok[12][12];
string S;bool vis[12];
int nx[4004][12],vl[4004],tot=1;
int f[4096][4004];
pii g[4096][4004];
void dfs(int x){
	vis[x]=1;S+=(char)(x+'a');
	for(int i=0;i<12;i++)if(ok[x][i]&&!vis[i])dfs(i);
}
void add(string s,int c){
	int cur=1;
	for(auto c:s){
		int ch=c-'a';
		if(!nx[cur][ch])nx[cur][ch]=++tot;
		cur=nx[cur][ch];
	}
	vl[cur]+=c;
}
void built(){
	for(int i=0;i<12;i++)nx[0][i]=1;
	queue<int>q;q.push(1);tr[1]=0;
	while(!q.empty()){
		int u=q.front();q.pop();
		vl[u]+=vl[tr[u]];
		for(int i=0;i<12;i++){
			int v=nx[u][i],t=tr[u];
			if(!v){nx[u][i]=nx[t][i];continue;}
			tr[v]=nx[t][i];q.push(v);
		}
	}
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>n;
	while(n--){
		memset(ok,0,sizeof(ok));
		memset(dg,0,sizeof(dg));
		string s;int W;cin>>W>>s;
		for(int i=1;i<s.size();i++){
			int a=s[i-1]-'a',b=s[i]-'a';
			ok[a][b]=ok[b][a]=1;
		}
		for(int i=0;i<12;i++)for(int j=0;j<12;j++)
			dg[i]+=ok[i][j];
		bool ok=1;int pos=-1,cnt=0;
		for(int i=0;i<12;i++)if(dg[i]){
			if(dg[i]>2)ok=0;
			if(dg[i]==1)pos=i;
			cnt++;
		}
		if(!ok)continue;
		if(cnt>2&&pos<0)continue;
		if(cnt==2)pos=s[0]-'a';
		S="",memset(vis,0,sizeof(vis));
		dfs(pos),add(S,W);
		reverse(S.begin(),S.end()),add(S,W);
	}
	built();
	for(int i=0;i<4096;i++)for(int j=1;j<=tot;j++)f[i][j]=-1e9;
	f[0][1]=0;
	for(int i=0;i<4096;i++){
		for(int j=1;j<=tot;j++){
			for(int c=0;c<12;c++)if(!((i>>c)&1)){
				int ni=i|(1<<c),nj=nx[j][c];
				if(f[ni][nj]<f[i][j]+vl[nj]){
					f[ni][nj]=f[i][j]+vl[nj];
					g[ni][nj]={j,c};
				}
			}
		}
	}
	int pos,mx=-1e9,msk=4095;
	for(int i=1;i<=tot;i++)if(mx<f[msk][i])
		mx=f[msk][i],pos=i;
	string ans="";
	for(;;){
		if(!msk){
			cout<<ans;
			return 0;
		}
		auto[A,B]=g[msk][pos];
		ans+=(char)(B+'a'),msk^=(1<<B),pos=A;
	}
}