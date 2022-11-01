#include<bits/stdc++.h>
using namespace std;
const int mod = 9973;
typedef long long ll;
const int N = 500010;
int n,cnt;
int c[N];
inline int lowbit(int x)
{
	return x&(-x);
}
void add(int x,int val)
{
	while(x)
	{
		if(c[x] < val) c[x] = val;
		x-=lowbit(x);
	}
}
int getmax(int x)
{
	int s = -1;
	while(x<=cnt)
	{
		if(s<c[x]) s = c[x];
		x+=lowbit(x);
	}
	return s;
}
struct node
{
	int b,i,r;
	int id;
}lady[N];
bool cmp(node a,node b)  
{  
    return a.b<b.b;  
}  
bool cmp1(node a,node b)  
{  
    return a.i>b.i;  
}
int read(){ int v = 0, f = 1;char c =getchar();
while( c < 48 || 57 < c ){if(c=='-') f = -1;c = getchar();}
while(48 <= c && c <= 57) v = v*10+c-48, c = getchar();
return v*f;}
int main()
{
	int ans = 0;
//	cin>>n;
//	for(int i=0;i<n;i++)cin>>lady[i].b;
//	for(int i=0;i<n;i++) cin>>lady[i].i;
//	for(int i=0;i<n;i++) cin>>lady[i].r;
	n=read();
	for(int i=0;i<n;i++)lady[i].b=read();
	for(int i=0;i<n;i++)lady[i].i=read();
	for(int i=0;i<n;i++)lady[i].r=read();
	
	sort(lady,lady+n,cmp);
	cnt = 1;
	lady[0].id = 1;
	for(int i=1;i<n;i++)
	{
		if(lady[i].b == lady[i-1].b)
		{
			lady[i].id = cnt;
		}
		else lady[i].id = ++cnt;
	}
	sort(lady,lady+n,cmp1);
	for(int i=1;i<=cnt;i++)
	{
		c[i] = -1;
	}
	int j;
	for(int i=0;i<n;)
	{
		for(j = i;j < n && lady[i].i==lady[j].i;j++)
		{
			if(getmax(lady[j].id + 1) > lady[j].r)
			{
				ans++;
			}
		}
		for(j = i; j < n && lady[i].i == lady[j].i;j++)
		{
			add(lady[j].id,lady[j].r);
		}
		i = j;
	}
	cout<<ans<<endl;
	return 0;
	
}