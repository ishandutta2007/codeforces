#include<bits/stdc++.h>
using namespace std;
const int maxn = 505;
char mp[maxn][maxn];
int dx[4] ={0,0,1,-1};
int dy[4] ={-1,1,0,0};
int r,c;
bool check(int i,int j){
	if (mp[i][j]!='W')return true;
	for (int x = 0;x<4;x++){
		int ii = i+dx[x];
		int jj = j+dy[x];
		if (ii>=0&&ii<r&&jj>=0&&jj<c&&mp[ii][jj]=='S')return false;
	}
	return true;
}
int main(){
	cin>>r>>c;
	for (int i=0;i<r;i++){
		scanf("%s",mp[i]);
	}
	for (int i=0;i<r;i++){
		for (int j=0;j<c;j++){
			if (check(i,j))continue;
			else{
				cout<<"No"<<endl;
				return 0;
			}
		}
	}
	cout<<"Yes"<<endl;
	for (int i=0;i<r;i++){
		for (int j=0;j<c;j++){
			printf("%c",mp[i][j]=='.'?'D':mp[i][j]);
		}
		printf("\n");
	}
	return 0;
}