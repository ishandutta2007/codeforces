#include <bits/stdc++.h>

using namespace std;

const int N = (int) 5e5 + 7;
int n, a[N], f[N], dp[N], peSufixDiferite[N], primul[N], ultimul[N];

int main() {
        ios::sync_with_stdio(0); cin.tie(0);

       /// freopen ("input", "r", stdin);

        /**
        Exista trei categorii de numere
        (1) numere pt care fiecare "reprezentant" al lor ramane nemiscat
        (2) numere pt care fiecare "reprezentant" al lor ramane se misca
        (3) numere pt care un prefix al "reprezentantiolr" lor se misca si un sufix ramane nemiscat
        exista maxim un numar din categoria 3 deoarece fiecare numar din catergoria 3 are restrictia
        ca trebuie sa fie primul mutat
        deci avem doar o(n) posibile solutii
        cand suntem la i : stergem fiecare element de dupa el care nu este egal cu el si pastram un nr maxim
        de numere de pe prefixul [1..i] cu proprietatea ca st1<=dr1<=st2<=dr2<=...<=stk<=drk
        !! atentie i poate sa fie si 0 caz in care mut tot de dupa el adica costul ar fi n
        !! mai exact, i ia valorile {0...n}
        **/

        cin >> n;
        for (int i = 1; i <= n; i++) {
                cin >> a[i];
                ultimul[a[i]] = i;
                if (!primul[a[i]])
                        primul[a[i]] = i;
        }
        for (int i = n; i >= 1; i--) {
                f[a[i]]++;
                peSufixDiferite[i] = n - i + 1 - f[a[i]];
        }
        int ret = n;
        for (int i = 1; i <= n; i++) {
                dp[i] = dp[i - 1];
                if (ultimul[a[i]] == i)
                        dp[i] = max(dp[i], dp[primul[a[i]] - 1] + f[a[i]]);
                int cost;
                cost = i - dp[i] + peSufixDiferite[i + 1];
                ret = min(ret, cost);
        }
        cout << ret << "\n";


}