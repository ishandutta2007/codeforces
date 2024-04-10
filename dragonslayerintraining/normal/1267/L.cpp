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

int N,L,K;
string S;
string ans[1001];
deque<char>dq;

char get(){
  char c=dq.front();
  dq.pop_front();
  return c;
}

int main()
{
  //ios_base::sync_with_stdio(0);cin.tie(0);
  //freopen (".in","r",stdin);
  //freopen (".out","w",stdout);
  cin>>N>>L>>K; K--;
  cin>>S;
  for (int i=0;i<N;i++)
    ans[i]="";
  sort(S.begin(),S.end());
  for (int i=0;i<N*L;i++)
    dq.push_back(S[i]);
  for (int i=0;i<L;i++){
    int same=0;
    for (int j=0;j<N;j++)
      if (ans[j]==ans[K])
	same++;
    same=min(same,K+1);
    for (int i=K-same+1;i<=K;i++){
      ans[i]+=get();
    }
  }
  while ((int)ans[K].length()<L)
    ans[K]+=get();
  int cur=0;
  while (dq.size()>0){
    while (cur<N && (int)ans[cur].length()==L)
      cur++;
    ans[cur]+=get();
  }
  sort(ans,ans+N);
  for (int i=0;i<N;i++)
    cout<<ans[i]<<endl;
  return 0;
}