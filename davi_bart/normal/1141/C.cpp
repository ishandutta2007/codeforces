#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
vector<ll> p;
bool vis[1000000];
int main(){
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
		ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
		ll N;
		cin>>N;
		p.push_back(0);
		ll mi=0;
		for(ll i=0;i<N-1;i++){
      ll a;
      cin>>a;
      p.push_back(p[i]+a);
      mi=min(mi,p.back());
		}
		for(ll i=0;i<N;i++){
		    p[i]=p[i]-mi+1;
		    if(p[i]>N || vis[p[i]]){
		        cout<<-1;
		        return 0;
		    }
		    vis[p[i]]=1;
		}
		for(ll i=0;i<N;i++)cout<<p[i]<<" ";
		return 0;
}