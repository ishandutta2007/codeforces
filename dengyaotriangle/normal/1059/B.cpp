#include<bits/stdc++.h>
using namespace std;

const int maxn=1005;
const int dx[8]={0,0,1,1,0,0,-1,-1};
const int dy[8]={1,1,0,0,-1,-1,0,0};

char x[maxn][maxn];

int main(){
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>(x[i]+1);
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(x[i][j]=='.') continue;
			bool vld=0;
			for(int k=0;k<8;k++){
				int cur=k;
				int cx=i,cy=j;
				bool cvld=1;
				for(int l=0;l<9;l++){
					if(x[cx][cy]=='.') cvld=0;
					cx+=dx[cur];
					cy+=dy[cur];
					if(cx<=0||cy<=0||cx>n||cy>m){
						cvld=0;
						break;
					}
					cur++;
					if(cur==8) cur=0;
				}
				vld=vld||cvld;
			}
			if(!vld){
				cout<<"NO";
				return 0;
			}
		}
	}
	cout<<"YES";
	return 0; 
}