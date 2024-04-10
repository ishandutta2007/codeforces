#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <map>
#include <queue>
#include <set>
#include <iomanip>
#include <deque>
#include <cassert>
#include <ctime>
#include <cstring>
#include <cstdlib>
#include <chrono>
#include <ctime>
#include <random>
#include <stack>
#include <unordered_set>
#include <unordered_map>
#include <iterator>
#include <climits>
using namespace std;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
typedef long long ll;
typedef long double ld;
#define INF 2001001001
#define MOD 1000000007

int N,M;
int a[101][101];

int check(int win){
  vector<pair<int,int>>v;
  int sumA=0,sumB=0;
  for (int i=0;i<M;i++){
    sumA+=a[i][win];
    sumB+=a[i][N-1];
    v.push_back({a[i][win]-a[i][N-1],i});
  }
  sort(v.begin(),v.end());
  int ans=0;
  for (int i=0;i<M;i++){
    if (sumB<=sumA)
      break;
    sumA-=a[v[i].second][win];
    sumB-=a[v[i].second][N-1];
    ans++;
  }
  return ans;
}
int main()
{
  //ios_base::sync_with_stdio(0);cin.tie(0);
  //freopen (".in","r",stdin);
  //freopen (".out","w",stdout);
  cin>>N>>M;
  for (int i=0;i<M;i++)
    for (int j=0;j<N;j++)
      cin>>a[i][j];
  int ans=INF,store=-1;
  for (int i=0;i+1<N;i++)
    if (check(i)<ans){
      ans=check(i);
      store=i;
    }
  cout<<ans<<endl;
  int win=store;
  vector<pair<int,int>>v;
  int sumA=0,sumB=0;
  for (int i=0;i<M;i++){
    sumA+=a[i][win];
    sumB+=a[i][N-1];
    v.push_back({a[i][win]-a[i][N-1],i});
  }
  sort(v.begin(),v.end());
  for (int i=0;i<M;i++){
    if (sumB<=sumA)
      break;
    sumA-=a[v[i].second][win];
    sumB-=a[v[i].second][N-1];
    cout<<v[i].second+1<<' ';
  }
  cout<<endl;
  return 0;
}