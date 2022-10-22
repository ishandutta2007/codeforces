#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
int a[200010];
vector<pair<int,int> > s;
int main(){
  //freopen("input.txt","r",stdin);
  //freopen("output.txt","w",stdout);
  ios_base::sync_with_stdio(0);
  int N,M,K;
  cin>>N>>M>>K;
  long long int u=0;
  for(int i=0;i<N;i++){
    cin>>a[i];
    u+=a[i];
    s.push_back({a[i],i});
  }
  sort(s.begin(),s.end());
  for(int i=0;i<N-M*K;i++){
    a[s[i].second]=-1000000001;
    u-=s[i].first;
  }
  cout<<u<<endl;
  int last=0;
  for(int i=0;i<K-1;i++){
    int o=0;
    for(int j=last;j<N;j++){
      if(a[j]==-1000000001)continue;
      o++;
      if(o==M){
        cout<<j+1<<" ";
        last=j+1;
        break;
      }
    }
  }
  return 0;
}