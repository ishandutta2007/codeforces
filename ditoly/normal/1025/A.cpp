#include<bits/stdc++.h>
using namespace std;
char s[100005];int u[26];
int main()
{
	int n,i;
	scanf("%d%s",&n,s);
	if(n==1)return 0*puts("Yes");
	for(i=0;i<n;++i)++u[s[i]-'a'];
	for(i=0;i<26;++i)if(u[i]>1)return 0*puts("Yes");
	puts("No");
}