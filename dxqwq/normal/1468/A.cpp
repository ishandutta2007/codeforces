#include<bits/stdc++.h>

#define rd(x) x=read()

#define N 500005
#define lowbit(x) (x&-x)

using namespace std;

int T;
int n;
int a[N],f[N],c[N];
vector<int>v[N];
stack<int>s;

inline int read()
{
    int x=0,f=1;char ch=getchar();
    while(ch>'9'||ch<'0'){if(ch=='-')f=-1;ch=getchar();if(ch==-1)return 0;}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}

inline void write(int x)
{
    if(x<0){putchar('-');x=-x;}
    if(x>=10)write(x/10);
    putchar(x%10+'0');
}

inline void update(int x,int k){for(;x<=n;x+=lowbit(x))c[x]=max(c[x],k);}

inline int query(int x){int ans=0;for(;x;x-=lowbit(x))ans=max(ans,c[x]);return ans;}

int main()
{
	rd(T);
	while(T--)
	{
		rd(n);int ans=0;
		for(int i=1;i<=n;i++)rd(a[i]),c[i]=0;
		for(int i=1;i<=n+1;i++)v[i].clear(),f[i]=0;
		while(!s.empty())s.pop();s.push(n+1),a[n+1]=N;
		for(int i=n;i>=1;i--)
		{
			while(!s.empty()&&a[s.top()]<a[i])s.pop();
			v[s.top()].push_back(i),s.push(i);
		}
		f[1]=1,update(a[1],1);
		for(int i=2;i<=n;i++)
		{
			f[i]=max(2,query(a[i])+1);
			for(int j:v[i])update(a[j],f[j]+1);
			update(a[i],f[i]);
		}
		for(int i=1;i<=n;i++)ans=max(ans,f[i]);
		cout<<ans<<endl;
	}

    return 0;
}