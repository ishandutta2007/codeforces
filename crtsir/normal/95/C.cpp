#include<bits/stdc++.h>
using namespace std;
struct node{
	int y;
	long long l;
	node(int yy=0,long long ll=0):y(yy),l(ll){};
};
bool canu[1003][1003];
int que[1003],qs,qe,s,e,n,m,inq[1003],a,b,c,len[1003],ne[1003];
vector<node>ed[1003];
long long dist[1003];
bool vis[1003];
inline void push(int a){
	if(inq[a])return ;
	inq[a]=1;
	que[qe++]=a;
	if(qe==1003)qe=0;
}
inline int pop(){
	int a=que[qs++];
	if(qs==1003)qs=0;
	inq[a]=0;
	return a;
}
inline void sp(int st){
	qs=0;qe=0;
	memset(inq,0,sizeof(inq));
	for(int i=0;i<n;i++)dist[i]=901398907091;
	dist[st]=0;
	push(st);
	while(qs!=qe){
		int tp=pop();
		for(int i=0;i<ed[tp].size();i++)
		{
			int y=ed[tp][i].y;
			long long l=ed[tp][i].l;
			if(dist[y]>l+dist[tp])
				dist[y]=l+dist[tp],
				push(y);
		}
	}
}
int main(){
	cin>>n>>m>>s>>e;
	s--;e--;
	for(int i=0;i<m;i++){
		cin>>a>>b>>c;
		a--;b--;
		ed[a].push_back(node(b,c));
		ed[b].push_back(node(a,c));
	}
	for(int i=0;i<n;i++){
		cin>>len[i]>>ne[i];
		sp(i);
		for(int j=0;j<n;j++)if(dist[j]<=len[i])
			canu[i][j]=1;
			//cout<<i<<' '<<j<<' '<<dist[j]<<endl;
	}
	for(int i=0;i<n;i++)dist[i]=90139890778085091;
	dist[s]=0;
	for(int i=0;i<n;i++){
		long long now=90139890709176592;
		int u=-1;
		for(int j=0;j<n;j++)
			if(!vis[j]&&dist[j]<now)
			{
				now=dist[j];
				u=j;
			}
		if(u==-1){
			//cout<<"Dead";
			break;
		}
		vis[u]=1;
		for(int j=0;j<n;j++)
			if(canu[u][j])
				dist[j]=min(dist[j],dist[u]+ne[u]);
	}
	if(vis[e])
		cout<<dist[e];
	else
		cout<<-1;
}