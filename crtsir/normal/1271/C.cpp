#include<bits/stdc++.h>
using namespace std;
const int dx[4]={1,0,-1,0},dy[4]={0,1,0,-1};
int n,sx,sy,x[200003],y[200003];
pair<int,pair<int,int> >ans;
int main(){
	scanf("%d%d%d",&n,&sx,&sy);
	for(int i=0;i<n;i++)scanf("%d%d",x+i,y+i);
	for(int i=0;i<4;i++){
		int px=sx+dx[i],py=sy+dy[i],cnt=0;
		if(px<0||py<0||px>1e9||py>1e9)continue;
		for(int j=0;j<n;j++)
		{
			int cntt=0;
			cntt+=bool((sx<=px&x[j]>=px)|(sx>=px&x[j]<=px));
			cntt+=bool((sy<=py&y[j]>=py)|(sy>=py&y[j]<=py));
			if(cntt==2)cnt++;
		}
		ans=max(ans,make_pair(cnt,make_pair(px,py)));
	}
	cout<<ans.first<<'\n'<<ans.second.first<<' '<<ans.second.second;
}