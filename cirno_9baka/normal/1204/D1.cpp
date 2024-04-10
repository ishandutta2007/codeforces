#include<bits/stdc++.h>  
using namespace std;
typedef long long ll;
#define ri register int
const int M=998244353;
int n,m,i,j,k,s[100005],mn=1<<30;
char c[100005]; 
int main()
{
	scanf("%s",c+1);
	for(i=1;c[i];i++)
		if(c[i]=='1')
			s[i]=s[i-1]+1;
		else
			s[i]=s[i-1]-1;
	for(i=strlen(c+1);i>=1;i--)
	{
		if(s[i]<=mn)
			c[i]='0';
		mn=min(mn,s[i]);
	}
	printf("%s",c+1);
}