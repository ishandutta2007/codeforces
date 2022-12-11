#include<bits/stdc++.h>
const int MaxN = 100123;

int n,p[MaxN];
int L[MaxN],R[MaxN];

int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;++i)scanf("%d",p+i);
	
	for(int i=1;i<=n;++i)
	L[i]=(p[i]>p[i-1]?L[i-1]+1:1);
	for(int i=n;i;--i)
	R[i]=(p[i]>p[i+1]?R[i+1]+1:1);
	
	int maxv=std::max(*std::max_element(L+1,L+n+1),*std::max_element(R+1,R+n+1));
	int cnt=std::count(L+1,L+n+1,maxv)+std::count(R+1,R+n+1,maxv);
	if(cnt!=2 || maxv%2==0)return puts("0"),0;
	int ans=0;
	for(int i=1;i<=n;++i)
	if(L[i]==maxv && R[i]==maxv)++ans;
	printf("%d\n",ans);
	return 0;
}