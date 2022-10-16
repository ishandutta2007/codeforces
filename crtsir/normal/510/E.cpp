#include<bits/stdc++.h>
using namespace std;
const int Maxn=200,Group=1;
int n,a[203];
vector<int>FEP[Maxn*Group+5];// 
vector<pair<int,int> >FE;// 
void FAE(int FFrom,int Fto,int Fweight){
	FEP[FFrom].push_back(FE.size());
	FE.push_back(make_pair(Fto,Fweight));
}// 
int FlowDis[Maxn*Group+5];//bfs 
queue<pair<int,int> >FlowQueue;//bfs 
vector<vector<int> >ans;
int Flow_BFS(int Flow_Startfrom,int Flow_Endat){
	memset(FlowDis,0,sizeof(FlowDis));
	FlowDis[Flow_Startfrom]=1;
	FlowQueue.push(make_pair(Flow_Startfrom,1));
	while(!FlowQueue.empty()){
		int FlowNowx=FlowQueue.front().first,FlowNowlen=FlowQueue.front().second;
		FlowQueue.pop();
		for(int i=0;i<FEP[FlowNowx].size();i++)
			if(FlowDis[FE[FEP[FlowNowx][i]].first]==0&&FE[FEP[FlowNowx][i]].second)
				FlowQueue.push(make_pair(FE[FEP[FlowNowx][i]].first,FlowNowlen+1)),
				FlowDis[FE[FEP[FlowNowx][i]].first]=FlowNowlen+1;
	}
	if(FlowDis[Flow_Endat])return FlowDis[Flow_Endat];
	return 0;
}// 
bool isprime(int x){
	if(x==0||x==1)return 0;
	for(int i=2;i<=sqrt(x);i++)
		if(x%i==0)
			return 0;
	return 1;
}
bool isgood=1;
vector<int>pathes,answ[203];
int Flow_DFS(int FlowNowx,int minn,int Flow_Endat,int Flow_Depth){
	if(FlowNowx==Flow_Endat){
		isgood=1;
		return minn;
	}
	if(FlowDis[Flow_Endat]==Flow_Depth)return 0;
	int Flow_DFS_Return=0;
	for(int i=0;i<FEP[FlowNowx].size();i++)
		if(FlowDis[FE[FEP[FlowNowx][i]].first]==FlowDis[FlowNowx]+1&&FE[FEP[FlowNowx][i]].second!=0){
			int Flow_DFS_Answer=Flow_DFS(FE[FEP[FlowNowx][i]].first,min(minn-Flow_DFS_Return,FE[FEP[FlowNowx][i]].second),Flow_Endat,Flow_Depth+1);
			FE[FEP[FlowNowx][i]].second-=Flow_DFS_Answer; 
			FE[FEP[FlowNowx][i]^1].second+=Flow_DFS_Answer;// 
			if(Flow_DFS_Answer)
				return Flow_DFS_Answer;
		}
	FlowDis[FlowNowx]=0; 
	return Flow_DFS_Return;
}// 
int Flow_Dinic(int Flow_Startfrom,int Flow_Endat){
	int Flow_Dinics_Return=0;
	while(isgood&&Flow_BFS(Flow_Startfrom,Flow_Endat))isgood=0,Flow_Dinics_Return+=Flow_DFS(Flow_Startfrom,1000000007,Flow_Endat,1);
	for(int i=1;i<FE.size();i+=2)
		if(FE[i].second&&FE[i].first!=0&&FE[i-1].first!=204)
			answ[FE[i-1].first].push_back(FE[i].first),
			answ[FE[i].first].push_back(FE[i-1].first);
	return Flow_Dinics_Return;
}// 
int cntt;
vector<int>tmp;
bool vis[203];
void findpath(int x,int last){
	if(vis[x])return;
	vis[x]=1;
	tmp.push_back(x); 
	for(int i=0;i<answ[x].size();i++)
		if(answ[x][i]!=last&&isprime(a[x]+a[answ[x][i]]))
			findpath(answ[x][i],x);
}
void findans(int x){
	tmp.clear();
	findpath(x,-1);
	ans.push_back(tmp); 
}
vector<int>e,o;
int main(){
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<=n;i++)
		if(a[i]%2==0)
			e.push_back(i);
		else
			o.push_back(i);
	for(int i=0;i<e.size();i++)FAE(0,e[i],2),FAE(e[i],0,0);
	for(int i=0;i<e.size();i++)
		for(int j=0;j<o.size();j++)
			if(isprime(a[e[i]]+a[o[j]]))
				FAE(e[i],o[j],1),
				FAE(o[j],e[i],0);
	for(int i=0;i<o.size();i++)FAE(o[i],204,2),FAE(204,o[i],0);
	if(Flow_Dinic(0,204)!=n)
		cout<<"Impossible";
	else
	{
		for(int i=1;i<=n;i++)if(!vis[i]){findans(i);}
		cout<<ans.size()<<endl;
		for(int i=0;i<ans.size();i++){
			cout<<ans[i].size();
			for(int j=0;j<ans[i].size();j++)cout<<' '<<ans[i][j];
			cout<<endl;
		}
	}
}