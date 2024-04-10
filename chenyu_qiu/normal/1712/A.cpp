#include <bits/stdc++.h>
#include <map>
#define ll long long 
using  namespace std;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin>>t;
while(t--)
{
  int n,k;
  cin>>n>>k;
  int arr[n],count[101]={0},wr=0,x=k;
  for(int i=0;i<n;i++)
  {
    cin>>arr[i];
    if(x>=1)
    {
      count[arr[i]]++;
      x--;
    }
  }
for(int i=1;i<=k;i++)
{
  if(count[i]==0)wr++;
}
cout<<wr<<"\n";
 
}
 
}