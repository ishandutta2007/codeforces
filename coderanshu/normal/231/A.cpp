#include<bits/stdc++.h>
using namespace std;

int main()
{
  int n,x,i,j,z;
  int ans=0;
  cin>>n;
  for(i=0;i<n;i++)
  {
      z=0;
      for(j=0;j<3;j++)
      {
          cin>>x;
          if(x==1)z++;
      }
      if(z>=2)ans++;
  }
   cout<<ans;
	return 0;
}