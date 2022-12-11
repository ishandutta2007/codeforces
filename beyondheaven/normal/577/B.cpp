#include<bits/stdc++.h>
#define MaxN 1123
typedef std::bitset<MaxN> Bitset;
int n,m;
int a[MaxN*MaxN]; 

inline Bitset Shift(Bitset s,int p)
{
	p=m-p;
	return (s<<(m-p))|(s>>p);
}

inline void Print(Bitset s)
{
	for(int i=0;i<m;++i)
	if(s[i])putchar('1');
	else putchar('0');
	puts("");
}

int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;++i)scanf("%d",a+i);
	
	Bitset ans;
	ans.set(a[1]%m);
	#ifdef Dubug
	Print(ans);
	#endif
	
	for(int i=2;i<=n;++i)
	{
		ans|=Shift(ans,a[i]%m);
		ans.set(a[i]%m);
		#ifdef Dubug
		Print(ans);
		#endif
	}
	
	if(ans[0])puts("YES");
	else puts("NO");
	
	return 0;
}