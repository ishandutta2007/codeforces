#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n,i,j,count=0;
    cin>>n;
    pair<int,int> p[n];
    for(i=0;i<n;i++)
    {
        cin>>p[i].first>>p[i].second;
    }
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            if(p[i].first==p[j].second)
            count++;
        }
    }
  cout<<count;
  
   return 0; 
}