#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int MOD = (int)1e6 + 3;

int add(int a, int b)
{
        a += b;
        if(a >= MOD) return a - MOD;
        if(a < 0) return a + MOD;
        return a;
}

int mul(int a, int b)
{
        return a * (ll)b % MOD;
}

int expow(int a, int b)
{
        int r = 1;
        while(b)
        {
                if(b & 1)
                {
                        r = mul(r, a);
                }
                a = mul(a, a);
                b >>= 1;
        }
        return r;
}

int dv(int a, int b)
{
        return mul(a, expow(b, MOD - 2));
}

/// n ecuatii
/// m necunoscute : a(0), ..., a(10)

int A[107][107];
int X[107];

int get(int x)
{
        int res = 0;
        for(int j = 0; j <= 10; j++)
        {
                res = add(res, mul(X[j + 1], expow(x, j)));
        }
        return res;
}

int32_t main()
{
        int n = 49;
        int m = 11; /// : a(1), a(2), a(3) echivalent cu a(0), a(1), a(2)
        for(int i = 1; i <= n; i++)
        {
                cout << "? " << (i - 1) << endl;
                int res;
                cin >> res;
                A[i][m + 1] = res;
                for(int j = 1; j <= m; j++)
                {
                        A[i][j] = expow((i - 1), (j - 1));
                }
        }
        int i = 1, j = 1, k;
        int aux;

        //Algoritmul lui Gauss propriu-zis
        while(i <= n && j <= m)
        {
                //Cautam o linie k pentru care A[k][j] sa fie nenul. Folosim epsilonul pentru a nu lua in considerare micile erori de calcul.
                for(k = i; k <= n; ++k)
                        if(A[k][j] != 0)
                                break;

                //Daca nu gasim linia, necunoscuta j este variabila libera, incrementam pe j si trecem la pasul urmator.
                if(k == n + 1)
                {
                        ++j;
                        continue;
                }

                //Interschimbam pe k cu i, daca este cazul.
                if(k != i)
                        for(int l = 1; l <= m + 1; ++l)
                        {
                                aux = A[i][l];
                                A[i][l] = A[k][l];
                                A[k][l] = aux;
                        }

                //Pentru a usura calculele, impartim toate valorile de pe linia i la A[i][j], A[i][j] devenind 1.
                //Observam ca valorile de pe linia i si coloanele 1..j-1 sunt egale cu 0 de la pasii precedenti ai algoritmului,
                //deci nu e necesar sa le parcurgem pentru a le imparti.
                for(int l = j + 1; l <= m + 1; ++l)
                        A[i][l] = dv(A[i][l], A[i][j]);
                A[i][j] = 1;

                //Scadem din ecuatiile i+1...n ecuatia i inmultita cu A[u][j], pentru a egala toti coeficientii de coloana j
                //a acestor linii la 0.
                for(int u = i + 1; u <= n; ++u)
                {
                        for(int l = j + 1; l <= m + 1; ++l)
                                A[u][l] = add(A[u][l], -mul(A[u][j], A[i][l]));
                        A[u][j] = 0;
                }

                ++i;
                ++j;
        }

        //Calculul necunoscutelor
        for(int i = n; i > 0; --i)
                for(int j = 1; j <= m + 1; ++j)
                        if(A[i][j] != 0)
                        {
                                //Singura valoare nenegativa de pe linia i este rezultatul => sistemul nu are solutie.
                                if(j == m + 1)
                                {
                                        cout << "ERROR\n";
                                        return 0;
                                }

                                //Calculam pe necunoscuta j = rezultatul ecuatiei i - necunoscutele j+1...m inmultite cu coeficientii lor din aceasta ecuatie.
                                X[j] = A[i][m + 1];
                                for(int k = j + 1; k <= m; ++k)
                                        X[j] = add(X[j], -mul(X[k], A[i][k]));
                                break;
                        }
        for(int i = 0; i < MOD; i++)
        {
                if(get(i) == 0)
                {
                        cout << "! " << i << endl;
                        return 0;
                }
        }
        cout << "! -1" << endl;
        return 0;
}