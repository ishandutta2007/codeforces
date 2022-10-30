#include<bits/stdc++.h>
using namespace std;
bool vis[1005];
int main()
{
  int b,g,n;
  cin>>b>>g>>n;
  int ans=0;
  for(int i=0;i<=b;i++)
  {
    int j=n-i;
    if(j<0) break;
    if(j>g) continue;
    //cout<<i<<" "<<j<<endl;
    ans++;
  }
  cout<<ans<<endl;
  
}