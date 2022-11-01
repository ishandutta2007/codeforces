#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll exgcd(ll a,ll b,ll &x,ll &y)
{
    if(!a && !b)return -1;
    if(!b)return x=1,y=0,a;
    ll d=exgcd(b,a%b,y,x);
    return y-=a/b*x,d;
}
int main()
{
    ll a,b,c,x,y,t;
    scanf("%lld%lld%lld",&a,&b,&c);
    t=exgcd(a,b,x,y);
  //  cout<<t<<endl;
    if(c%t) return 0*printf("-1");
    x *= -c/t;
	y *= -c/t;
    return 0*printf("%lld %lld",x,y);
}