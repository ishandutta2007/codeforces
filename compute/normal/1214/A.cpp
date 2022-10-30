#include<bits/stdc++.h>
using namespace std;
int main()
{
  int n,d,e;
  cin>>n>>d>>e;
  int ans=n;
  for(int i=0;;i++)
  {
    if(i*d>n) break;
    int j=(n-i*d)/e;
    ans=min(ans,n-(i*d+j*e)+(j%5)*e);
  }
  cout<<ans<<endl;
}