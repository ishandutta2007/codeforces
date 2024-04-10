#include<bits/stdc++.h>
#define Tp template<typename Ty>
#define Ts template<typename Ty,typename... Ar>
#define Rg register
#define RI Rg int
#define Cn const
#define CI Cn int&
#define I inline
#define W while
#define N 1000
using namespace std;
int n,p[N+5],ct;pair<int,int> s[2];
I int Q(CI a,CI b,CI c,CI d) {RI x;return printf("? %d %d %d %d\n",a,b,c,d),fflush(stdout),scanf("%d",&x),x&1;}
I void Find1(CI x) {RI l=1,r=n,mid;W(l^r) mid=l+r>>1,Q(x,l,x,mid)?r=mid:l=mid+1;s[ct++]=make_pair(x,l),p[l]=1;}
I void Find2(CI x) {RI l=1,r=n,mid;W(l^r) mid=l+r>>1,Q(l,x,mid,x)?r=mid:l=mid+1;s[ct++]=make_pair(l,x);}
int main()
{
	RI i;for(scanf("%d",&n),i=1;i<=n;++i) if(Q(i,1,i,n)) Find1(i);for(i=1;i^n;++i) if(!p[i]&&Q(1,i,n,i)) Find2(i);
	return ct==1&&(Find2(n),0),printf("! %d %d %d %d\n",s[0].first,s[0].second,s[1].first,s[1].second),0;
}