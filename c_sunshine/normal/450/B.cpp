#include<cstdio>
#include<iostream>
using namespace std;
const long long P=1000000007;
struct M
{
  long long a,b,c,d;
  M(long long aa,long long bb,long long cc,long long dd)
  {a=aa;b=bb;c=cc;d=dd;}
  M()
  {a=b=c=d=0;}
}O,A;
long long x,y,n;
M mult(M p,M q)
{
  M ret;
  ret.a=(p.a*q.a+p.b*q.c)%P;
  ret.b=(p.a*q.b+p.b*q.d)%P;
  ret.c=(p.c*q.a+p.d*q.c)%P;
  ret.d=(p.c*q.b+p.d*q.d)%P;
  return ret;
}
int main()
{
  cin>>x>>y;
  x%=P;y%=P;
  if(x<0)x+=P;
  if(y<0)y+=P;
  cin>>n;
  if(n==1){cout<<x<<endl;return 0;}
  if(n==2){cout<<y<<endl;return 0;}
  n-=2;
  O=M(1,-1,1,0);
  A=M(1,0,0,1);
  while(n)
  {
    if(n&1)A=mult(O,A);
    O=mult(O,O);
    n>>=1;
  }
  long long ans=(y*A.a+x*A.b)%P;
  if(ans<0)ans+=P;
  cout<<ans<<endl;
  return 0;
}