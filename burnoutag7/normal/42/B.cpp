/******************
*  Author: BD747  *
******************/
#include<algorithm>
#include<cstdio>
#include<iostream>
#include<cstring>
#include<cmath>
#include<map>
#include<queue>
#include<set>
#include<sstream>
#include<stack>
#include<string>
#include<vector>
using namespace std;

int a[10][10];
bool wc[10][10];
char c;
int x,y;
int rx[2],ry[2];

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	cin>>c>>y;
	x=c-'a'+1;
	wc[x][y]=1;
	rx[0]=x;ry[0]=y;
	
	cin>>c>>y;
	x=c-'a'+1;
	wc[x][y]=1;
	rx[1]=x;ry[1]=y;
	
	cin>>c>>y;
	x=c-'a'+1;
	wc[x][y]=1;
	for(int rk=0;rk<=1;rk++){
		int xx=rx[rk],yy=ry[rk];
		for(int i=xx+1;i<=8;i++){
			a[i][yy]++;
			if(wc[i][yy])break;
		}
		for(int i=xx-1;i>=1;i--){
			a[i][yy]++;
			if(wc[i][yy])break;
		}
		for(int i=yy+1;i<=8;i++){
			a[xx][i]++;
			if(wc[xx][i])break;
		}
		for(int i=yy-1;i>=1;i--){
			a[xx][i]++;
			if(wc[xx][i])break;
		}
	}
	for(int i=-1;i<=1;i++){
		for(int j=-1;j<=1;j++){
			if(i==0&&j==0){
				a[x][y]=-1;
			}
			a[x+i][y+j]++;
		}
	}
	
	cin>>c>>y;
	x=c-'a'+1;
	
	for(int i=-1;i<=1;i++){
		for(int j=-1;j<=1;j++){
			if(i+x<1||j+y<1||j+y>8||i+x>8)continue;
			if(a[i+x][j+y]==0){
				cout<<"OTHER";
				return 0;
			}
		}
	}
	cout<<"CHECKMATE";
	
	return 0;
}