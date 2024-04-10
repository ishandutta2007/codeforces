#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
typedef long long ll;
#define ordered_set tree<pair<int,int>,null_type,less<pair<int,int> >,rb_tree_tag,tree_order_statistics_node_update>
ordered_set k;
int mi[500000],ma[500000];
int val[500000];
int primo=1;
int main(){
		ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int N,M;
    cin>>N>>M;
    for(int i=0;i<N;i++){
      k.insert({i+1,i+1});
      mi[i+1]=i+1;
      ma[i+1]=i+1;
      val[i+1]=i+1;
    }
    for(int i=0;i<M;i++){
      int a;
      cin>>a;
      ma[a]=max(ma[a],(int)k.order_of_key({val[a],a})+1);
      k.erase({val[a],a});
      primo--;
      k.insert({primo,a});
      val[a]=primo;
      mi[a]=1;
    }
    int pos=1;
    for(auto x:k){
      mi[x.second]=min(mi[x.second],pos);
      ma[x.second]=max(ma[x.second],pos);
      pos++;
    }
    for(int i=1;i<=N;i++)cout<<mi[i]<<" "<<ma[i]<<endl;
    return 0;
}