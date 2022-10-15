#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

signed main() {
  ios::sync_with_stdio(0); cin.tie(0);

  /**
  postulat : daca fiecare celula cu . pot sa ies afara => pot sa unic determin tabla
  de ce este acest postulat gresit intr-un mod fundamental? datorita contra exemplului, dar aceasta demonstratie
  nu este riguroasa avand in vedere existenta in paralel a altei demonstratii care demonstreaza corectitudinea algoritmului.
  haideti sa aruncam o privire asupra demonstratiei care demonstreaza corectitudinea algoritmului:

  contra exemplul la care fac referire este:
  ?X
  XX

  daca fiecare celula cu . pot sa ies afara =>
  la final fiecare celula . va fi un E si fiecare celula
  la final fiecare celula x va fi un N si fiecare celula

  avand in fata o tablita doar cu E-uri si N-uri
  este evident ca fiecare E va fi un .
  dar fiecare N va fi de asemenea un X?

  presupunem ca fiecare N este intrinsec un X

  atunci fiecare N de pe prima linie/coloana este automat un X

  avand deja determinate celul din jos si stanga ne intereseaza urmatoarele cazuri:


  ?.
  .N => N = X



  ?X
  .N => N = X


  ?.
  XN => N = X


  ?X
  XN => N = X sau .
  **/


  int n, m;
  cin >> n >> m;
  vector<vector<int>> valid(n, vector<int> (m, 0));
  for (int i = 0; i < n; i++) {
    string s;
    cin >> s;
    for (int j = 0; j < m; j++) {
      valid[i][j] = (s[j] == '.');
    }
  }

  vector<int> pref(m + 1, 0);
  for (int j = 0; j < m; j++) {
    for (int i = 0; i < n; i++) {
      if (i && j && !valid[i - 1][j] && !valid[i][j - 1]) {
        pref[j + 1]++;
        break;
      }
    }
    pref[j + 1] += pref[j];
  }

  int q;
  cin >> q;
  while (q--) {
    int l, r;
    cin >> l >> r;
    if (pref[l] != pref[r]) {
      cout << "NO\n";
    } else {
      cout << "YES\n";
    }
  }


  return 0;
}