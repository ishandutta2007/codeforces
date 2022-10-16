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

int N;
map<int,int>mp;
vector<int>v;

int check(int tot, int s){
  int ans=INF;
  for (int k=0;;k++){
    if (k*s>tot)
      break;
    if ((tot-k*s)%(s-1)==0)
      ans=min(ans,k+(tot-k*s)/(s-1));
  }
  return ans;
}

void solve(){
  scanf("%d",&N);
  mp.clear();
  v.clear();
  for (int i=0;i<N;i++){
    int x;
    scanf("%d",&x);
    mp[x]++;
  }
  int mn=INF;
  for (auto it:mp){
    v.push_back(it.second);
    mn=min(mn,it.second+1);
  }
  //cout<<"MN: "<<mn<<endl;
  for (int i=mn;i>=1;i--){
    bool bad=false;
    int ans=0;
    //cout<<i<<": "<<endl;
    for (int j=0;j<(int)v.size();j++){
      int temp=check(v[j],i);
      //cout<<temp<<endl;
      if (temp==INF){
	bad=true;
	break;
      }
      else
	ans+=temp;
    }
    if (!bad){
      printf("%d\n",ans);
      return;
    }
  }
}
  
int main()
{
  //ios_base::sync_with_stdio(0);cin.tie(0);
  //freopen (".in","r",stdin);
  //freopen (".out","w",stdout);
  int T;
  scanf("%d",&T);
  while (T--)
    solve();
  return 0;
}