#include<bits/stdc++.h> 
using namespace std;
int f[1010][2];
int l[1010], r[1010];
int n, m;
const int INF=1000000002;
int top,ans;
#define ll long long
void solve()
{
	top = 1;
    while (top <= n && r[top] == 0 && l[top] == m+1 && 1) 
		++top;
		
	int i;
    for (i = n; i>top; i--)
    {
        f[i][0] = min(f[i+1][0] + r[i] * 2, f[i+1][1] + m+1)+1;
        f[i][1] = min(f[i+1][1] + (m+1-l[i])*2, f[i+1][0] + m+1)+1;
    }
    
    if (top > n)
    {
        cout<<"0"<<endl;
        return;
    }
    else
    {
        ans = min(f[top+1][0] + r[i], f[top+1][1] + (m+1) - l[i])+1;
        cout<<ans-1<<endl;
    }
}
int main()
{
	scanf("%d%d",&n,&m);
    for (int i=1; i<=n; i++)
    {
    	r[i]=0;
    	l[i]=m+1;
    	
    	for (int j=0;j<=m+1;j++)
    	{
    		char c=getchar();
    		while (c!='0' && c!='1') c=getchar();
    		if (c == '1')
    		{
    			if (l[i]==m+1) l[i]=j;
    			r[i]=j;
			}
		}
    }
    
    f[n+1][1] = INF;
    solve();
    return 0;
}