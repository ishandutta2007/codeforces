#include<bits/stdc++.h>
typedef long long LL;
LL n,k;
std::mt19937 rnd(time(0));
inline LL _rand(LL l,LL r)
{
	return (LL)((unsigned long long)(rnd())%(r-l+1))+l;
}
inline bool Query(LL l,LL r)
{
	static char ret[20];
	printf("%lld %lld\n",l,r);
	fflush(stdout);
	scanf("%s",ret);
	return ret[0]=='Y';
}
inline void Solve()
{
	LL L=1,R=n,Mid;
	while(1)
	{
		Mid=((L+R)>>1);
		if(R-L+1<=44)
		{
			LL p=_rand(L,R);
			if(Query(p,p))return;
			else
			{
				L=std::max(1LL,L-2*k);
				R=std::min(n,R+2*k);
			}
		}
		else
		{
			if(Query(L,Mid))
			{
				L=std::max(1LL,L-k);
				R=std::min(n,Mid+k);
			}
			else
			{
				L=std::max(1LL,Mid+1-k);
				R=std::min(n,R+k);
			}
		}
	}
}
int main()
{
	scanf("%lld%lld",&n,&k);
	Solve();
	return 0;
}