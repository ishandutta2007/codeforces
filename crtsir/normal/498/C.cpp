#include<bits/stdc++.h>
using namespace std;
const int Maxn=114514,Group=1;
vector<int>FEP[Maxn*Group+5];
vector<pair<int,int> >FE;
void FAE(int FFrom,int Fto,int Fweight){
	FEP[FFrom].push_back(FE.size());
	FE.push_back(make_pair(Fto,Fweight));
	FEP[Fto].push_back(FE.size());
	FE.push_back(make_pair(FFrom,0));
}
int FlowDis[Maxn*Group+5];
queue<pair<int,int> >FlowQueue;
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
} 
int Flow_DFS(int FlowNowx,int minn,int Flow_Endat,int Flow_Depth){
	if(FlowNowx==Flow_Endat)return minn;
	if(FlowDis[Flow_Endat]==Flow_Depth)return 0;
	int Flow_DFS_Return=0;
	for(int i=0;i<FEP[FlowNowx].size();i++)
		if(FlowDis[FE[FEP[FlowNowx][i]].first]==FlowDis[FlowNowx]+1&&FE[FEP[FlowNowx][i]].second){
			int Flow_DFS_Answer=Flow_DFS(FE[FEP[FlowNowx][i]].first,min(minn-Flow_DFS_Return,FE[FEP[FlowNowx][i]].second),Flow_Endat,Flow_Depth+1);
			if(Flow_DFS_Answer){
				FE[FEP[FlowNowx][i]].second-=Flow_DFS_Answer; 
				FE[FEP[FlowNowx][i]^1].second+=Flow_DFS_Answer;
				return Flow_DFS_Answer;
			}
		}
	return Flow_DFS_Return;
} 
int Flow_Dinic(int Flow_Startfrom,int Flow_Endat){
	int Flow_Dinics_Return=0;
	while(Flow_BFS(Flow_Startfrom,Flow_Endat))Flow_Dinics_Return+=Flow_DFS(Flow_Startfrom,1000000007,Flow_Endat,1);
	return Flow_Dinics_Return;
}
void Flow_init(){
	FE.clear();
	for(int i=0;i<Maxn*Group+5;i++)FEP[i].clear();
}
int a[103],fr[103],to[103],cnttt=1,n,m;
vector<pair<int,int> >v[103];
void op(int x,int i){
	for(int j=2;j<=sqrt(x);j++)
		if(x%j==0){
			int cnt=0;
			while(x%j==0){
				x/=j;
				cnt++;
			}
			v[i].push_back(make_pair(j,cnttt));
			if(i%2==0)
				FAE(0,cnttt,cnt);
			else
				FAE(cnttt,114514,cnt);
			cnttt++;
		}
	if(x!=1){
		v[i].push_back(make_pair(x,cnttt));
		if(i%2==0)
			FAE(0,cnttt,1);
		else
			FAE(cnttt,114514,1);cnttt++;
	}
}
void op2(int x,int y){
	for(int i=0;i<to[x]-fr[x];i++)
		for(int j=0;j<to[y]-fr[y];j++)
			if(v[x][i].first==v[y][j].first)
				FAE(v[x][i].second,v[y][j].second,114514);
}
int main(){cin>>n>>m;
	for(int i=0;i<n;i++){ 
		cin>>a[i];
		fr[i]=cnttt;
		op(a[i],i); 
		to[i]=cnttt;
	}
	for(int i=0;i<m;i++){
		int x,y;
		cin>>x>>y;
		x--;y--;
		if(x%2)swap(x,y);
		op2(x,y);
	}
	cout<<Flow_Dinic(0,114514);
}