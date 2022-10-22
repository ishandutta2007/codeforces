#include<bits/stdc++.h>
#define Tp template<typename Ty>
#define Ts template<typename Ty,typename... Ar>
#define Rg register
#define RI Rg int
#define Cn const
#define CI Cn int&
#define I inline
#define W while
using namespace std;
int la,ra,ta,lb,rb,tb;I int gcd(CI x,CI y) {return y?gcd(y,x%y):x;}
int main()
{
	scanf("%d%d%d%d%d%d",&la,&ra,&ta,&lb,&rb,&tb),ra-la+1>rb-lb+1&&(swap(la,lb),swap(ra,rb),swap(ta,tb),0);
	RI d=gcd(ta,tb),t;la<lb?(t=(lb-la)/d,la+=t*d,ra+=t*d):(t=(la-lb+d-1)/d,la-=t*d,ra-=t*d);
	RI ans=min(ra,rb)-max(la,lb)+1;return la+=d,ra+=d,printf("%d\n",max(0,max(ans,min(ra,rb)-max(la,lb)+1))),0;
}