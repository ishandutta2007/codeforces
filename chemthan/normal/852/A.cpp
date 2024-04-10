#include <bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define inf 1000000005
#define all(a) (a).begin(), (a).end()
#define ms(a,x) memset(a, x, sizeof(a))
#define mod 1000000007
#define sz(a) ((ll)(a).size())

template<class T> int getbit(T s, int i) { return (s >> i) & 1; }
template<class T> T onbit(T s, int i) { return s | (T(1) << i); }
template<class T> T offbit(T s, int i) { return s & (~(T(1) << i)); }
template<class T> int cntbit(T s) { return __builtin_popcount(s);}
#define Rep(i,n) for(int i = 0; i < (n); ++i)
#define Repd(i,n) for(int i = (n)-1; i >= 0; --i)
#define For(i,a,b) for(int i = (a); i <= (b); ++i)
#define Ford(i,a,b) for(int i = (a); i >= (b); --i)

typedef unsigned long long ull;
typedef long long ll;
typedef double ld;
#define eps 1e-12
typedef pair<int, int> II;
typedef pair<ll, ll> LL;
template<class T> T gcd(T a, T b){ T r; while (b != 0) { r = a % b; a = b; b = r; } return a;}
template<class T> T lcm(T a, T b) { return a / gcd(a, b) * b; }
#define PI (2 * acos((ld)0))
#define linf (1ll << 60)
#define y1 y32432
#define y0 y435346

#define maxn 400005

bool can[3300005];
int n, a[maxn];
string s;

int cal(int x){
  int res = 0;
  while(x){
    res += x % 10;
    x /= 10;
  }
  return res;
}

void init(){
  ms(can, 0);
  for(int i = 0; i <= 3300000; i++){
    int u = cal(i);
    int v = cal(u);
    if(v < 10) can[i] = 1;
    int ch[10];
    int temp = i, run = 0, sum = 0;
    while(temp){
      ch[++run] = temp % 10;
      sum += ch[run];
      temp /= 10;
    }
    for(int j = 2; j <= run; j++){
      int A = sum + ch[j] * 9;
      v = cal(A);
      if(v < 10){
        can[i] = 1;
      }
    }
  }
}

void prep(int x){
  int ch[10];
  int run = 0;
  while(x){
    ch[++run] = x % 10;
    x /= 10;
  }
  if(run == 0) ch[++run] = 0;
  for(int i = run; i >= 1; i--){
    cout << ch[i];
    if(i > 1) cout << "+";
    else cout << endl;
  }
}

void dig(int x){
  int u = cal(x);
  int v = cal(u);
  if(v < 10){
    prep(x);
    prep(u);
    return;
  }
  int ch[10];
  int temp = x, run = 0, sum = 0;
  while(temp){
    ch[++run] = temp % 10;
    sum += ch[run];
    temp /= 10;
  }
  for(int j = 2; j <= run; j++){
    int A = sum + ch[j] * 9;
    v = cal(A);
    if(v < 10){
      for(int i = run; i >= 1; i--){
        cout << ch[i];
        if(i == j);
        else if(i == 1) cout << endl;
        else cout << "+";
      }  
      prep(A);
      return;
    }
  }
}

int main()
{
  /* freopen("in.txt", "r", stdin); */
  /* freopen("out.txt", "w", stdout); */
  ios::sync_with_stdio(0);
  cin.tie(0);
  init();
  
  cin >> n >> s;
  int sum = 0;
  For(i, 1, n){
    a[i] = s[i - 1] - '0';
    sum += a[i];
  }

  if(can[sum]){
    for(int i = 1; i <= n; i++){
      cout << a[i];
      if(i < n) cout << "+";
      else cout << endl;
    }
    dig(sum);
    return 0;
  }
  srand(time(NULL));
  
  vector<int> V; 
  for(int i = 1; i <= n; i++) if(a[i]) V.push_back(i);
  int m = sz(V);

  while(1){
    int u = V[((rand() % 1000 * 1000) + rand() % 1000) % m];
    int v = V[((rand() % 1000 * 1000) + rand() % 1000) % m];
    int t = V[((rand() % 1000 * 1000) + rand() % 1000) % m];
    int q = V[((rand() % 1000 * 1000) + rand() % 1000) % m];
    vector<int> VV;
    VV.push_back(u); VV.push_back(v); VV.push_back(t); VV.push_back(q);
    sort(all(VV));
    u = VV[0];
    v = VV[1];
    t = VV[2];
    q = VV[3];
    int l1 = rand() % 6 + 1;
    int l2 = rand() % 5 + 1;
    int l3 = rand() % 5 + 1;
    int l4 = rand() % 5 + 1;
    if(v > u && u + l1 <= v && q + l4 <= n + 1 && t > v && v + l2 <= t && q > t && t + l3 <= q){
      int heso = 1, temp = sum;
      for(int i = u + l1 - 1; i >= u; i--){
        temp += a[i] * (heso - 1);
        heso *= 10;
      }
      heso = 1;
      for(int i = v + l2 - 1; i >= v; i--){
        temp += a[i] * (heso - 1);
        heso *= 10;
      }
      heso = 1;
      for(int i = t + l3 - 1; i >= t; i--){
        temp += a[i] * (heso - 1);
        heso *= 10;
      }
      heso = 1;
      for(int i = q + l4 - 1; i >= q; i--){
        temp += a[i] * (heso - 1);
        heso *= 10;
      }
      if(can[temp]){
        /* cout << u << " " << v << endl; */
        for(int i = 1; i <= n; i++){
          cout << a[i];
          if((i >= u && i < u + l1 - 1) || (i >= v && i < v + l2 - 1) || (i >= t && i < t + l3 - 1) || (i >= q && i < q + l4 - 1));
          else if(i < n) cout << "+";
          else cout << endl;
        }
        dig(temp);
        return 0;
      }
    }
  }

  return 0;
}