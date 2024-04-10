#include<bits/stdc++.h>
using namespace std;
int func(pair<int,int> a,pair<int,int> b)
{
    return a.second<b.second;
}
int main()
{
   pair<int,int> m[102];
   int n,x,i;
   cin>>n;
   for(i=0;i<n;i++)
   {
      cin>>m[i].second;
      m[i].first=i+1;
       
   }
   sort(m,m+n,func);
   for(i=0;i<n;i++)
   {
       cout<<m[i].first<<" ";
   }
   return 0; 
}