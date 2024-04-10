/**
       .
       |`.
       ;  `.
       ; :. \           __
       ; ; \ \      .--"  \
       ; ;  ; ;     :      \
       ; ;  : :     ; ;     ;
       ' :   ; ;    ;::     :
        \ \  : ;--.-;; l     ;
         \ \  ;:    :;//'-.__:
         /\ \ ::____:::-\
        /  ).:+'""""""""=\
       :_,=""     /"-.    ;
       ;"       .'    `.  |
      :      .-^=    ==.\ |
      |  _.-".gp      gp:;:
      ;    /  $$      $$;: ;
     :    :  `--      --:  |
     ;    ;\        ,   '  |
    :    :  \      _   /   :
    ;    |   `.   `-' /     ;
   :     :    :`-.__.'      |
   ;          ;     :       |
  :     ...._/      '.__..  |
  ;   .'                  \ ;
 :   /                   _ Y
 ;  :         .g$$p.    d$$+.
 ;  ;     :.g$$$$$$$$p.d$$$$$b
 :  :     :$$$$$$$$$$$T$$$$$$$;
  \  ;    ;$$$$S$$$$$$$S$$$$$P
   `.|    |$$$$S$$$$$$$S$$$$P
     |    |T$$$$$SSSSS$$$$$$
     :    | `T$$$$$$$$$$$$$;
      ;   |   $$$$$$$$$$$$$
      |   :   $$$$$$$$$$$$;
      :    ; d$$$$$$$$$$$$;
      |    :d$$$$$$$$$$$$$$
      ;    :"^T$$$$$$$$$$$$b
     :     ;   `T$$$$$$$$$$P;
     ;    :      `T$$$$$$$P :
     |    ;        T$$$$$P   ;
     |   :          T$$P'    ;
     :   ;           $'      :
    ._;__;           :       :
    ; ;  ;           |       :
    :_L__:           |       ;
    .'    ;          |       ;
  .'      :          |      :
 :/ _.-.  :;         |      |
 /.'    \ |:         |      ;
//  bug  ;| ;        |     :
`        `' :        |     |
             ;       |     ;
             :       |    :
              ;      |    |
              :      :    ;
              :    _.'-   ;
              ;     /:    :
             /     / ;     ;
            /     :  ;     :
           :      ;  ;     :
           ;     :  :      :
          :      ;  :      ;
          ;     :   ;     :
         :      ;   ;     ;
         ;     :    ;    :
         ;     ;    ;    ;
         ;    :     ;   :
         |    ;     ;   ;
         |   :      ;  :
         |   ;      ;  ;
         :  :       :  ;
         ;  :       :  :
        :    ,      ;   ;
        ;    ;      ;   :
       :     :      :    ;
       :     ;      :b__d$
       $b   d$       $$$$$
       :$bgd$;        T$P'
        T$$$P
         '"'
**/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int N = (int) 3e5 + 7;
const int M = 998244353;

int n;
int m;
int l[N];
int r[N];
vector<int> in[N];
vector<int> out[N];
vector<int> bad[N];
int par[N];
int id[N];
vector<int> who[N];
int dp[30];
int dp2[30];
vector<vector<int>> memo[N];
int fact[N];
int inv_fact[N];

int comp(int x) {
  if (par[x] == x) {
    return x;
  } else {
    return par[x] = comp(par[x]);
  }
}

void unite(int x, int y) {
  par[comp(x)] = comp(y);
}

bool vis[N];

bool independent_set(vector<int> nodes) {
  for (auto &x : nodes) {
    for (auto &y : bad[x]) {
      vis[y] = 1;
    }
  }
  bool indp = 1;
  for (auto &x : nodes) {
    if (vis[x]) {
      indp = 0;
      break;
    }
  }
  for (auto &x : nodes) {
    for (auto &y : bad[x]) {
      vis[y] = 0;
    }
  }
  return indp;
}

int pw(int a, int b) {
  int r = 1;
  while (b) {
    if (b & 1) {
      r = (ll) r * a % M;
    }
    a = (ll) a * a % M;
    b /= 2;
  }
  return r;
}

int comb(int n, int k) {
  return (ll) fact[n] * inv_fact[k] % M * inv_fact[n - k] % M;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  fact[0] = 1;
  for (int i = 1; i < N; i++) {
    fact[i] = (ll) fact[i - 1] * i % M;
  }
  inv_fact[N - 1] = pw(fact[N - 1], M - 2);
  for (int i = N - 2; i >= 0; i--) {
    inv_fact[i] = (ll) inv_fact[i + 1] * (i + 1) % M;
  }
  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    cin >> l[i] >> r[i];
    in[l[i]].push_back(i);
    out[r[i] + 1].push_back(i);
    par[i] = i;
  }
  for (int i = 1; i <= m; i++) {
    int x, y;
    cin >> x >> y;
    unite(x, y);
    bad[x].push_back(y);
    bad[y].push_back(x);
  }
  for (int i = 1; i <= n; i++) {
    id[i] = (int) who[comp(i)].size();
    who[comp(i)].push_back(i);
  }
  for (int c = 1; c <= n; c++) {
    int sz = (int) who[c].size();
    if (sz <= 1) {
      continue;
    }
    vector<vector<int>> cnt(1 << sz, vector<int>(sz + 1, 0));
    for (int m = 0; m < (1 << sz); m++) {
      vector<int> nodes;
      for (int i = 0; i < sz; i++) {
        if (m & (1 << i)) {
          nodes.push_back(who[c][i]);
        }
      }
      if (independent_set(nodes)) {
        cnt[m][(int) nodes.size()]++;
      }
    }
    for (int x = 0; x <= sz; x++) {
      for (int bt = 0; bt < sz; bt++) {
        for (int m = (1 << sz) - 1; m >= 0; m--) {
          if (m & (1 << bt)) {
            cnt[m][x] += cnt[m ^ (1 << bt)][x];
          }
        }
      }
    }
    memo[c] = cnt;
  }
  int single = 0;
  map<int, int> fc;
  set<int> act;
  int sol = 0;
  for (int cnt = 1; cnt <= n; cnt++) {
    for (auto &i : in[cnt]) {
      int c = comp(i), j = id[i];
      if ((int) who[c].size() == 1) {
        single++;
      } else {
        if (fc[c] == 0) {
          act.insert(c);
        }
        fc[c] += (1 << j);
      }
    }
    for (auto &i : out[cnt]) {
      int c = comp(i), j = id[i];
      if ((int) who[c].size() == 1) {
        single--;
      } else {
        fc[c] -= (1 << j);
        if (fc[c] == 0) {
          act.erase(c);
        }
      }
    }
    int cur = 0;
    for (int i = 0; i <= 25; i++) {
      dp[i] = 0;
    }
    dp[0] = 1;
    for (auto &c : act) {
      int sz = (int) who[c].size();
      for (int x = 0; x <= sz; x++) {
        int val = memo[c][fc[c]][x];
        for (int j = 25; j >= 0; j--) {
          if (dp[j]) {
            dp2[j + x] = (dp2[j + x] + (ll) val * dp[j]) % M;
          }
        }
      }
      for (int i = 0; i <= 25; i++) {
        dp[i] = dp2[i];
        dp2[i] = 0;
      }
    }
    for (int j = 0; j <= 25 && j <= cnt; j++) {
      if (j + single < cnt) {
        continue;
      }
      int ch = cnt - j;
      cur = (cur + (ll) comb(single, ch) * dp[j]) % M;
    }
    sol = (sol + cur) % M;
  }
  cout << sol << "\n";
  return 0;
}