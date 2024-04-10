#include<bits/stdc++.h>
#define ll long long
using namespace std;
inline int read(){
   int s=0,w=1;
   char ch=getchar();
   while(ch<'0'||ch>'9'){if(ch=='-')w=-1;ch=getchar();}
   while(ch>='0'&&ch<='9') s=s*10+ch-'0',ch=getchar();
   return s*w;
}
int a[1000003];
int mx[1000003][21],mn[1000003][21],l2[1000003],n,m;
inline void init(int l)
{
	mx[l][0]=mn[l][0]=a[l];
	for(int i=1; i<=20; i++) mx[l][i]=max(mx[l][i-1],mx[min(l+(1<<(i-1)),n)][i-1]);
	for(int i=1; i<=20; i++) mn[l][i]=min(mn[l][i-1],mn[min(l+(1<<(i-1)),n)][i-1]);
	return ;
}
inline int query(int l,int r)
{
	if(l>r) return 0;
	int L=l2[r-l+1];
	return max(mx[l][L],mx[min(r-(1<<L)+1,n)][L])-min(mn[l][L],mn[min(r-(1<<L)+1,n)][L]);
}
ll A[1000003],B[1000003];
bool check(int x)
{
	if(x==1) return 0;
	if(x==n) return 1;
	if(a[x-1]>=a[x]&&a[x]<=a[x+1]) return 1;
	if(a[x-1]<=a[x]&&a[x]>=a[x+1]) return 1;
	return 0;
}
signed main()
{
	n=read();
	for(int i=1; i<=n; i++) a[i]=read();
    for(int i=2; i<=n; i++) l2[i]=l2[i>>1]+1;
	for(int i=n; i; --i) init(i);
	for(int i=1,lst=0; i<=n; i++)
	{
		if(check(i))
		{
			if(lst)
			{
				A[i]=max(A[lst]+query(lst+1,i),B[lst]+query(lst,i));
				B[i]=max(A[lst]+query(lst+1,i-1),B[lst]+query(lst,i-1));
			}
			else
			{
				A[i]=query(1,i),B[i]=query(1,i-1);
			}
			lst=i;
		}
	}
	printf("%lld\n",A[n]);
	return 0;
}