#include<bits/stdc++.h>
using namespace std;
int main()
{
  int n,s,i,j;
  cin>>s>>n;
  int a[n][2];
  for(i=0;i<n;i++)
  {
      cin>>a[i][0]>>a[i][1];
  }
  for(i=0;i<n;i++)
  {
      for(j=0;j<n-i-1;j++)
      {
          if(a[j][0]>a[j+1][0])
          {
              swap(a[j][0],a[j+1][0]);
              swap(a[j][1],a[j+1][1]);
          }
      }
  }
  int flag=0;
  for(i=0;i<n;i++)
  {
      if(s>a[i][0])
      {
          s+=a[i][1];
      }
      else{
          flag=1;break;
          
      }
  }
  if(flag==0)
  cout<<"YES";
  else cout<<"NO";
    return 0; 
}