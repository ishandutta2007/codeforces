#include <bits/stdc++.h>

using namespace std;


int main() {
  ///freopen ("___input___.txt", "r", stdin);
  int n, k, l, c, d, p, nl, np;
  cin >> n >> k >> l >> c >> d >> p >> nl >> np;

  int maxnr;

  maxnr = min((k * l) / nl, min((c * d), p / np));
  maxnr = maxnr / n;
  cout << maxnr << "\n";
}

/**
-----------
* n prieteni
* k sticle (nu k sticle fiecare, in total k sticle)
* fiecare sticla are l litri de bautura
* au c lamai (nu k sticle fiecare, in total k sticle)
* fiecare lamaie (din alea c) este impartita in d bucati
* p grame de sare
-----------
* ca sa sa faca un toast au nevoie de :
    a) nl litri de bautura
    b) o lamaie
    c) np grame de sare

* vor sa bea fiecare ac. nr de toast-uri si vor ca
acel nr sa fie maxim

7 toast-uri in total
3 prieteni

* nr de toast-uri pe care le bea fiecare = nr de toast-uri total / n
**/