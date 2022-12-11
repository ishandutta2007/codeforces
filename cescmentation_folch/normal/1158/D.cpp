#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll,ll> pi;
typedef vector<pi> vpi;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef long double ld;

struct pt {
  ll x,y;
  int ind;
  pt(ll a, ll b) : x(a), y(b) {}
  pt() {}
};

pt V[2020];

bool cmpini(pt a, pt b) {
  if (a.x == b.x) return a.y < b.y;
  return a.x < b.x;
}

pt reef;
int sign(pt a, pt b) {
  pt a1(a.x - reef.x, a.y - reef.y);
  pt b1(b.x - reef.x, b.y - reef.y);
  ll val = a1.x*b1.y - a1.y*b1.x;
  if (val > 0) return 1;
  else return -1;
}

bool cmpL(pt a, pt b) {
  return sign(a,b) > 0;
}

bool cmpR(pt a, pt b) {
  return sign(a,b) < 0;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  for (int i = 0; i < n; ++i) {
    cin >> V[i].x >> V[i].y;
    V[i].ind = i+1;
  }
  sort(V, V + n, cmpini);
  int k = n-1;
  for (int i = 0; i < n-2; ++i) {
    cout << V[0].ind << ' ';
    reef = V[0];
    swap(V[0], V[k]);
    char a;
    cin >> a;
    if (a == 'L') sort(V, V + k, cmpL);
    else sort(V, V+k, cmpR);
    --k;
  }
  cout << V[0].ind << ' ' << V[1].ind << '\n';
}