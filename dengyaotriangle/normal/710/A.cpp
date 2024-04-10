#include<bits/stdc++.h>

using namespace std;

const int dx[8]={-1,-1,-1,0,0,1,1,1};
const int dy[8]={-1,0,1,-1,1,-1,0,1};

int main(){
	char ip[2];
	cin>>ip;
	int x,y;
	x=ip[0]-'a';
	y=ip[1]-'1';
	int ans=0;
	for(int i=0;i<8;i++){
		if(x+dx[i]<0||x+dx[i]>=8||y+dy[i]<0||y+dy[i]>=8) continue;
		ans++;
	}
	cout<<ans;
	return 0;
}