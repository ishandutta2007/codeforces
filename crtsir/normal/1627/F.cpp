#include<bits/stdc++.h>
using namespace std;
int T,n,k,val[2][503][503],dis[503][503];
void calc(int r1,int c1,int r2,int c2){
	if(r2<r1)swap(r2,r1);
	if(c2<c1)swap(c2,c1);
	if(r1==r2)
		val[0][r1][c1+1]++;
	else
		val[1][r1+1][c1]++;
}
int main(){
	cin>>T;
	while(T--){
		cin>>n>>k;
		for(int i=0;i<=k+2;i++)
			for(int j=0;j<=k+2;j++){
				val[0][i][j]=0,
				val[1][i][j]=0;
				dis[i][j]=-1;
			}
		for(int i=0;i<n;i++){
			int r1,c1,r2,c2;
			scanf("%d%d%d%d",&r1,&c1,&r2,&c2);
			r1--;r2--;c1--;c2--;
			calc(r1,c1,r2,c2);
			calc(k-1-r1,k-1-c1,k-1-r2,k-1-c2);
		}
		priority_queue<pair<int,pair<int,int> > >q;
		dis[k/2][k/2]=0;
		q.push(make_pair(0,make_pair(k/2,k/2)));
		while(q.size()){
			int len=-q.top().first,x=q.top().second.first,y=q.top().second.second;q.pop();
			if(dis[x][y]!=len)continue;
			if(x>0)
				if(dis[x-1][y]==-1||len+val[0][x-1][y]<dis[x-1][y]){
					dis[x-1][y]=len+val[0][x-1][y];
					q.push(make_pair(-dis[x-1][y],make_pair(x-1,y)));
				}
			if(x<k)
				if(dis[x+1][y]==-1||len+val[0][x][y]<dis[x+1][y]){
					dis[x+1][y]=len+val[0][x][y];
					q.push(make_pair(-dis[x+1][y],make_pair(x+1,y)));
				}
			if(y>0)
				if(dis[x][y-1]==-1||len+val[1][x][y-1]<dis[x][y-1]){
					dis[x][y-1]=len+val[1][x][y-1];
					q.push(make_pair(-dis[x][y-1],make_pair(x,y-1)));
				}
			if(y<k)
				if(dis[x][y+1]==-1||len+val[1][x][y]<dis[x][y+1]){
					dis[x][y+1]=len+val[1][x][y];
					q.push(make_pair(-dis[x][y+1],make_pair(x,y+1)));
				}
		}
		int ans=114514233;
		for(int i=0;i<=k;i++){
			ans=min(ans,dis[i][0]);
			ans=min(ans,dis[i][k]);
		}
		for(int i=0;i<=k;i++){
			ans=min(ans,dis[0][i]);
			ans=min(ans,dis[k][i]);
		}
		cout<<n-ans<<endl;
	}
}