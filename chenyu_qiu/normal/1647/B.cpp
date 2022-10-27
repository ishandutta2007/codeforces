#include<bits/stdc++.h>
using namespace std;
 
#define yes cout<<"YES"<<endl;
#define no cout<<"NO"<<endl;
#define fin for(int i=0;i<n;i++)
#define test int t; cin>>t; while(t--)
#define ll long long int
#define pb push_back
#define sortvec(a) sort(a.begin(),a.end())
 
 
ll M = 1e6+1;
 
// FUNCTIONS TO BE USED *****
 
int bin_exp(int a,int b){
 
  if(b==0)
    return 1;
  int result = bin_exp(a,b/2);
  if(b&1){
    return a*result*1LL*result;
  }
  else{
    return result*1LL*result;
  }
}
 
ll bin_multiply(ll a,ll b){
  ll ans=0;
  while(b>0){
    if(b&1){
      ans=(ans+a)%M;
    }
    a=(a+a)%M;
    b>>=1;
  }
  return ans;
}
 
ll bin_exp_iter(ll a,ll b){
  ll ans = 1;
  while(b>0){
    if(b&1){
      ans=bin_multiply(ans,a);
    }
    a=bin_multiply(a,a);
    b>>=1;
  }
  return ans;
}
 
bool sortbysec(const pair<int,int> &a,const pair<int,int> &b)
{
    return (a.second > b.second);
}
 
bool sortpair(const pair<int,int> &a,const pair<int,int> &b){
       return a.second>b.second;
}
 
bool cmp(ll a, ll b){
	return a>b;
}
 
// *************//
 
void solve(){
 
  int n,m;
  cin>>n>>m;
  string s[n];
  fin{
    cin>>s[i];
  }
  
    for(int i=0;i<n-1;i++){
      for(int j=0;j<m-1;j++){
        int c=0;
          if(s[i][j]=='1')
           c++;
          if(s[i][j+1]=='1')
           c++;
          if(s[i+1][j]=='1')
           c++;
          if(s[i+1][j+1]=='1')
           c++;
          if(c==3){
            no
            return;
          }
          else
           continue;
      
      }
    }
    yes
  
    
}
 
int main(){
 
  ios_base::sync_with_stdio(false);
	cin.tie(NULL);
  test{
    solve();
  }
 
}