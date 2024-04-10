#include<bits/stdc++.h>
using namespace std; 
const int Maxn=10003,Group=1;
vector<int>FEP[Maxn*Group+5];// 
vector<pair<int,int> >FE;// 
void FAE(int FFrom,int Fto,int Fweight){
	FEP[FFrom].push_back(FE.size());
	FE.push_back(make_pair(Fto,Fweight));
}// 
int n,b,q;
vector<pair<int,int> >v;
int FlowDis[Maxn*Group+5];//bfs 
pair<int,int>FlowQueue[10007];//bfs 
int Flow_BFS(int Flow_Startfrom,int Flow_Endat){
	memset(FlowDis,0,sizeof(FlowDis));
	FlowDis[Flow_Startfrom]=1;
	int s=0,t=0;
	FlowQueue[t++]=make_pair(Flow_Startfrom,1);
	while(s!=t){
		int FlowNowx=FlowQueue[s].first,FlowNowlen=FlowQueue[s++].second;
		for(int i=0;i<FEP[FlowNowx].size();i++)
			if(FlowDis[FE[FEP[FlowNowx][i]].first]==0&&FE[FEP[FlowNowx][i]].second)
				FlowQueue[t++]=make_pair(FE[FEP[FlowNowx][i]].first,FlowNowlen+1),
				FlowDis[FE[FEP[FlowNowx][i]].first]=FlowNowlen+1;
	}
	if(FlowDis[Flow_Endat])return FlowDis[Flow_Endat];
	return 0;
}// 
int cnt[10008];
inline int Flow_DFS(int FlowNowx,int minn,int Flow_Endat,int Flow_Depth){
	cnt[FlowNowx]++; 
	if(FlowNowx==Flow_Endat)return minn;
	if(FlowDis[Flow_Endat]==Flow_Depth)return 0;
	int Flow_DFS_Return=0;
	for(int i=0;i<FEP[FlowNowx].size();i++)
		if(FlowDis[FE[FEP[FlowNowx][i]].first]==FlowDis[FlowNowx]+1&&FE[FEP[FlowNowx][i]].second){
			int Flow_DFS_Answer=Flow_DFS(FE[FEP[FlowNowx][i]].first,min(minn-Flow_DFS_Return,FE[FEP[FlowNowx][i]].second),Flow_Endat,Flow_Depth+1);
			FE[FEP[FlowNowx][i]].second-=Flow_DFS_Answer; 
			FE[FEP[FlowNowx][i]^1].second+=Flow_DFS_Answer; 
			Flow_DFS_Return+=Flow_DFS_Answer;
			if(Flow_DFS_Return==minn)break;
		}
	return Flow_DFS_Return;
}// 
int Flow_Dinic(int Flow_Startfrom,int Flow_Endat){
	int Flow_Dinics_Return=0;
	while(Flow_BFS(Flow_Startfrom,Flow_Endat)&&Flow_Dinics_Return!=n)Flow_Dinics_Return+=Flow_DFS(Flow_Startfrom,1000000007,Flow_Endat,1);
	return Flow_Dinics_Return;
}// 
int did(int x,int y,int z){
	int cntx=(x+5-z)/5;
	int cnty=(y+5-z)/5;
	return cnty-cntx; 
}
int main(){
	cin>>n>>b>>q;
	v.push_back(make_pair(0,0)); 
	for(int i=0;i<q;i++)
	{
		int x,y;
		cin>>x>>y;
		v.push_back(make_pair(x,y));
	}
	v.push_back(make_pair(b,n));
	sort(v.begin(),v.end());//s=0,modo=10002,10003,10004,10005,10006,t=10007
	for(int i=1;i<v.size();i++){
		int x,y;
		x=v[i].first-v[i-1].first;
		y=v[i].second-v[i-1].second;
		if(x<y||y<0){
			cout<<"unfair";
			return 0; 
		}
		FAE(0,i,y);
		FAE(i,0,0);
		for(int j=0;j<5;j++)
			FAE(i,10002+j,did(v[i-1].first,v[i].first,j)),
			FAE(10002+j,i,0);
	}
	for(int i=10002;i<10007;i++)FAE(i,10007,n/5),FAE(10007,i,0);
	if(Flow_Dinic(0,10007)==n)
		cout<<"fair";
	else
		cout<<"unfair";
}