#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
///#define int long long

const int M = 998244353;

int add(int a, int b) {
  a += b;
  if (a >= M) {
    return a - M;
  }
  if (a < 0) {
    return a + M;
  }
  return a;
}

int mul(int a, int b) {
  return a * (ll) b % M;
}

int pw(int a, int b) {
  int r = 1;
  while (b) {
    if (b & 1) {
      r = mul(r, a);
    }
    a = mul(a, a);
    b /= 2;
  }
  return r;
}

int dv(int a, int b) {
  return mul(a, pw(b, M - 2));
}

void addup(int &a,int b) {
  a=add(a,b);
}

void mulup(int &a,int b) {
  a=mul(a,b);
}

const int N=50000+7;
bool edge[10][10];
int dp[N][1<<10];
vector<pair<int, int>> transitions;

signed main() {
#ifndef ONLINE_JUDGE
  freopen ("input.txt", "r", stdin);
#endif

#ifdef ONLINE_JUDGE
  ios::sync_with_stdio(0); cin.tie(0);
#endif // ONLINE_JUDGE

  int ndim,m;
  cin>>ndim>>m;

  for (int i=1;i<=m;i++) {
    int a,b;
    cin>>a>>b;
    edge[a][b]=edge[b][a]=1;
  }

  for (int first=0;first<10;first++) {
    dp[1][1<<first]=1;
  }
  {
    for (int mask=0;mask<(1<<10);mask++) {

      vector<int> who;
      for (int bit=0;(1<<bit)<=mask;bit++) {
        if (mask&(1<<bit)) {
          who.push_back(bit);
        }
      }

      for (int place=0;place<10;place++) {
        bool bad=0;
        int new_mask=1<<place;
        for (auto &pot:who) {
          if (edge[pot][place]) {
            new_mask|=(1<<pot);
          }
          if (pot<place&&edge[pot][place]) {
            bad=1;
            break;
          }
        }
        if(!bad) {
          transitions.push_back({mask, new_mask});
        }
      }
    }
  }

  for (int len=1;len<ndim;len++) {
    for (auto &it:transitions) {
      addup(dp[len+1][it.second], dp[len][it.first]);
    }
  }

  int sol=0;
  for (int mask=0;mask<(1<<10);mask++) {
    addup(sol,dp[ndim][mask]);
  }
  cout<<sol<<"\n";

  return 0;
}