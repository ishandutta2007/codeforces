#include<bits/stdc++.h>
using namespace std;
int n,ans,vis[103][53][213][2];string s;
void dfs(int nowpos,int time,int nox,int dx){
	if(vis[nowpos][time][nox+100][dx])return;
	vis[nowpos][time][nox+100][dx]=1;
	if(nowpos==s.size()){if(time==0)ans=max(ans,max(nox,-nox));return;}
	for(int i=0;i<=time;i++){
		int go=(s[nowpos]=='F');
		go^=(i%2);
		dfs(nowpos+1,time-i,nox+(go==1?(dx?1:-1):0),go==0?dx^1:dx);
	}
}
int main(){
	cin>>s>>n;
	dfs(0,n,0,1);
	cout<<ans;
}