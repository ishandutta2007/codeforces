#include<cstdio>
#include<cstdlib>
#include<iostream>
#include<algorithm>
#include<cstring>
#include<queue>
#include<vector>
#include<map>
#include<set>
#include<stack>
#include<string>
#include<cmath>
#include<cctype>
#include<ctime>
#include<bitset>
using namespace std;
const int maxlongint=2147483647;
const int inf=1000000000;
char s[1000010];
int numa[1000010],numb[1000010];
int main()
{
	int a,b;
	cin>>s+1>>a>>b;
	int len=strlen(s+1);
	for(int i=1;i<=len;i++)
		numa[i]=(numa[i-1]*10+s[i]-48)%a;
	int k=1;
	for(int i=len;i>=1;i--)
	{
		numb[i]=(numb[i+1]+(s[i]-48)*k)%b;
		k=k*10%b;
	}
	for(int i=1;i<len;i++)
	{
	//	cout<<numa[i]<<' '<<numb[i]<<endl;
		if(s[i+1]!='0'&&numa[i]==0&&numb[i+1]==0)
		{
			cout<<"YES\n";
			for(int j=1;j<=i;j++)
				putchar(s[j]);
			putchar('\n');
			for(int j=i+1;j<=len;j++)
				putchar(s[j]);
			return 0;
		}
	}
	cout<<"NO";
}