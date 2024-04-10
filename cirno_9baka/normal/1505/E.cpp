#include<bits/stdc++.h>
using namespace std;
int f[105],n,m,i,j,x,y,ans;
char c[105][105];
int main()
{
    scanf("%d %d",&n,&m);
    for(i=1;i<=n;++i)
    	scanf("%s",c[i]+1);
    x=1,y=1;
    while(x<n||y<m)
    {
    	if(c[x][y]=='*')
    		++ans;
    	if(c[x][y+1]=='*')
    		++y;
    	else
    		if(c[x+1][y]=='*')
    			++x;
    		else
    			if(y+1<=m)
					++y;
				else
					++x;
	}
	if(c[x][y]=='*')
    	++ans;
    cout<<ans;
}