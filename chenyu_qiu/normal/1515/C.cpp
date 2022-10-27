#include <iostream>
#include<bits/stdc++.h>
#include <cmath>
using namespace std;
 
int main()
{
  int t, n, m, x;
 
  string s, s1, s2;
 
  cin>>t;
 
  while(t--)
  {
    cin>>n>>m>>x;
 
    int a[n];
    vector<pair<int, int>> vec;
 
    for(int i=0; i<n; i++)
    {
    cin>>a[i];
    vec.push_back(make_pair(a[i], i+1));
    }
 
    sort(a, a+n);
    sort(vec.begin(), vec.end());
 
    vector<pair<int, int>> v;
 
    int b[n+1];
 
    for(int i=0; i<m; i++)
    {
      v.push_back(make_pair(a[i], i));
      int p= vec[i].second;
      b[p]=i;
    }
 
    for(int i=m; i<n; i++)
    {
      if(i%m==0)
      {
        sort(v.begin(), v.end());
      }
      v[i%m].first+=a[i];
      int p= vec[i].second;
      b[p]= v[i%m].second;
    }
 
    cout<<"YES"<<endl;
    for(int i=1; i<=n; i++)
    {
      cout<<(b[i]+1)<<" ";
    }
    cout<<endl;
  }
 
  return 0;
   
}