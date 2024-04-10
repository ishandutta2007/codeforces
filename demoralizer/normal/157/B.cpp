#include<bits/stdc++.h>

using namespace std;

int main()
{
  int n,s=0;
  cin>>n;
  int r[n+1];
  for(int i=0;i<n;i++)
  	cin>>r[i];
  sort(r,r+n,greater<int>());
  r[n]=0;
  for(int i=0;i<n;i+=2)
  	s+=r[i]*r[i]-r[i+1]*r[i+1];
  cout<<(3.1415926536*s)<<endl;
}