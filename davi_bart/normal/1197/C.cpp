#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
vector<int> v;
vector<int> diff;
int main(){
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(0);
    int N,K;
    cin>>N>>K;
    int a;
    for(int i=0;i<N;i++){
      cin>>a;
      v.push_back(a);
    }
    ll tot=0;
    for(int i=1;i<N;i++){
      diff.push_back(v[i]-v[i-1]);
    }
    sort(diff.begin(),diff.end());
    for(int i=0;i<N-K;i++)tot+=diff[i];
    cout<<tot;
    return 0;
}