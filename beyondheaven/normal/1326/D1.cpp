#include<bits/stdc++.h>
#define MaxN 1000123
std::string s;
std::vector<int>d1,d2;
int n,L,R;
inline int Begin1(int x){return ((x)-d1[x]+1);}
inline int Begin2(int x){return ((x)-d2[x]);}
inline int End1(int x){return ((x)+d1[x]-1);}
inline int End2(int x){return ((x)+d2[x]-1);}
inline int Begin1(int x,int y){return x-(y-x);}
inline int Begin2(int x,int y){return x-(y-x)-1;}
inline int End1(int x,int y){return x+(x-y);}
inline int End2(int x,int y){return x+(x-y)-1;}
inline void Solve()
{
	std::cin>>s;
	n=s.length();
	d1.clear();d1.resize(n+5);
	d2.clear();d2.resize(n+5);
	L=0;R=n-1;
	while(s[L]==s[R]&&L<R)++L,--R;
	--L,++R;
	for(int i=0,l=0,r=-1;i<n;++i)
	{
		int k=((i>r)?1:std::min(d1[l+r-i],r-i));
		while(0<=i-k&&i+k<n&&s[i-k]==s[i+k])++k;
		d1[i]=k--;
		if(i+k>r)r=i+k,l=i-k;
	}
	for(int i=0,l=0,r=-1;i<n;++i)
	{
		int k=((i>r)?0:std::min(d2[l+r-i+1],r-i+1));
		while(0<=i-k-1&&i+k<n&&s[i-k-1]==s[i+k])++k;
		d2[i]=k--;
		if(i+k>r)r=i+k,l=i-k-1;
	}
	int Lpos1=-1,Lpos2=-1;
	for(int i=L+1;i<n;++i)
	{
		if(Begin1(i)<=L+1&&End1(i,L+1)<=R-1)Lpos1=i;
		if(d2[i])if(Begin2(i)<=L+1&&End2(i,L+1)<=R-1)Lpos2=i;
	}
	int Rpos1=-1,Rpos2=-1;
	for(int i=R-1;i;--i)
	{
		if(End1(i)>=R-1&&Begin1(i,R-1)>=L+1)Rpos1=i;
		if(d2[i])if(End2(i)>=R-1&&Begin2(i,R-1)>=L+1)Rpos2=i;
	}
	int LEnd=-1,RBegin=0x3f3f3f3f;
	if(~Lpos1)LEnd=std::max(LEnd,End1(Lpos1,L+1));
	if(~Lpos2)LEnd=std::max(LEnd,End2(Lpos2,L+1));
	if(~Rpos1)RBegin=std::min(RBegin,Begin1(Rpos1,R-1));
	if(~Rpos2)RBegin=std::min(RBegin,Begin2(Rpos2,R-1));
	#ifdef Dubug
	printf("[%d,%d],[%d,%d]\n",L+1,LEnd,RBegin,R-1);
	#endif
	int Llen=LEnd-(L+1)+1,Rlen=(R-1)-RBegin+1;
	std::string ans;
	if(Llen>=Rlen)
	{
		for(int i=0;i<=L;++i)ans+=s[i];
		for(int i=L+1;i<=LEnd;++i)ans+=s[i];
		for(int i=R;i<n;++i)ans+=s[i];
	}
	else
	{
		for(int i=0;i<=L;++i)ans+=s[i];
		for(int i=RBegin;i<=R-1;++i)ans+=s[i];
		for(int i=R;i<n;++i)ans+=s[i];
	}
	std::cout<<ans<<std::endl;
}
int main()
{
	int T;
	std::ios::sync_with_stdio(false);
	std::cin>>T;
	while(T--)Solve();
	return 0;
}