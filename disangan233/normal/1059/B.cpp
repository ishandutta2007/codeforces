#include<bits/stdc++.h>
using namespace std;
#define re register int
int S[1010][1010],u[1010][1010];
char mm[1010][1010];
int n,m;
int main()
{
    cin>>n>>m;
    for(int i=1;i<=n;++i)
	for(int j=1;j<=m;j++)
	{
		char a;
		cin>>mm[i][j];
		if(mm[i][j]=='#')S[i][j]=1;
	}
    for(int i=2;i<n;++i)
    for(int j=2;j<m;++j)
    if(S[i-1][j-1]&&S[i-1][j]&&S[i-1][j+1]&&S[i][j+1]&&S[i][j-1]&&S[i+1][j-1]&&S[i+1][j]&&S[i+1][j+1])
    u[i-1][j-1]=u[i-1][j]=u[i-1][j+1]=u[i][j+1]=u[i][j-1]=u[i+1][j-1]=u[i+1][j]=u[i+1][j+1]=1;
    for(int i=1;i<=n;++i)
    for(int j=1;j<=m;++j)
    if(mm[i][j]=='#'&&!u[i][j])return puts("NO"),0;
    puts("YES");
    return 0;
}