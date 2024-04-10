#include<bits/stdc++.h>
using namespace std;

int main()
{
  int n,k,i,c;
  cin>>n;
  int a[n];
  for(i=0;i<n;i++)
  {
      cin>>a[i];
  }
  sort(a,a+n);
  k=(n+1)/2;
  for(i=1;i<n;i++)
  {
      c=1;
      while(a[i]==a[i-1] && i<n)
      {
         c++;i++; 
         if(c>k)
         {
             cout<<"NO";return 0;
         }
      }
  }
  cout<<"YES";
    return 0;
}