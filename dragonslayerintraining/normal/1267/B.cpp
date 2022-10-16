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

string S;
deque<pair<char,int>>v; //letter, freq
int N;

int main()
{
  //ios_base::sync_with_stdio(0);cin.tie(0);
  //freopen (".in","r",stdin);
  //freopen (".out","w",stdout);
  cin>>S;
  N=S.length();
  int cur=0;
  for (int i=0;i<N;i++){
    cur++;
    if (i+1==N || S[i]!=S[i+1]){
      v.push_back({S[i],cur});
      cur=0;
    }
  }
  while (v.size()>2 && v.front().first==v.back().first && v.front().second+v.back().second>=3){
    v.pop_front();
    v.pop_back();
  }
  if (v.size()==1 && v.front().second>=2)
    cout<<v.front().second+1<<endl;
  else
    cout<<0<<endl;
  return 0;
}