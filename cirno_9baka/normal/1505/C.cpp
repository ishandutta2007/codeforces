#include<bits/stdc++.h>
using namespace std;
int f[105];
int i,vis[105];
char c[105];
int main()
{
    int s=0;
    scanf("%s",c);
    for(i=0;c[i];++i)
    	f[i]=c[i]-'A';
    for(i=2;c[i];++i)
    	if(f[i]!=(f[i-1]+f[i-2])%26)
    	{
    		puts("NO");
    		return 0;
    	}
    puts("YES");
}