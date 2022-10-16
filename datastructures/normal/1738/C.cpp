#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int t,n,num0,num1,f[105][105][2][2];
int dfs(int x,int y,int t,int s){
	if (f[x][y][t][s]!=-1)return f[x][y][t][s];
	if (x==0&&y==0)return f[x][y][t][s]=(s^1);
	if (t==0){
		if ((x>0&&dfs(x-1,y,(t^1),s)==1)||(y>0&&dfs(x,y-1,(t^1),(s^1))==1))return f[x][y][t][s]=1;
		return f[x][y][t][s]=0;
	}
	if ((x>0&&dfs(x-1,y,(t^1),s)==0)||(y>0&&dfs(x,y-1,(t^1),s)==0))return f[x][y][t][s]=0;
	return f[x][y][t][s]=1;
}
int main(){
	cin>>t;
	while(t--){
		cin>>n;
		num0=num1=0;
		for (int i=1;i<=n;i++){
			int x;
			cin>>x;
			if (x%2==0)num0++;
			else num1++;
		}
		memset(f,-1,sizeof(f));
		if (dfs(num0,num1,0,0)==1)puts("Alice");
		else puts("Bob");
	}
	return 0;
}