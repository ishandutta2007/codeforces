#include <iostream>
#include <string>
#include <algorithm>
#include <memory.h>
using namespace std;

string board[500];
const int mod = 1e9+7;
int dp[500][250][500],n,m;

#define ll long long

int solve(int x,int c,int xl){
	int y = c-x, yl = n+m-2-xl-2*c;
	if(xl < 0 || yl < 0) return 0;
	if(xl == 0 && yl == 0) return 1;
	
	int xc= x+xl,yc = y+yl;
	if(board[y][x] != board[yc][xc])return 0;
	if(xl+yl == 1) return 1;
	int &ret= dp[x][c][xl];
	if(ret!=-1) return ret;
	ret = 0;
	for(int i=0;i<2;++i) for(int j=0;j<2;++j) ret = (ret+ solve(x+i,c+1,xl-i-j) )%mod;
	return ret;
}

int main(){
	cin>>n>>m;
	memset(dp,-1,sizeof(dp));
	for(int i=0;i<n;++i) cin>>board[i];
	cout<<solve(0,0,m-1)<<endl;
}