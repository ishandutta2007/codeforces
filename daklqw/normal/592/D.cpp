#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cstring>
#define MAXN 130000
#define ROOT 0x7ffffff
using namespace std;
int n,m,t1,t2,t,fa[MAXN],pl[MAXN],val[MAXN],at=1,poc=0;
bool isp[MAXN],vis[MAXN];
vector<int> grap[MAXN];
void build(){
	queue<int>q;
	memset(vis,0,sizeof vis);
	q.push(t1);
	fa[t1]=ROOT;
	while(!q.empty()){
		t=q.front();
		vis[t]=true;
		for(int i=1;i<grap[t].size();++i){
			if(!vis[grap[t][i]]){
				q.push(grap[t][i]);
				fa[grap[t][i]]=t;
			}
		}
		q.pop();
	}
}
void delp(){
	for(int i=1;i<at;i++){
		t=fa[pl[i]];
		while(t!=ROOT&&!isp[t]){
			isp[t]=true;
			t=fa[t];
		}
	}
}
int getl(){
	memset(vis,0,sizeof vis);
	memset(val,0,sizeof val);
	queue<int>q;
	q.push(t1);
	val[t1]=1;
	while(!q.empty()){
		t=q.front();
		vis[t]=true;
		for(int i=1;i<grap[t].size();++i)
			if(!vis[grap[t][i]]&&isp[grap[t][i]]){
				q.push(grap[t][i]);
				val[grap[t][i]]=val[t]+1;
			}
		q.pop();
	}
	int mAx=-0x7fffffff,mIx=0x7fffffff;
	for(int i=n;i>=1;--i)
		if(val[i]>mAx)mAx=val[i],mIx=i;
		else if(val[i]==mAx)mIx=min(mIx,i);
	memset(vis,0,sizeof vis);
	memset(val,0,sizeof val);
	q.push(mIx);
	val[mIx]=1;
	while(!q.empty()){
		t=q.front();
		vis[t]=true;
		for(int i=1;i<grap[t].size();++i)
			if(!vis[grap[t][i]]&&isp[grap[t][i]]){
				q.push(grap[t][i]);
				val[grap[t][i]]=val[t]+1;
			}
		q.pop();
	}
	int mAx2=-0x7fffffff,mIx2=0x7fffffff;
	for(int i=n;i>=1;--i)
		if(val[i]>mAx2)mAx2=val[i],mIx2=i;
		else if(val[i]==mAx2)mIx2=min(mIx2,i);
	cout<<min(mIx,mIx2)<<endl;
	return mAx2-1;
}
int main(){
	cin>>n>>m;
	for(int i=1;i<=n;i++)grap[i].push_back(0);
	for(int i=1;i<=n-1;++i){
		cin>>t1>>t2;
		grap[t1].push_back(t2);
		grap[t2].push_back(t1);
	}
	for(int i=1;i<=m;++i){
		cin>>t1;pl[at++]=t1;
		isp[t1]=true;
	}
	build();
	delp();
	for(int i=1;i<=n;i++)poc+=isp[i];
	cout<<(poc-1)*2-getl()<<endl;
	return 0;
}