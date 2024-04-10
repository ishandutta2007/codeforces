#include<bits/stdc++.h>
#define MaxN 3123
typedef long long LL;

char buf[1<<21],*p1,*p2;
#define getchar()((p1==p2&&(p2=(p1=buf)+fread(buf,1,1<<21,stdin),p1==p2))?EOF:*p1++)
template<typename T>
inline void read(T&x)
{
	x=0;int ch=getchar();
	while(ch<48||ch>57)ch=getchar();
	while(ch>47&&ch<58)x=10*x+ch-48,ch=getchar();
}

int n,k;
std::vector<int>a[MaxN];
LL ans,s[MaxN];

inline void Solve(std::vector<LL>&p,int L,int R)
{
	if(L==R)
	{
		LL tmp=0;
		for(int i=0;i<=static_cast<int>(a[L].size());++i)
		{
			if(i)tmp+=a[L][i-1];
			ans=std::max(ans,p[k-i]+tmp);
		}
		return;
	}
	
	int Mid=((L+R)>>1);
	std::vector<LL>l(p),r(p);
	
	for(int i=Mid+1;i<=R;++i)
	for(int j=k;j>=static_cast<int>(a[i].size());--j)
	l[j]=std::max(l[j],s[i]+l[j-static_cast<int>(a[i].size())]);
	
	for(int i=L;i<=Mid;++i)
	for(int j=k;j>=static_cast<int>(a[i].size());--j)
	r[j]=std::max(r[j],s[i]+r[j-static_cast<int>(a[i].size())]);
	
	Solve(l,L,Mid);Solve(r,Mid+1,R);
}

int main()
{
	read(n);read(k);
	for(int i=1,t;i<=n;++i)
	{
		read(t);
		for(int j=1,x;j<=t;++j)
		{
			read(x);
			a[i].push_back(x);
			if(j<=k)s[i]+=x;
		}
		if(static_cast<int>(a[i].size())>k)
		a[i].resize(k);
	}
	
	std::vector<LL>tmp(k+5,0);
	Solve(tmp,1,n);
	
	printf("%lld\n",ans);
	return 0;
}