#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll, char> pi;
typedef vector<ll> vi;
typedef vector<pi> vpi;

bool comp(pi A, pi B) {
  if (A.second == B.second) return A.first >= B.first;
  return false;
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  ll n, m;
  cin >> n >> m;
  vpi T;
  for(ll i = 0; i< n; ++i) {
    ll x;
    char mander, tt;
    cin >> x >> mander >> tt;
    if ((ll)T.size() > 0 and T.back().second == tt) {
      T.back().first += x;
    }
    else T.push_back(pi(x, tt));
  }
  vpi S;
  for (ll i = 0; i < m; ++i){
    ll x;
    char mander, tt;
    cin >> x >> mander >> tt;
    if ((ll)S.size() > 0 and S.back().second == tt) {
      S.back().first += x;
    }
    else S.push_back(pi(x, tt));
  }
  
  if (S.size() == 1) {
    ll res = 0;
    for (ll i = 0; i < (ll)T.size(); ++i){
      if (comp(T[i], S[0])) {
	res += T[i].first - S[0].first + 1;
      }
    }
    cout << res << endl;
    return 0;
  }
  else if (S.size() == 2) {
    ll res = 0;
    for (ll i = 0; i < (ll)T.size() - 1; ++i){
      if (comp(T[i], S[0]) and comp(T[i + 1], S[1])) {
	res++;
      }
    }
    cout << res << endl;
    return 0;
  }
  
  vpi SS;
  for (ll i = 1; i < (ll)S.size() - 1; ++i) {
    SS.push_back(S[i]);
  }
  vpi TT;
  for (ll i = 1; i < (ll)T.size() - 1; ++i) {
    TT.push_back(T[i]);
  }
  
  vi P(SS.size() + 1, 0);
  ll k = 0;
  for (ll i = 2; i <= (ll)SS.size(); ++i) {
    while (k > 0 and SS[i - 1] != SS[k]) k = P[k];
    if (SS[i - 1] == SS[k]) ++k;
    P[i] = k;
  }
  ll res = 0;
  k = 0;
  for (ll i = 0; i < (ll)TT.size(); ++i) {
    while (k > 0 and TT[i] != SS[k]) k = P[k];
    if (SS[k] == TT[i]) ++k;
    if (k == (ll)SS.size()) {
      k = P[k]; //Matching
      if (i + 2 < (ll)T.size()) {
	if (comp(T[i + 2], S.back()) and comp(T[i-(ll)SS.size() + 1], S[0])) ++res;
      }
    }
  }
  cout << res << endl;
}