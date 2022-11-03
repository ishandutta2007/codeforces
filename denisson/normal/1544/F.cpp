#include <bits/stdc++.h>
#define ll long long
#define db long double
#define x first
#define y second
#define mp make_pair
#define pb push_back
#define all(a) a.begin(), a.end()

using namespace std;

const uint16_t mod = 31607;

inline void add(uint16_t& a, uint16_t b) {
  a += b;
  if (a >= mod) a -= mod;
}


inline void dec(uint16_t& a, uint16_t b) {
  add(a, mod - b);
}

inline uint16_t mult(uint16_t a, uint16_t b) {
  return a * (ll)b % mod;
}

uint16_t bp(uint16_t a, int b) {
  uint16_t res = 1;
  while (b > 0) {
    if (b & 1) res = mult(res, a);
    a = mult(a, a);
    b >>= 1;
  }
  return res;
}


const int K = 1<<23;

// u can set modular arithmetic here
void ANDConvolution(uint16_t* v){
    for (int step=K; step > 1; step /= 2){
        for (int start=0; start < K; start += step){
            for (int w=0; w < step/2; w++){
                add(v[start+w], v[start + w + step / 2]);
            }
        }
    }
}

void inverseANDConvolution(uint16_t* v){
    for (int step=K; step > 1; step /= 2){
        for (int start=0; start < K; start += step){
            for (int w=0; w < step/2; w++){
                dec(v[start+w], v[start + w + step / 2]);
            }
        }
    }
}

/* Usage Example
    ANDConvolution(f);
    ANDConvolution(g);
    for (int i = 0; i < K; i++) f[i] *= g[i];
    inverseANDConvolution(f);
    f is ur answer
*/

int n;
uint16_t a[22][22];
uint16_t b[22][22];
uint16_t ar[22][22];
uint16_t br[22][22];

uint16_t mask[1 << 23];
uint16_t cur[1 << 23];

int to[1 << 21];

uint16_t SUKA[1 << 21];

int main(){
#ifdef LOCAL
	freopen("G_input.txt", "r", stdin);
	//freopen("G_output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);

  for (int i = 0; i < 21; ++i) to[1 << i] = i;

  cin >> n;
  for (int i = 0; i < n; ++i) for (int j = 0; j < n; ++j) {
    ll x;
    cin >> x;
    a[i][j] = x % mod;
    a[i][j] = mult(a[i][j], bp(10000, mod - 2));
    b[i][j] = 1;
    dec(b[i][j], a[i][j]);


    ar[i][j] = bp(a[i][j], mod - 2);
    br[i][j] = bp(b[i][j], mod - 2);

  }

  mask[(1 << (n + 2)) - 1] = 1;
 // for (int i = 0; i < (1 << (n + 2)); ++i) mask[i] = 1;

  ANDConvolution(mask);


  for (int i = 0; i < n; ++i) {
    std::fill(cur, cur + (1 << 23), 0);

   // cout << i << endl;

    for (int m = 0; m < (1 << n) - 1; ++m) {
      int now = m;

      if (m == 0) {
        SUKA[0] = 1;
        for (int j = 0; j < n; ++j) SUKA[0] = mult(SUKA[0], b[i][j]);
      } else {
        int v = to[m & -m];

        SUKA[m] = SUKA[m ^ (1 << v)];
        SUKA[m] = mult(SUKA[m], br[i][v]);
        SUKA[m] = mult(SUKA[m], a[i][v]);
      }

   //   cout << i << ' ' << m << ' ' << SUKA[m] << endl;

      // int prod = 1;
      /*
      ll prod = 1;
      int cnt = 0;

      for (int j = 0; j < n; ++j) {
        if ((m >> j) & 1) {
          prod *= a[i][j];
          //prod = mult(prod, a[i][j]);
        } else {
          prod *= b[i][j];
          // prod = mult(prod, b[i][j]);
        }
        ++cnt;
        if (cnt == 4) {
          prod %= mod;
          cnt = 0;
        }
      }

      prod %= mod; */

      now ^= ((m >> i) & 1) << n;
      now ^= ((m >> (n - i - 1)) & 1) << (n + 1);

     // cout << m << ' ' << now << ' ' << prod << endl;

      add(cur[now], SUKA[m]);
    }

  /*  for (int w = 0; w < (1 << (n + 2)); ++w) {
      cout << w << ' ' << cur[w] << endl;
    }
    cout << endl;
*/

//    ANDConvolution(mask);
    ANDConvolution(cur);
    for (int i = 0; i < K; i++) mask[i] = mult(mask[i], cur[i]);


  /*  for (int w = 0; w < (1 << (n + 2)); ++w) {
      cout << w << ' ' << mask[w] << endl;
    }

    cout << endl;
    cout << endl;
*/
  }
    inverseANDConvolution(mask);


  //cout << bp(4, mod - 2) << endl;
//  cout << mult(1, bp(16, mod - 2)) << endl;

  ll res = mask[0];

//  for (int i = 0; i < (1 << (n + 2)); ++i) add(res, mask[i]);

  res = 1 - res;
  if (res < 0) res += mod;
  cout << res;
}