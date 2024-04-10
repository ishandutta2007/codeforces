#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int n,m;
char s[2005][2005];
int main(){
	cin>>n>>m;
	for (int i=1;i<=n;i++)scanf("%s",s[i]+1);
	int l=1e9,r=0,u=1e9,d=0;
	for (int i=1;i<=n;i++)
		for (int j=1;j<=m;j++)
			if (s[i][j]=='B')l=min(l,j),r=max(r,j),u=min(u,i),d=max(d,i);
	cout<<(u+d)/2<<' '<<(l+r)/2<<endl;
	return 0;
}