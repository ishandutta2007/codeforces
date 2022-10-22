#include<iostream>
#include<cstdio>
#include<cstring>
#define maxn 10005
#define inf 0x3f3f3f3f
using namespace std;
typedef long long ll;
char a[maxn];
bool b[maxn];
bool vis[maxn];
int main()
{
	cin>>a;
	int len=strlen(a);
	int i,j;
	for(i=0;i<len;i++) b[i]=a[i]-'a';
	for(i=0;i<len-1;i++)
	{
		if(b[i]!=b[i+1])
		{
			for(j=0;j<i-j;j++)
			    swap(b[j],b[i-j]);
			vis[i]=1;
		}
	}
	if(b[0]==1) vis[len-1]=1;
	for(i=0;i<len;i++)
	{
		cout<<vis[i]<<" ";
	}
	return 0;
}