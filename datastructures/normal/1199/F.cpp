#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
int n;
char a[55][55];
int f[51][51][51][51];
inline bool check(register int x1,register int x2,register int y1,register int y2){
	for (int i=x1;i<=x2;i++)	
		for (int j=y1;j<=y2;j++)
			if (a[i][j]=='#')return 0;
	return 1;
}
inline int dfs(register int x1,register int x2,register int y1,register int y2){
	if (f[x1][x2][y1][y2]!=-1)return f[x1][x2][y1][y2];
	int s=max(x2-x1+1,y2-y1+1);
	if (x1==x2&&y1==y2){
		if (a[x1][y1]=='#')return f[x1][x2][y1][y2]=1;
		return f[x1][x2][y1][y2]=0;
	}
	if (s>0){
		for (register int i=x1;i<x2;i++)s=min(s,dfs(x1,i,y1,y2)+dfs(i+1,x2,y1,y2));
		for (register int i=y1;i<y2;i++)s=min(s,dfs(x1,x2,y1,i)+dfs(x1,x2,i+1,y2));
	}
	return f[x1][x2][y1][y2]=s;
}
int main(){
	cin>>n;
	for (int i=1;i<=n;i++)	
		for (int j=1;j<=n;j++)
			cin>>a[i][j];
	memset(f,-1,sizeof(f));
	cout<<dfs(1,n,1,n)<<endl;
	return 0;
}