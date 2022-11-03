#include <bits/stdc++.h>
#define ll long long
#define db long double
#define ull unsigned long long
#define x first
#define y second
#define mp make_pair
#define pb push_back
#define all(a) a.begin(), a.end()

using namespace std;

#define pper(a) cerr << #a << " = " << a << endl;

void per() { cerr << endl; }
template<typename Head, typename... Tail> void per(Head H, Tail... T) { cerr << H << ' '; per(T...); }

template<class T> bool uin(T &a, T b) { return a > b ? (a = b, true) : false; }
template<class T> bool uax(T &a, T b) { return a < b ? (a = b, true) : false; }

template<class U, class V> 
ostream& operator<<(ostream& out, const pair<U, V>& a) {
  return out << "(" << a.x << ", " << a.y << ")";
}

template<class U, class V> 
istream& operator>>(istream& in, pair<U, V>& a) {
  return in >> a.x >> a.y;
}

template<typename W, typename T = typename enable_if<!is_same<W, string>::value, typename W::value_type>::type>
ostream& operator<<(ostream& out, const W& v) { out << "{ "; for (const auto& x : v) out << x << ", "; return out << '}'; }

template<class T>
void readArr(T from, T to) {
  for (auto i = from; i != to; ++i) cin >> *i;
}

mt19937 mrand(1337); 
unsigned int myRand32() {
  return mrand() & (unsigned int)(-1);
}
 
unsigned ll myRand64() {
  return ((ull)myRand32() << 32) ^ myRand32();
}

const int mod = 1000000007;

void add(int& a, int b) {
  a += b; if (a >= mod) a -= mod;
}

void dec(int &a, int b) {
  a -= b; if (a < 0) a += mod;
}

int mult(int a, int b) {
  return a * (ll)b % mod;
}

int bp(int a, int b) {
  int res = 1;
  while (b > 0) {
    if (b & 1) res = mult(res, a);
    a = mult(a, a);
    b >>= 1;
  }
  return res;
}


struct Tree {
  int t[1000007 * 4];

  void up(int v, int vl, int vr, int pos) {
    if (vl == vr) {
      t[v]++;
    } else {
      int vm = (vl + vr) >> 1;
      if (pos <= vm) up(v * 2 + 1, vl, vm, pos); else up(v * 2 + 2, vm + 1, vr, pos);
      t[v] = t[v * 2 + 1] + t[v * 2 + 2];
    }
  }

  int get(int v, int vl, int vr, int l, int r) {
    if (r < vl || l > vr) return 0;
    if (vl >= l && vr <= r) {
      return t[v];
    } else {
      int vm = (vl + vr) >> 1;
      return get(v * 2 + 1, vl, vm, l, r) + get(v * 2 + 2, vm + 1, vr, l, r);
    }
  }

  int fi(int v, int vl, int vr, int pos) {


//    per(v, vl, vr, pos);

    if (pos < vl) return -1;
  
    if (vr <= pos) if (t[v] == vr - vl + 1) return -1;
    
    if (vl == vr) return vl;

    int vm = (vl + vr) >> 1;

    int res = fi(v * 2 + 2, vm + 1, vr, pos);
    if (res != -1) return res;
    return fi(v * 2 + 1, vl, vm, pos);
  }


  // i <= ri
  int fi2(int v, int vl, int vr, int ri = 0) {

    if (vl == vr) return min(vl, ri + t[v]);

    int vm = (vl + vr) >> 1;

    if (ri + t[v * 2 + 2] == vm) return vm;

    if (ri + t[v * 2 + 2] > vm) return fi2(v * 2 + 2, vm + 1, vr, ri);
  
    if (ri + t[v * 2 + 2] < vm) return fi2(v * 2 + 1, vl, vm, ri + t[v * 2 + 2]);


  }
} f1, f2;


const int MID = 500007;

int n;
int a[500007];

int main(){
#ifdef LOCAL
	freopen("C_input.txt", "r", stdin);
	//freopen("C_output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);

  cin >> n;
  readArr(a, a + n);

  for (int i = 0; i < n; ++i) {

    if (a[i] < 0) {

      f1.up(0, 0, 1000001, -a[i]);

    }

    int pos = f2.fi(0, 0, 1000001, MID + a[i] - 1);
    if (pos != -1)
      f2.up(0, 0, 1000001, pos);

   // pper(pos - MID);
  

    int start = f1.fi2(0, 0, 1000001);

  //  pper(start);

    cout << f2.get(0, 0, 1000001, MID - start, 1000001) - start << "\n";

  }

}