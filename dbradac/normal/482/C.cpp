#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

typedef long long ll;

int n, l, kolkoraz[1<<20];
ll kojiraz[1<<20];
char s[51][25];
double dp[1<<20];

double Rek(int st)
{
    int i, ostalo=0, nst;
    double rez=0, jedan;

    if (dp[st] > -0.5)
        return dp[st];

    if (kolkoraz[st] < 2)
        return 0;

    for (i=0; i<l; i++)
        if (!((1<<i) & st))
            ostalo++;
    jedan = 1 / (double) ostalo;

    rez = 1.0;

    for (i=0; i<l; i++)
        if (!((1<<i) & st)) {
            nst = st | (1<<i);
            rez += jedan * Rek(nst) * (double) kolkoraz[nst] / kolkoraz[st];
        }

    return dp[st] = rez;
}


int main()
{
    int i, j, k, novi;
    ll tmp;

    scanf("%d", &n);

    for (i=0; i<n; i++)
        scanf("%s", s[i]);
    l = strlen(s[0]);

    for (i=0; i<(1<<l); i++)
        dp[i] = -1;

    for (i=0; i<n; i++)
        for (j=i+1; j<n; j++) {
            for (k=tmp=0; k<l; k++)
                if (s[i][k] == s[j][k])
                    tmp |= 1<<k;
            kojiraz[tmp] |= ((ll)1<<i) | ((ll)1<<j);
        }

    for (i=(1<<l)-1; i>=0; i--) {
        tmp = kojiraz[i];
        for (j=0; j<n; j++)
            if (((ll)1<<j) & tmp)
                kolkoraz[i]++;
        for (j=0; j<20; j++) {
            if ((1<<j) & i) {
                novi = i ^ (1<<j);
                kojiraz[novi] |= tmp;
            }
        }
    }

    printf("%.11lf\n", Rek(0));


    return 0;
}