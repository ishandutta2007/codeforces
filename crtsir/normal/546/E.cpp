#include<bits/stdc++.h>
using namespace std;
int n,m,a[103],b[103],dis[203],temp,ans[103][103];
const int Maxn=100,Group=2;
vector<int>FEP[Maxn*Group+5];// 
vector<pair<int,int> >FE;// 
void FAD(int FFrom,int Fto,int Fweight){
	FEP[FFrom].push_back(FE.size());
	FE.push_back(make_pair(Fto,Fweight));
}// 
int FlowDis[Maxn*Group+5];//bfs 
queue<pair<int,int> >FlowQueue;//bfs 
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
int Flow_DFS(int FlowNowx,int minn,int Flow_Endat,int Flow_Depth){
	if(FlowNowx==Flow_Endat)return minn;
	if(FlowDis[Flow_Endat]==Flow_Depth)return 0;
	int Flow_DFS_Return=0;
	for(int i=0;i<FEP[FlowNowx].size();i++)
		if(FlowDis[FE[FEP[FlowNowx][i]].first]==FlowDis[FlowNowx]+1&&FE[FEP[FlowNowx][i]].second){
			int Flow_DFS_Answer=Flow_DFS(FE[FEP[FlowNowx][i]].first,min(minn-Flow_DFS_Return,FE[FEP[FlowNowx][i]].second),Flow_Endat,Flow_Depth+1);
			FE[FEP[FlowNowx][i]].second-=Flow_DFS_Answer;
			FE[FEP[FlowNowx][i]^1].second+=Flow_DFS_Answer;
			Flow_DFS_Return+=Flow_DFS_Answer;
		}
	return Flow_DFS_Return;
}// 
int Flow_Dinic(int Flow_Startfrom,int Flow_Endat){
	int Flow_Dinics_Return=0;
	while(Flow_BFS(Flow_Startfrom,Flow_Endat))Flow_Dinics_Return+=Flow_DFS(Flow_Startfrom,1000000007,Flow_Endat,1);
	return Flow_Dinics_Return;
}// 
bool check(){
	int sum=0;
	for(int i=1;i<=n;i++)sum+=a[i];
	int mn=Flow_Dinic(0,202);
	return (mn==sum);
}
int main(){
	cin>>n>>m;
	int cnt1=0,cnt2=0;
	for(int i=1;i<=n;i++)
		cin>>a[i],
		cnt1+=a[i],
		FAD(0,i,a[i]),
		FAD(i,0,0);
	for(int i=1;i<=n;i++)cin>>b[i],cnt2+=b[i],FAD(i+100,202,b[i]),FAD(202,i+100,0),FAD(i,i+100,1000000007),FAD(i+100,i,0);
	for(int i=0;i<m;i++){
		int x,y;
		cin>>x>>y;
		FAD(x,y+100,1000000007);
		FAD(y+Maxn,x,0);
		FAD(y,x+100,1000000007);
		FAD(x+100,y,0);
	}
	if(cnt1!=cnt2){
		cout<<"NO";
		return 0;
	}
	if(!check()){
		cout<<"NO\n";
	}
	else{
		cout<<"YES\n";
		for(int i=1;i<=n;i++)
			for(int j=0;j<FEP[i].size();j++)
				if(FE[FEP[i][j]].first>100)
					ans[i][FE[FEP[i][j]].first-100]=FE[FEP[i][j]^1].second; 
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=n;j++)
				cout<<ans[i][j]<<' ';
			cout<<endl;
		} 
	} 
}