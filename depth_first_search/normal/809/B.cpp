#include<bits/stdc++.h>
#define Tp template<typename Ty>
#define Ts template<typename Ty,typename... Ar>
#define Reg register
#define RI Reg int
#define Con const
#define CI Con int&
#define I inline
#define W while
#define write(op,x,y) (printf("%d %d %d\n",op,x,y),fflush(stdout))
#define Check() (scanf("%s",s+1),s[1]=='T')
using namespace std;
int n,k;char s[10];
I int Solve(RI l,RI r)
{
	RI mid;W(l<r) mid=l+r>>1,write(1,mid,mid+1),
		scanf("%s",s+1),s[1]=='T'?r=mid:l=mid+1;return l;
}
int main()
{
	scanf("%d%d",&n,&k);RI t1,t2;t1=Solve(1,n),
	((t2=Solve(1,t1-1))==t1||!(write(1,t2,t1),Check()))&&(t2=Solve(t1+1,n));
	return write(2,t1,t2),0;
}