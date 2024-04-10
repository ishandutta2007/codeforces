#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

vector<ll>v;
ll solve(ll n)
{
  ll ans=0;
  for(int i=0;i<v.size();i++)
  {
  	if(v[i]==1)
      ans+=((ll)pow(2,i)+n)/(ll)pow(2,i+1);
  }
    
  return ans;
}
int main()
{
  ll n,l,r;
  cin>>n>>l>>r;
  while(n)
  {
      v.push_back(n%2LL);
      n/=2LL;
  }
  reverse(v.begin(),v.end());
  cout<<solve(r)-solve(l-1)<<endl;
  return 0;
}