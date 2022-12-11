#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef int llint;
typedef vector<llint> vi;
typedef vector<vi> vvi;
typedef pair<llint, llint> pi;
typedef vector<pi> vpi;
typedef vector<vpi> vvpi;

struct punt {
  ll x,y,z;
  int ind;
};

ll dist(punt a, punt b) {
  ll xd = a.x - b.x;
  ll yd = a.y - b.y;
  ll zd = a.z - b.z;
  return xd*xd + yd*yd + zd*zd;
}

bool comp(punt a, punt b) {
  if (a.x != b.x) return a.x < b.x;
  if (a.y != b.y) return a.y < b.y;
  return a.z < b.z;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  vector<punt> V(n);
  for (int i = 0; i < n; ++i) {
    cin >> V[i].x >> V[i].y >> V[i].z;
    V[i].ind = i+1;
  }
  sort(V.begin(), V.end(), comp);
  int ind = 0;
  for (int i = 0; i < n/2; ++i) {
    while (V[ind].ind == 0) ++ind;
    int tind = -1;
    ll val = -1;
    for (int j = ind +1; j < n; ++j) {
      if (V[j].ind) {
        ll dis = dist(V[ind], V[j]);
        if (val == -1 or val > dis) {
          val = dis;
          tind = j;
        }
      }
    }
    cout << V[ind].ind << ' ' << V[tind].ind << '\n';
    V[ind].ind = V[tind].ind = 0;
  }

}