#include <cstdio>
#include <algorithm>

using namespace std;

typedef long long ll;

const int H1 = 1000000007, H2 = 1000000009, H3 = 1000000021;
const int MAX = 1<<18;
ll MOD = 2147481754;

int vel[MAX], mal[MAX], h1[MAX], h2[MAX], h3[MAX], pot1, pot2, pot3, hash1, hash2, hash3;

int main()
{
    int i, lvel, lmal, rez=0;

    scanf("%d%d", &lvel, &lmal);

    for (i=1; i<=lvel; i++) {
        scanf("%d", &vel[i]);
        h1[i] = ((ll) h1[i-1] * H1 + vel[i] - vel[i-1] + MOD) % MOD;
        h2[i] = ((ll) h2[i-1] * H2 + vel[i] - vel[i-1] + MOD) % MOD;
        h3[i] = ((ll) h3[i-1] * H3 + vel[i] - vel[i-1] + MOD) % MOD;
    }

    for (i=1; i<=lmal; i++) {
        scanf("%d", &mal[i]);
        if (i > 1) {
            hash1 = ((ll) hash1 * H1 + mal[i] - mal[i-1] + MOD) % MOD;
            hash2 = ((ll) hash2 * H2 + mal[i] - mal[i-1] + MOD) % MOD;
            hash3 = ((ll) hash3 * H3 + mal[i] - mal[i-1] + MOD) % MOD;
        }
    }
    lmal--;

    pot1 = 1;
    for (i=0; i<lmal; i++)
        pot1 = ((ll) pot1 * H1) % MOD;

    pot2 = 1;
    for (i=0; i<lmal; i++)
        pot2 = ((ll) pot2 * H2) % MOD;

    pot3 = 1;
    for (i=0; i<lmal; i++)
        pot3 = ((ll) pot3 * H3) % MOD;

    if (!lmal) {
        printf("%d\n", lvel);
        return 0;
    }

    for (i=2; i+lmal-1<=lvel; i++) {
        if ((((h1[i+lmal-1] - (ll) h1[i-1] * pot1) % MOD) + MOD) % MOD == hash1)// &&
            /*(((h2[i+lmal-1] - (ll) h2[i-1] * pot2) % MOD) + MOD) % MOD == hash2 &&
            (((h3[i+lmal-1] - (ll) h3[i-1] * pot3) % MOD) + MOD) % MOD == hash3)*/
            rez++;
    }

    printf("%d\n", rez);

    return 0;
}