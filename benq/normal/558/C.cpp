#include <bits/stdc++.h>
using namespace std;
 
#define ll long long
#define mp make_pair
#define pb push_back
#define pii pair <int, int>
#define vi vector<int>
 
#define FOR(i, a, b) for (int i=a; i<b; i++)
#define F0R(i, a) for (int i=0; i<a; i++)
 
#define f first
#define s second
 
const int MOD = 1000000007;
const int MAX = 10000005;

int cnt[100005], vis[100005], steps[100005];
 
int main() {
  int n, res = MOD, x, y;
  cin >> n;
  FOR(i,1,n+1) {
    cin >> x;
    queue<pii> q;
    q.push(mp(x, 0));
    while(!q.empty()) {
      x = q.front().f;
      y = q.front().s;
      q.pop();
      if(x > 100003 || vis[x] == i) continue;
      vis[x] = i;
      steps[x] += y;
      cnt[x] ++;
      q.push(mp(x * 2, y + 1));
      q.push(mp(x / 2, y + 1));
    }
  }
  F0R(i,100001) if(cnt[i] == n && res > steps[i]) res = steps[i];
  cout << res;
  return 0;
}