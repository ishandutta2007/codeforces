#include<bits/stdc++.h>
using namespace std;
inline int read(){
   int s=0,w=1;
   char ch=getchar();
   while(ch<'0'||ch>'9'){if(ch=='-')w=-1;ch=getchar();}
   while(ch>='0'&&ch<='9') s=s*10+ch-'0',ch=getchar();
   return s*w;
}
set<pair<int,int> > s;
int a[1000003],b[1000003];
bool cmp(int x,int y)
{
	return a[x]<a[y];
}
int cnt[1000003],ccnt[1000003];
int MX=1;
signed main()
{
	int n=read();
	for(int i=1; i<=n; ++i) a[i]=read(),b[i]=i;
	sort(b+1,b+n+1,cmp);
	s.insert(make_pair(1,n));
	++cnt[n];
	int C=1;
	int ANS1=-1,ANS2=a[b[n]]+1;
	for(int i=n; i>=1; --i)
	{
		auto it=s.lower_bound(make_pair(b[i],100000000));
		--it;
		int L=(*it).first,R=(*it).second;
		if(cnt[R-L+1]==MX&&ccnt[MX]==1)
		{
			--MX;
		}
		s.erase(it),--ccnt[cnt[R-L+1]],--cnt[R-L+1],--C;
		++ccnt[cnt[R-L+1]];
		int r=b[i]-1,l=b[i]+1;
		if(L<=r)
		{
			--ccnt[cnt[r-L+1]];
			++cnt[r-L+1],++C;
			s.insert(make_pair(L,r));
			++ccnt[cnt[r-L+1]];
			MX=max(MX,cnt[r-L+1]);
		}
		if(l<=R)
		{
			--ccnt[cnt[R-l+1]];
			++cnt[R-l+1],++C;
			s.insert(make_pair(l,R));
			++ccnt[cnt[R-l+1]];
			MX=max(MX,cnt[R-l+1]);
		}
		if(MX==C)
		{
			if((int)s.size()>=ANS1) ANS1=(int)s.size(),ANS2=a[b[i-1]]+1;
		}
	}
	printf("%d\n",ANS2);
    return 0;
}