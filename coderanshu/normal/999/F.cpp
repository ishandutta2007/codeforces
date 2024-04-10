//https://codeforces.com/contest/999/problem/F
#pragma GCC optimize "trapv" 
#include<bits/stdc++.h>
#define rep(i,a,n)     for(int i=a;i<n;i++)
#define rep3(n)        for(int i=0;i<n;i++)
#define inarr(arr,n)   rep(i,a,n)cin>>arr[i]
#define ll             long long int
#define pb             push_back
#define all(v)         v.begin(),v.end()
#define endl           "\n"
#define eb             emplace_back
#define x              first
#define y              second
#define gcd(a,b)       __gcd(a,b)
#define mem1(a)        memset(a,-1,sizeof(a))
#define pres(a,x)      a.find(x)!=a.end()
#define sz(a)          (int)a.size()
#define pii            pair<int,int>
#define IOS            ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define ret            return 0
#define pi             3.1415926536
#define hell           1000000007
#define narak          998244353
const int inf1=1e9;
const ll inf2=1e18;
const int N=100000;
using namespace std;
int dirs[4][2] ={{1,0},{-1,0},{0,1},{0,-1}};
ll dp[501][5001];
int h[100];
int n,k;
ll zaker(int i,int cards,int total){
   if(i>total){
       return 0;
   }
   if(dp[i][cards]!=-1){
       return dp[i][cards];
   }
   dp[i][cards]=0;
   for(int j=1;j<=min(k,cards);j++){
       dp[i][cards]=max(h[j]+zaker(i+1,cards-j,total),dp[i][cards]);
   }
   return dp[i][cards];
}
int solve(){
  cin>>n>>k;          
  map<int,int>mp;  // number of cards;
  rep3(n*k){
      int t;cin>>t;
      mp[t]++;
  }   
  map<int,int> mp2; // same fav;       
  rep3(n){
    int t;cin>>t;
    mp2[t]++;
  }
  h[0]=0;
  rep3(k)cin>>h[i+1];
  //rep3(k+1)cout<<h[i]<<" ";cout<<endl;
  ll ans=0;
  for(auto i:mp2){
     int cards=mp[i.x];
     int total=i.y;
     mem1(dp);
    ans=ans+zaker(1,cards,total);
   // cout<<i.x<<" "<<ans<<endl;
  }
  cout<<ans<<endl;
 ret;
}
int main(){
    IOS;
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    #ifdef cat
    cat();
    #endif
    int t=1;//cin>>t;
    while(t--){
        solve();
    }
    ret;
}