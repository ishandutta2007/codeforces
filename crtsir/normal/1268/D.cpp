#include<bits/stdc++.h>
using namespace std;
int n,m;
vector<int>v[2003],rv[2003],V;
bool used[2003];
void dfs(int x){
	used[x]=1;
	for(int i=0;i<v[x].size();i++)
		if(!used[v[x][i]])
			dfs(v[x][i]);
	V.push_back(x);
}
int col[2003],cnt[2003];
void rdfs(int x,int y){
	col[x]=y;used[x]=1;cnt[y]++; 
	for(int i=0;i<rv[x].size();i++)
		if(!used[rv[x][i]])
			rdfs(rv[x][i],y);
}
void init(){
	memset(used,0,sizeof(used));
	for(int i=0;i<n;i++)
		if(!used[i])
			dfs(i);
	memset(used,0,sizeof(used));
	while(V.size()){
		if(!used[V.back()])
			rdfs(V.back(),m++); 
		V.pop_back();
	}
}
const int mod=131;
unsigned __int128 st[2003][16],vis[16],val[mod];
bool calc(){
	memset(vis,0,sizeof(vis));
	vis[0]=1;
	queue<int>q;
	q.push(0);
	while(q.size()){
		int nw=q.front();q.pop();
		for(int j=0;j<16;j++){
			unsigned __int128 newv=(st[nw][j]&(~vis[j]));
			vis[j]|=st[nw][j];
			while(newv){
				if(val[(newv&-newv)%mod]+(j<<7)<n)
					q.push(val[(newv&-newv)%mod]+(j<<7));
				else
					break;
				newv^=(newv&-newv);
			}
		}
	}
	for(int i=0;i<n;i++)
		if(!(vis[i>>7]&((unsigned __int128)(1)<<(i&127))))
			return 0;
	return 1;
}
int main(){
	int pw=1;
	for(int i=0;i<128;i++){val[pw]=i;pw=pw*2%mod;}
	cin>>n;
	for(int i=0;i<n;i++){
		string s;
		cin>>s;
		for(int j=0;j<n;j++)
			if(s[j]=='1')
				st[i][j>>7]|=((unsigned __int128)(1)<<(j&127));
		for(int j=0;j<n;j++)
			if(s[j]=='0')
				v[i].push_back(j);
			else
				rv[i].push_back(j);
	}init();
	if(m==1){cout<<0<<' '<<1;return 0;}
	int ans1=2,ans2=0;
	for(int i=0;i<n;i++)
		if(col[i]&&col[i]<m-1)
			ans2++;
		else{
			for(int j=0;j<n;j++){
				st[i][j>>7]^=((unsigned __int128)(1)<<(j&127));
				st[j][i>>7]^=((unsigned __int128)(1)<<(i&127));
			}
			bool ok=calc();
			for(int j=0;j<n;j++)
				for(int k=0;k<16;k++)
					st[j][k]=(~st[j][k]);
			ok&=calc();ans2+=ok;
			for(int j=0;j<n;j++){
				st[i][j>>7]^=((unsigned __int128)(1)<<(j&127));
				st[j][i>>7]^=((unsigned __int128)(1)<<(i&127));
			}
		}
	if(ans2){cout<<1<<' '<<ans2;return 0;}
	if(n==4)
		cout<<-1;
	else
		cout<<2<<' '<<18; 
	return 0;
}