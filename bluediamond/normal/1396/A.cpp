#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
#define int ll

ll d;

pair<ll,ll>slove(ll a,ll b)
{
    if(b==0)
    {
        d=a;
        return {1,0};
    }
    else
    {
        pair<ll,ll>p=slove(b,a%b);
        return {p.second,p.first-(a/b)*p.second};
    }
}

const int N=(int) 1e5+7;
int n;
ll a[N];
ll x[N];
ll y[N];

pair<ll, ll> get(ll a, ll b, ll c) {
  pair<ll,ll>p=slove(a,b);
  return {c / d * p.first, c / d * p.second};
}

signed main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin>>n;
  for (int i=1;i<=n;i++) {
    cin>>a[i];
  }
  if (n == 1) {
    cout << "1 1\n0\n";
    cout << "1 1\n0\n";
    cout << "1 1\n" << -a[1] << "\n";
    return 0;
  }
  for (int i = 1; i <= n; i++) {
    pair<ll, ll> it = get(n, n - 1, -a[i]);
    x[i] = it.first;
    y[i] = it.second;
  }
  cout << "1 " << n << "\n";
  for (int i = 1; i <= n; i++) {
    cout << x[i] * n << " ";
  }
  cout << "\n";
  cout << "2 " << n << "\n";
  for (int i = 2; i <= n; i++) {
    cout << y[i] * (n - 1) << " ";
  }
  cout << "\n";
  cout << "1 " << n - 1 << "\n";
  cout << y[1] * (n - 1) << " ";
  for (int i = 2; i < n; i++) {
    cout << "0 ";
  }
  cout << "\n";
  return 0;
}