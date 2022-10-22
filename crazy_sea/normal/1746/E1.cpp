#include<cstdio>
#include<vector>
#include<cstring>
using namespace std;
int n,t[100010];
char str[10];
bool check(int a)
{
	printf("! %d\n",a);
	fflush(stdout);
	scanf("%s",str);
	return strcmp(str,":)")==0;
}
bool ask2(int a)
{
	printf("? 1 %d\n",a);
	fflush(stdout);
	scanf("%s",str);
	return strcmp(str,"YES")==0;
}
void work(int a,int b,int c)
{
	if(ask2(c))
	{
		if(!check(c))
			check(ask2(a)?a:b);
	}
	else if(!check(a)) check(b);
}
void solve(vector<int> a,vector<int> b)
{
	int x=a.size(),y=b.size();
	if(x==2&&y==1)
	{
		work(a[0],a[1],b[0]);
		return;
	}
	vector<int> v;
	for(int i=0;i<x/2;i++)
		v.push_back(a[i]);
	for(int i=0;i<y/2+(y&1);i++)
		v.push_back(b[i]);
	printf("? %llu",v.size());
	for(int i=1;i<=n;i++) t[i]=0;
	for(int u:v) printf(" %d",u),t[u]=1;
	printf("\n");
	fflush(stdout);
	scanf("%s",str);
	if(strcmp(str,"NO")==0)
		for(int i=1;i<=n;i++) t[i]^=1;
	vector<int> c,d;
	for(int i=0;i<x;i++)
		if(t[a[i]]) c.push_back(a[i]);
		else d.push_back(a[i]);
	for(int i=0;i<y;i++)
		if(t[b[i]]) c.push_back(b[i]);
	solve(c,d);
}
int main()
{
	scanf("%d",&n);
	if(n==1) check(1);
	else if(n==2)
	{
		if(!check(1))
			check(2);
	}
	else if(n==3)
	{
		if(ask2(1))
		{
			if(check(1)) return 0;
			if(ask2(2)) check(2);
			else check(3);
		}
		else work(2,3,1);
	}
	if(n<=3) return 0;
	vector<int> v1,v2;
	for(int i=1;i<=n;i++)
		v1.push_back(i);
	solve(v1,v2);
}