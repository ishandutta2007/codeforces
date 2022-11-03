#include <bits/stdc++.h>
#define ll long long
#define db long double
#define x first
#define y second
#define mp make_pair
#define pb push_back
#define all(a) a.begin(), a.end()

using namespace std;

struct Aho {
    struct Vert {
        int to[26]; // tree edge
        int au[26]; // automata edge
        int suf;    // suf link
        int p;      // parent
        int c;      // edge char between vertex and parent
        int term;
        int ded;
        int len;
        Vert() { for (int i = 0; i < 26; i++) to[i] = -1, au[i] = 0; suf = 0; len = 0; }
    };

    Vert t[1000007];
    int sz;

    Aho() { sz = 1; }

    int add(const string& s) {
        int v = 0;
        for (char c : s){
            int now = c - 'a';
            if (t[v].to[now] == -1) t[sz].p = v, t[sz].c = now, t[sz].len = t[v].len + 1, t[v].to[now] = sz++;
            v = t[v].to[now];
        }
        t[v].term = 1;
        return v;
    }

    void buildSuf() {
        vector<int> st;
        int uk = 0;
        st.push_back(0);
        while(uk < st.size()){
            int v = st[uk++];
            if (v == 0 || t[v].p == 0) t[v].suf = t[v].ded = 0;
            else {
                int cur = t[t[v].p].suf;
                while(1){
                    if (t[cur].to[t[v].c] != -1){
                        t[v].suf = t[cur].to[t[v].c];
                        break;
                    }
                    if (cur == 0) break;
                    cur = t[cur].suf;
                }
            }

            if (t[t[v].suf].term) t[v].ded = t[v].suf; else t[v].ded = t[t[v].suf].ded;

            for (int i = 0; i < 26; i++) if (t[v].to[i] != -1) st.pb(t[v].to[i]);
        }
    }

    void buildAu() {
        vector<int> st;
        int uk = 0;
        st.push_back(0);
        while(uk < st.size()){
            int v = st[uk++];
            for (int i = 0; i < 26; i++){
                if (t[v].to[i] != -1) t[v].au[i] = t[v].to[i];
                else {
                    t[v].au[i] = t[t[v].suf].au[i];
                }
            }
            for (int i = 0; i < 26; i++) if (t[v].to[i] != -1) st.pb(t[v].to[i]);
        }
    }
} t;

int last[1000007];
int was[1000007];

int main(){
#ifdef LOCAL
	freopen("B_input.txt", "r", stdin);
	//freopen("B_output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);

  int n;
  cin >> n;

  ll res = 0;
  vector<string> a;

  for (int i = 0; i < n; ++i) {
    string s; cin >> s;
    t.add(s);
    a.pb(s);
  }

  t.buildSuf();
  t.buildAu();

  for (int i = 0; i < n; ++i) {
    int v = 0;
    int now = 0;

    vector<pair<int, int>> st;

    for (int j = 0; j < a[i].size(); ++j) {
      auto c = a[i][j];
      int to = c - 'a';
        
      v = t.t[v].au[to];

      int cp = v;

      if (!t.t[v].term || j + 1 == a[i].size()) v = t.t[v].ded;

      int fr = 1;

      while (v != 0) {
     //   cout << i << ' ' << j << ' ' << c << ' ' << v << ' ' << now << ' ' << was[v] << ' ' << fr << endl;
        
        int le = j - t.t[v].len + 1;

        if (was[v] == i + 1) {
          if (!fr) {
            if (last[v] == 0) break;

            now -= last[v];
            last[v] = 0;
          } else {

            while (st.size() > 0) {
              if (st.back().y >= le) {

                int node = st.back().x;
                if (last[node]) last[node] = 0, --now;

                st.pop_back();

              } else break;
            }

            st.pb(mp(v, le));

          }
        } else {
          if (fr) {
            last[v] = 1;

            while (st.size() > 0) {
              if (st.back().y >= le) {

                int node = st.back().x;
                if (last[node]) last[node] = 0, --now;

                st.pop_back();

              } else break;
            }

            st.pb(mp(v, le));

          } else last[v] = 0;
          now += last[v];
        }
        was[v] = i + 1;
        fr = 0;
        v = t.t[v].ded;
      }

      v = cp;
    }
  //  cout << a[i] << ' ' << now << endl;
    res += now;
  }

  cout << res << "\n";
}