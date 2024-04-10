#include<bits/stdc++.h>
using namespace std;

int main()
{
  int n;
  cin>>n;
  int h[n],m,M,mi=0,Mi=0,i;
  for(i=0;i<n;i++)
  {
  cin>>h[i];
  if(i==0)
  {
  M=h[0];m=h[0];
  }
  else if(h[i]>M)
  {
      Mi=i;M=h[i];
  }
  else if(h[i]<=m)
  {
      m=h[i];
      mi=i;
  }
  }
  if(Mi<=mi)
  cout<<Mi+n-mi-1;
  else
  cout<<Mi+n-mi-2;
  
   return 0; 
}