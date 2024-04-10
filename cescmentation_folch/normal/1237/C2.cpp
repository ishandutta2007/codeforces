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
  vector<punt> S;
  for (int i = 0; i < n-1; ++i) {
    if (V[i].x == V[i+1].x and V[i].y == V[i+1].y) {
      cout << V[i].ind << ' ' << V[i+1].ind << '\n';
      V[i].ind = V[i+1].ind = 0;
      ++i;
    }
    else S.push_back(V[i]);
  }
  if (V.size() and V.back().ind) S.push_back(V.back());
  vector<punt> K;
  for (int i = 0; i < (int)S.size()-1; ++i) {
    if (S[i].x == S[i+1].x) {
      cout << S[i].ind << ' ' << S[i+1].ind << '\n';
      S[i].ind = S[i+1].ind = 0;
      ++i;
    }
    else K.push_back(S[i]);
  }
  if (S.size() and S.back().ind) K.push_back(S.back());
  for (int i = 0; i < (int)K.size()-1; ++i) {
    cout << K[i].ind << ' ' << K[i+1].ind << '\n';
    ++i;
  }

}