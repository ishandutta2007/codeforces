#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

#define int ll
/// fflush(stdout); /// DO NOT FORGET TO FLUSH!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!

const int N = (int) 3e5 + 7;
const int K = 300; /// CHANGE TO 300!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
int q, cnt[N], cost[N], n, par[N], par2[N];

void solve(int vertex) {
  if (cnt[par[vertex]] == 0) par[vertex] = 0;
  if (cnt[par2[vertex]] == 0) par2[vertex] = 0;
}

signed main(){
  ///ios::sync_with_stdio(0); cin.tie(0);

 /// freopen ("input", "r", stdin);

  cin >> q >> cnt[1] >> cost[1];
  n++;
  while (q--) {
    n++;
    int type;
    cin >> type;
    if (type == 1) {
      int parr, new_a, new_c;
      cin >> parr >> new_a >> new_c; parr++;

    ///  g[parr].push_back(n);
      cnt[n] = new_a;
      cost[n] = new_c;

     /// cout << "add vertex " << n << "\n";

      par[n] = parr;
      par2[n] = n;
      for (int j = 1; j <= K; j++) {
        par2[n] = par[par2[n]];
      }

      solve(n);

    } else {
      int a, want, done = 0, pay = 0;
      cin >> a >> want; a++;

     /// cout << " : " << a << " " << par[a] << "\n";

      while (done < want) {
       /// cout << a << " " << cnt[a] << "\n";
        if (cnt[a] == 0) break;
        int vertex = a;

        while (1) {
          solve(vertex);
          if (par2[vertex]) {vertex = par2[vertex]; continue;}
          if (par[vertex]) {vertex = par[vertex]; continue;}
          break;
        }

        int take = min(cnt[vertex], want - done);
        done += take;
        cnt[vertex] -= take;
       /// cout << take << " and " << cost[vertex] << "\n";
        pay += take * cost[vertex];
      }


      cout << done << " " << pay << endl;
      ///fflush(stdout);
    //  if (n == 3) {
       /// cout << done << " " << pay << "\n";
    //  }
    ///  return 0;
    }
  }


  return 0;
}