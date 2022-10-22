#include<bits/stdc++.h>
using namespace std;
const int N=1<<18;
int n,m,sa[N],rk[N],tp[N];
char s[N|1],t[N|1];
inline void sa_sort()
{
	static int cnt[N];memset(cnt,0,m<<2);
	for(int i=0;i<n;++i) ++cnt[rk[i]];
	for(int i=1;i<m;++i) cnt[i]+=cnt[i-1];
	for(int i=n-1;~i;--i) sa[--cnt[rk[tp[i]]]]=tp[i];
}
int main()
{
	scanf("%d %s",&n,s),n=1<<n;
	for(int i=0;i<n;++i) rk[i]=s[i]-'a',tp[i]=i;
	m=26,sa_sort(),m=0;
	for(int l=1;m!=n && l<n;l<<=1)
	{
		for(int i=0;i<n;++i) tp[i]=sa[i]^l;
		sa_sort(),swap(rk,tp),rk[sa[0]]=0,m=1;
		for(int i=1;i<n;++i) rk[sa[i]]=
		(tp[sa[i]]==tp[sa[i-1]] && tp[sa[i]^l]==tp[(sa[i-1])^l])?m-1:m++; 
	}
	for(int i=0;i<n;++i) t[i]=s[i^sa[0]];
	printf("%s",t);
	return 0;
}