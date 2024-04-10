#include <bits/stdc++.h>

using namespace std;

bool home = 1;

typedef long long ll;
typedef long double ld;

const int M = (int) 1e9 + 7;

int add(int a, int b) {
  a += b;
  if (a >= M) return a - M;
  if (a < 0) return a + M;
  return a;
}

int mul(int a, int b) {
  return a * (ll) b % M;
}

int pw(int a, int b) {
  int r = 1;
  while (b) {
    if (b & 1) r = mul(r, a);
    a = mul(a, a);
    b /= 2;
  }
  return r;
}

int dv(int a, int b) {
  return mul(a, pw(b, M - 2));
}

void addup(int &a, int b) {
  a = add(a, b);
}

void print(vector<int> v) {
  cout << " ---> ";
  for (auto &x : v) {
    cout << x << " ";
  }
  cout << "\n";
}

class PalindromicTree {
private:
  bool vectorSet;
  vector<int> v;
  int A;
public:
  explicit PalindromicTree(vector<int> v, int maxElement) : v(v), A(maxElement), vectorSet(1) {
  }

  PalindromicTree() : vectorSet(0) {
  }

  PalindromicTree(PalindromicTree& other) = default;
  PalindromicTree(PalindromicTree&& other) = default;
  ~PalindromicTree() = default;

  PalindromicTree operator = (PalindromicTree& other) {}
  PalindromicTree operator = (PalindromicTree&& other) noexcept {}


  bool isvectorSet() {
    return vectorSet;
  }

  struct Vertex {
    int len;
    int dif;
   // vector<Vertex*> kids;
    unordered_map<int, Vertex*> kids;
    Vertex* suffixLink;
    Vertex* serialLink;

    int sum = 0;
  };


  void setVector(vector<int> v, int maxElement) {
    vectorSet = 1;
    A = maxElement;
  }

  void unsetVector() {
    vectorSet = 0;
  }

  void computePalindromicTree() {
    assert(vectorSet);

    Vertex* nothing = new Vertex;
    Vertex* negative = new Vertex;

 //   nothing->kids.resize(A, 0);
 //   negative->kids.resize(A, 0);

    nothing->len = 0;
    negative->len = -1;

    nothing->suffixLink = negative;
    negative->suffixLink = negative;

    nothing->dif = 1;
    negative->dif = 0;

    nothing->serialLink = negative;
    negative->serialLink = negative;



    Vertex* best = negative;
    int n = (int) v.size();

  ///  print(v);

    vector<int> lungimi;
  ///  cout << "      ";

    vector<int> dp(n + 1, 0);
    dp[0] = 1;

    for (int i = 0; i < n; i++) {
     // cout << " = " << i << " ";
      while (best != negative) {
        int j = i - best->len - 1;

    //    cout << i << " and " << j << "\n";

        if (j < 0) {
          best = best->suffixLink;
          continue;
        }
        if (v[i] == v[j]) {
          break;
        }
        best = best->suffixLink;
      }
     /// cout << i << " : " << best->len << "\n";
      //assert(best);
     /// cout << "inter ";



      if (!best->kids[v[i]]) {
        //cout << "inter ";

        best->kids[v[i]] = new Vertex;
        best->kids[v[i]]->len = 2 + best->len;
     //   best->kids[v[i]]->kids.resize(A, 0);


        Vertex* nw = best->kids[v[i]];

        best = best->suffixLink;

       // cout << "kek ";
        while (best != negative) {
          /// 0123
          /// abba
          int j = i - best->len - 1;
          if (j < 0) {
            best = best->suffixLink;
            continue;
          }
          if (v[i] == v[j]) {
            break;
          }
          best = best->suffixLink;
        }

       // cout << "kek ";
        if (best->kids[v[i]]) {
          best = best->kids[v[i]];
        }



        if (best == nw) {
          best = nothing;
        }
        nw->suffixLink = best;

        nw->dif = nw->len - best->len;

        if (nw->dif == best->dif) {
          nw->serialLink = best->serialLink;
        } else {
          nw->serialLink = best;
        }

        best = nw;
      } else {
       // cout << "bb";
        best = best->kids[v[i]];
      }
      lungimi.push_back(best->len);


      int sol = 0;
      {
        Vertex* cur = best;

        cur = best;
        while (cur != nothing && cur != negative) {
          int dif = cur->len - cur->serialLink->len;
          int delta = cur->len - cur->suffixLink->len;
          int last = dif / delta - 1;
          while (!(i + 1 - cur->len + last * delta < i + 1)) last--;

          last = i + 1 - cur->len + last * delta;

          cur->sum = dp[last];

          if (cur->dif == cur->suffixLink->dif) {
            addup(cur->sum, cur->suffixLink->sum);
          }
          addup(sol, cur->sum);
          cur = cur->serialLink;
        }
      }



      if (i % 2 == 0) {
        sol = 0;
      }
      dp[i + 1] = sol;
    }
    cout << dp[n] << "\n";
  }
};

signed main() {
  ios::sync_with_stdio(0); cin.tie(0);

  #ifdef ONLINE_JUDGE
  home = 0;
  #endif // ONLINE_JUDGE

  if (home) {
    freopen ("input", "r", stdin);
  } else {
    ///
  }
  int n;

  vector<int> a;
  {
    string s;
    cin >> s;
    n = (int) s.size();
    for (int i = 0; i < n / 2; i++) {
      a.push_back(s[i] - 'a');
      a.push_back(s[n - 1 - i] - 'a');
    }
    assert((int) a.size() == n);
  }

  PalindromicTree tr(a, 26);
  tr.computePalindromicTree();
  exit(0);

  vector<int> dp(n, 0);

  for (int i = 0; i < n; i++) {

  }

  cout << dp.back() << "\n";



  return 0;
}