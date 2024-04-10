#include <bits/stdc++.h>
using namespace std;
bool flag[9][9];
char a;int b;
char get(){
	char k=getchar();
	for(;!isalpha(k);)k=getchar();
	return k;
}
int nx,ny,dx[8]={-2,-1,1,2,2,1,-1,-2},dy[8]={-1,-2,-2,-1,1,2,2,1};
signed main(){
	a=get();scanf("%d",&b);a-='a'-1;
	for(int i=1;i<=8;i++)flag[a][i]=true;
	for(int i=1;i<=8;i++)flag[i][b]=true;
	for(int i=0;i<8;i++){
		nx=a+dx[i];ny=b+dy[i];
		if (nx>=1&&ny>=1&&nx<=8&&ny<=8) flag[nx][ny]=true;
	}
	a=get();scanf("%d",&b);a-='a'-1;
	for(int i=0;i<8;i++){
		nx=a+dx[i];ny=b+dy[i];
		if (nx>=1&&ny>=1&&nx<=8&&ny<=8) flag[nx][ny]=true;
	}
	flag[a][b]=true;
	int ans=0;
	for(int i=1;i<=8;i++)
		for(int j=1;j<=8;j++)
			if(!flag[i][j])
				ans++;
	
	cout<<ans;
}