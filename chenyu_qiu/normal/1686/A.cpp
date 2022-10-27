#include<bits/stdc++.h>
using namespace std;
int main()
{
  int t;
  cin>>t;
  while(t--)
  {
   int n;
   cin>>n;
   vector<int> v;
   for(int i=0;i<n;i++)
   {
      int x;
      cin>>x;
      v.push_back(x);
   }
   int flag=0;
   for(int i=0;i<n;i++)
   {
      if((float)v[i]==(float)(accumulate(v.begin(),v.end(),0)-v[i])/(n-1))
      {
         flag=1;
         break;
      }
   }
   if(flag==1)
   {
      cout<<"YES"<<endl;
   }
   else{
      cout<<"NO"<<endl;
   }
   
  }
return 0;
}