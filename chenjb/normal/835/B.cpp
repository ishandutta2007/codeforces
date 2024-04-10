#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
using namespace std;
int a[110000];
char s[110000];
int k,n;
int main()
{
	cin>>k;
	scanf("%s",s);
	n=strlen(s);
	for(int i=0;i<n;i++)a[i+1]=s[i]-'0';
	sort(a+1,a+n+1);
	int ans=0;
	int now=0;
	for(int i=1;i<=n;i++)now+=a[i];
	int i=1;
	while (now<k)
	{
		now+=(9-a[i]);
		ans++;
		i++;
	}
	cout<<ans<<endl;
}