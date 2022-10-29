
using namespace std;
#include<bits/stdc++.h>

#define N 300100
long long a[N],b[N],c[5*N],d[5*N],t;
void s(long long x ,long long y)
{
 c[++t]=x;
 d[t]=y;
 b[a[x]]=y;
 b[a[y]]=x;
 swap(a[x],a[y]);
}
int main()
{
 long long n;
 cin>>n;
 for(long long i=1;i<=n;i++)
 {
   cin>>a[i];
   b[a[i]]=i;
 }
 for(long long i=2;i<n;i++)
 {
  if(i<=n/2)
  {
   if(b[i]>n/2)
    s(1,b[i]);
    s(b[i],n);
    s(i,b[i]);
  }
  else
  {
   if(b[i]<=n/2)
    s(b[i],n);
   s(1,b[i]);
   s(1,i);
  }
 }
 if(a[1]==n)
  s(1,n);
 cout<<t<<endl;
 for(long long i=1;i<=t;i++)
 {
   cout<<c[i]<<" "<<d[i]<<endl;
 }
}