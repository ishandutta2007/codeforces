#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
int h[128];
bool book[200005];
char a[200005],b[200005];
bool cmp(int x,int y)
{
	return x>y;
}
int main()
{
	cin>>a;
	int len=strlen(a);
	sort(a,a+len);
	int i,j,tmp=0,tmp1=0,tmp2=0;
	for(i=0;i<len;i++) 
	    h[a[i]]++;
	for(i=0;i<len-1;i++)
	{
		if(book[i]==1) continue;
		if(h[a[i]]>=2)
		{
			book[i]=1;
			book[i+1]=1;
			h[a[i]]-=2;
			b[tmp]=a[i];
			b[len-tmp-1]=a[i];
			tmp++;
		}
	}
	for(i=0;i<len;i++)
	{
		if(book[i]==0)
		    b[tmp++]=a[i];
	}
	for(i=0;i<len/2;i++)
	{
		b[len-i-1]=b[i];
	}
	sort(b,b+(len/2));
	sort(b+len-(len/2),b+len,cmp);
	cout<<b;
	return 0;
}