#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
using namespace std;
int n,flag,m;
char ch[105][105];
int main()
{
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			scanf("\n%c",&ch[i][j]);
	if(n%3==0)
	{
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=m;j++)
			{
				if(ch[i][j]!=ch[(i-1)/(n/3)*(n/3)+1][1]){flag=1; break;}
				for(int k=1;k<=3;k++)
					if((i+(n/3)-1)/(n/3)!=k&&ch[i][j]==ch[k*(n/3)-(n/3)+1][1])
						{flag=1;break;}
		}
	}
	if(!flag){
		puts("YES"); return 0;
	}}
	flag=0; swap(n,m);
	if(n%3==0){
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(ch[j][i]!=ch[1][(i-1)/(n/3)*(n/3)+1]){flag=1; break;}
			for(int k=1;k<=3;k++)if((i+(n/3)-1)/(n/3)!=k&&ch[j][i]==ch[1][k*(n/3)-(n/3)+1]){flag=1;break;}
		}
	}if(!flag){
		puts("YES"); return 0;
	}}
	puts("NO");
}