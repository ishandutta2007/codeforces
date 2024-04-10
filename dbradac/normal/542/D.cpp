#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>

#define X first
#define Y second

using namespace std;

typedef long long ll;
typedef pair<ll, int> P;

const int MAX = 1000100, BRPR = 79000;

vector <int> Pr;
vector <P> R;
vector <ll> D;
vector <int> Dp[BRPR];
int bio[BRPR], slj[BRPR];
int sito[MAX];
int jelpr[MAX];
ll n;
int x=0;

void Djelitelji(int poz, ll dosad)
{
  if (poz == (int) R.size()) {
    D.push_back(dosad);
    return;
  }
  
  for (int i=0; i<=R[poz].Y; i++) {
    Djelitelji(poz+1, dosad);
    dosad *= R[poz].X;
  }
}

int JelProsti(ll x)
{
  if (x <= MAX)
    return !sito[x];

  for (int i=0; i<(int) Pr.size(); i++)
    if (!(x % Pr[i]))
      return 0;
  return 1;
}

int Rek(int ind, int indost)
{
  if (!indost)
    return 1;

  if (ind == (int) Pr.size()) {
    slj[ind] = ind;
    return D[indost] > MAX && jelpr[indost];
  }

  if (bio[ind]) {
    if (!Dp[ind].size())
      return Rek(slj[ind], indost);
    return Dp[ind][indost];
  }

  bio[ind] = 1;
  
  int da=0;
  for (ll pot=Pr[ind]; pot<n; pot*=Pr[ind])
    if (!(n % (pot + 1)))
      da = 1;

  if (!da) {
    int ret = Rek(ind + 1, indost);
    slj[ind] = slj[ind + 1];
    return ret;
  }

  slj[ind] = ind;

  for (int i=0; i<(int) D.size(); i++) {
    ll tmp = D[i];
    int rje = Rek(ind + 1, i);
    for (ll pot=Pr[ind]; pot < tmp; pot *= Pr[ind]) {
      x++;
      if (!(tmp % (pot + 1)))
        rje += Rek(ind + 1, 
          lower_bound(D.begin(), D.end(), tmp / (pot + 1)) - D.begin());
    }

    Dp[ind].push_back(rje);
  }
  
  return Dp[ind][indost];
}

int main()
{
  for (int i=2; i<MAX; i++) {
    if (!sito[i]) {
      Pr.push_back(i);
      for (int j=2*i; j<MAX; j+=i)
        sito[j] = 1;
    }
  }

  cin >> n;
  ll tmp = n;

  for (int i=0; i<(int) Pr.size(); i++) {
    if (!(tmp % Pr[i])) {
      int pot=0;
      for (; !(tmp % Pr[i]); pot++, tmp /= Pr[i]);
      R.push_back(P(Pr[i], pot));
    }
  }

  if (tmp > 1)
    R.push_back(P(tmp, 1));

  Djelitelji(0, 1);
  sort(D.begin(), D.end());
  for (int i=0; i<(int) D.size(); i++)
    jelpr[i] = JelProsti(D[i] - 1);

  printf("%d\n", Rek(0, (int) D.size() - 1));

  return 0;
}