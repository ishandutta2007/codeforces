#include<iostream>
#include<cstring>
#include<string>
#include<algorithm>
#include<cmath>
#include<vector>
#include<map>
#include<stack>
#include<queue>
#include<windows.h>
#include<deque>
#include<set>
using namespace std;
const int dx[]={-1,-1,-1,0,0,1,1,1},dy[]={-1,0,1,-1,1,-1,0,1};
char a[105][105];
int n,m,k,x,y,cnt;
bool ok; 
int main(){
	ok=true;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			 cin>>a[i][j];
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			if(a[i][j]=='*')
				continue;
			k=0;
			cnt=0;
			if(a[i][j]>='0'&&a[i][j]<='9')
				k=a[i][j]-'0';
			for(int d=0;d<8;d++)
			{
				x=i+dx[d];
				y=j+dy[d];
				if(a[x][y]=='*')
					cnt++;
			}
			if(k!=cnt)
			{
				cout<<"NO";
				return 0;
			}
		}
	}
	cout<<"YES";
	return 0;
}