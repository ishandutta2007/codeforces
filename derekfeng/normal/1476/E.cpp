#include<bits/stdc++.h>
using namespace std;
map<string,int>id;
vector<int>g[100004];
string s[100004],S;
void putno(){
	puts("NO");
	exit(0);
}
int n,m,cmp[100004],cnt,low[100004],vis[100004],t;
stack<int>st;
bool instack[100004];
void tarjan(int x){
	vis[x]=low[x]=++cnt;
	st.push(x),instack[x]=1; 
	for (int i=0;i<g[x].size();i++){
		if (!vis[g[x][i]]) tarjan(g[x][i]);
		if (instack[g[x][i]]) low[x]=min(low[x],low[g[x][i]]);
	}
	if (vis[x]==low[x]){
		t++;
		while (st.top()!=x){
			cmp[st.top()]=t,instack[st.top()]=0,st.pop();
		}
		st.pop(),cmp[x]=t,instack[x]=0;
	}
}
int ord[100004];
bool cmp1(int A,int B){
	return cmp[A]>cmp[B];
}
int main(){
	int n,m,K,mt;cin>>n>>m>>K;
	for(int i=1;i<=n;i++)cin>>s[i],id[s[i]]=i,ord[i]=i;
	while(m--){
		cin>>S>>mt;
		for(int i=0;i<K;i++)
			if(s[mt][i]!='_'&&S[i]!=s[mt][i])putno();
		for(int i=0;i<(1<<K);i++){
			string SS=S;
			for(int j=0;j<K;j++)if((1<<j)&i)SS[j]='_';
			if(id[SS]>0){
				int tmp=id[SS];
				if(tmp==mt)continue;
				g[mt].push_back(tmp); 
			}
		}
	}
	for(int i=1;i<=n;i++)if(!vis[i])tarjan(i);
	for(int i=1;i<=n;i++)for(auto y:g[i])if(cmp[y]==cmp[i])putno(); 
	sort(ord+1,ord+1+n,cmp1);
	puts("YES");
	for(int i=1;i<=n;i++)cout<<ord[i]<<" ";
}