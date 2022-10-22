#include<cstdio>
#include<algorithm>
using namespace std;
const int N=4e6+10;
int t[N],a[N],n,mx,p,c[N],m1;
int calc(int w)
{
	if(w>=mx) return w-mx;
	else if(t[w]==0) return -1;
	else return w-a[t[w]];
}
bool okok(int a)
{
	return c[a];
}
bool chk()
{
	for(int i=1;i<=n;i++)
		if(!c[a[i]]) return 0;
	return 1;
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		t[a[i]]=i;
	}
	mx=a[n];
	for(int i=1;i<=mx;i++) if(!t[i]) t[i]=t[i-1];
	if(chk()){printf("0");return 0;}
	int m,k,w,x1,x2;
	w=k=1;
	while(w<=mx)
	{
		for(int i=0;i<=k;i++) c[i+w]=1;
		w+=2*k+1,k++;
	}
	for(int x=1;x<=mx;x++)
	{
		m=k=x,w=a[1],m1=0;
		while(1)
		{
			if(w-k<0||!t[w-k]) x1=w;
			else x1=a[t[w-k]+1];
			if(w-k>=mx) break;
			x2=calc(w+k);
			if(x2<m) m=x2;
			if(w-x1>m){p=1;break;}
			if(w-x1>m1) m1=w-x1;
			w+=2*k+1,k++;
		}
		if(m1>m) p=1;
		if(!p)
		{
			long long s=1ll*x*x+m1-a[1];
			if(s<0)
			{
				if(s-m1+m>=0) printf("0");
				else continue;
			}
			else printf("%lld",s);
			break;
		}
		else p=0;
	}
}