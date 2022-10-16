//  228

#include<bits/stdc++.h>
#define rep1(i, n) for(ll i=1;i<=n;i++)
#define rep(i, n) for(ll i=0;i<n;i++)
#define ll long long
 

using namespace std;

map <string, ll> mp;



int main() 
{ 
     
   ll n, m, flag  = 0, ans = 0;
   cin >> n >> m;
   string srr[n], sa[m], sb[m];
   rep(i, n) cin >> srr[i];
   
   sort(srr, srr+n);
   
   rep(i, n) mp[srr[i]] = i;
   
   rep(i, m) cin >> sa[i] >> sb[i];
   
   rep(i, 1<<n) {
                                       
       flag = 1;
       rep(j, m){
                                           
           if(((i) & (1<<mp[sa[j]])) && ((i) & (1<<mp[sb[j]]))) 
           flag = 0;                                 
                                           
       }
        if(flag == 1 && __builtin_popcount(i) > __builtin_popcount(ans))
        ans = i;
   }
//  cout<<ans<<"\n";
  cout<<__builtin_popcount(ans)<<"\n";
  rep(i, n){
                                      
     if(ans & (1<<i)) cout<<srr[i]<<"\n";                                 
                                      
  }
  
}