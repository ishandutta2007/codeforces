#include <iostream>
#include <fstream>
#include <queue>
using namespace std;
bool used[101][100001];
int len[101],n;
int dx[4]={-1,0,1,0},dy[4]={0,-1,0,1};
struct point{
	int x,y;
	int step;
};
int bfs(int rx,int ry,int cx,int cy){
	queue<int>qx,qy,qstep;
	qx.push(rx);
	qy.push(ry);
	qstep.push(0);
	used[rx][ry]=true;
	while(qstep.size()){
		int px=qx.front(),py=qy.front();
		int pst=qstep.front();
		qx.pop();qy.pop();
		qstep.pop();
		if(px==cx&&py==cy)return pst;
		for(int k=0;k<4;k++){
			int nx=px+dx[k],ny=py+dy[k];
			if(nx<0)nx=0;
			if(nx>=n)nx=n-1;
			if(ny<0)ny=0;
			if(ny>len[nx])ny=len[nx];
			if(used[nx][ny])continue;
			used[nx][ny]=true;
			qx.push(nx);qy.push(ny);
			qstep.push(pst+1);
		}
	}
	return -1;
}
int main(){
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	int rx,ry,cx,cy;
	cin>>n;
	for(int k=0;k<n;k++)cin>>len[k];
	cin>>rx>>ry>>cx>>cy;
	cout<<bfs(rx-1,ry-1,cx-1,cy-1);
	return 0;
}