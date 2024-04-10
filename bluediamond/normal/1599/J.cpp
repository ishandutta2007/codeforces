#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

vector<int> sol;

void add(int x) {
  sol.push_back(x);
}


const int N = 1000 + 7;
const int A = 1000000 + 7;
int n, b[N];


void bad() {
  cout << "NO\n";
  exit(0);
}

void print() {
  assert((int) sol.size() <= n);
  while ((int) sol.size() < n) {
    sol.push_back(0);
  }
  cout << "YES\n";
  for (auto &x : sol) {
    cout << x << " ";
  }
  cout << "\n";
  exit(0);
}

vector<int> take;
map<int, vector<int>> mp;

void bkt(int pos, int need, int sum) {
//  cout << " = " << pos << " " << need << " " << sum << "\n";
  int urmeaza = n - pos + 1;
  if (need > urmeaza) return;


  if (pos == n + 1) {
    assert(need == 0);
    if (mp.count(sum)) {

      vector<int> take2 = mp[sum];
      /// dat fiind ca nu s-au intalnit in alt loc vor vi dizjuncte
    //  for (auto &i : take) cout << i << " "; cout << "\n";
     // for (auto &i : take2) cout << i << " "; cout << "\n";


      set<int> s;
      for (int i = 1; i <= n; i++) {
        s.insert(b[i]);
      }
      for (auto &x : take) {
        s.erase(x);
      }
      for (auto &x : take2) {
        s.erase(x);
      }
      add(0);
      for (auto &x : s) {
        add(x);
      }
      int sum = 0;
      for (int i = 0; i < (int) take.size(); i++) {
        sum = take[i] - sum;
        add(sum);

        sum = take2[i] - sum;
        add(sum);
      }
      assert(sol.back() == 0);
      sol.pop_back();
      //take.pop_back();
      print();



      exit(0);
    } else {
      mp[sum] = take;
    }

    return;
  }
 // cout << "bef\n";
  bkt(pos + 1, need, sum);

  //cout << "aft\n";
  if (need) {
    take.push_back(b[pos]);
    bkt(pos + 1, need - 1, sum + b[pos]);
    take.pop_back();
  }
}

signed main() {
 // freopen ("input", "r", stdin);

  {
    /// practic am un graf care are valori pe noduri
    /// dupa aia trazez muchii cu valoarea unei muchii = suma valorilor nodurilor unite de ea
    /**

    eu acum stiu muchiile

    aici practic exista un ciclu, dar eu nu stiu care este, daca il gasesc sunt mare boss
    pentru ca restul nodurilor pot fi pretty much orice

    cum arata un ciclu?

    de lungime 2: (x) -> (y) cu valoarea x + y apare de 2 ori
    de lungime 3: (x) -> (a - x) -> (b - a + x)
    si avem x + b - a + x = c => 2 * x = c - b + a

    de lungime 4: (x) -> (a - x) -> (b - a + x) -> (c - b + a - x)
    si aavem x + c - b + a - x = d
             c - b + a = d => c + a = d + b


    **/
  }

  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> b[i];
  }
  { /// ciclu de lungime 2
    set<int> s;
    for (int i = 1; i <= n; i++) {
      s.insert(b[i]);
    }
    if ((int) s.size() < n) {
      for (auto &x : s) {
        add(x);
      }
      add(0);
      print();
    }
  }

  if (n <= 2) {
    bad();
  }

  { /// ciclu de lungime 3
    /// parity(a) = parity(b + c)

    /// 3 pare si m-am scos


    vector<vector<int>> cc(2);
    for (int i = 1; i <= n; i++) {
      cc[b[i] % 2].push_back(b[i]);
    }

    if ((int) cc[0].size() >= 3) {
      int a = cc[0].back(); cc[0].pop_back();
      int b = cc[0].back(); cc[0].pop_back();
      int c = cc[0].back(); cc[0].pop_back();
      int x = (c - b + a) / 2;
      add(x);
      add(a - x);
      add(b - a + x);

      for (auto &v : cc) {
        for (auto &xx : v) {
          add(xx - x);
        }
      }
      print();
    }
    if ((int) cc[0].size() >= 1 && (int) cc[1].size() >= 2) {
      int a = cc[0].back(); cc[0].pop_back();
      int b = cc[1].back(); cc[1].pop_back();
      int c = cc[1].back(); cc[1].pop_back();
      int x = (c - b + a) / 2;
      add(x);
      add(a - x);
      add(b - a + x);
      for (auto &v : cc) {
        for (auto &xx : v) {
          add(xx - x);
        }
      }
      print();
    }
  }
  if (n <= 3) {
    bad();
  }

  /// ciclu par
  for (int l = 1; l <= n / 2; l++) {
    take.clear();
    bkt(1, l, 0);
    mp.clear();
  }

  cout << "NO\n";
  return 0;

  assert(0);


  return 0;
}