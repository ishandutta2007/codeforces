#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define int ll
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int v[100010],op[100010];
signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    //freopen("input.txt","r",stdin);
    int N,M,K;
    cin>>N>>M>>K;
    int prec=0;
    for(int i=0;i<N;i++){
        cin>>v[i];
        v[i]-=prec;
        prec+=v[i];
    }
    vector<pair<pair<int,int>,int> >p;
    for(int i=0;i<M;i++){
      int a,b,c;
      cin>>a>>b>>c;
      p.push_back({{a-1,b-1},c});
    }
    for(int i=0;i<K;i++){
      int a,b;
      cin>>a>>b;
      a--;b--;
      op[a]++;
      op[b+1]--;
    }
    int s=0;
    for(int i=0;i<M;i++){
      s+=op[i];
      v[p[i].first.first]+=p[i].second*s;
      v[p[i].first.second+1]-=p[i].second*s;
    }
    s=0;
    for(int i=0;i<N;i++){
      s+=v[i];
      cout<<s<<" ";
    }
}