#include<bits/stdc++.h>

using namespace std;

const int maxn=55;
const int dx[5]={0,1,1,1,2};
const int dy[5]={0,0,-1,1,0};
int n;
char x[maxn][maxn];


int main(){
	cin>>n;
	for(int i=1;i<=n;i++)cin>>(x[i]+1);
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(x[i][j]=='.'){
				for(int k=0;k<5;k++){
					int cx=i+dx[k],cy=j+dy[k];
					if(cx<1||cy<1||cx>n||cy>n){
						cout<<"NO";
						return 0;
					}
					if(x[cx][cy]=='#'){
						cout<<"NO";
						return 0;
					}
					x[cx][cy]='#';
				}
			}
		}
	}
	cout<<"YES";
	return 0;
}