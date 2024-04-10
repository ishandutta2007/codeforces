#include <cstdio>
#include <algorithm>
#include <functional>
#include <set>

using namespace std;

char s[10];
int snaga1[105], snaga2[105], poz[105], uk[105], atk[105];

multiset <int> S;

int main()
{
    int n1, n2, i, j, ne, rez=0, tmp, bratk=0;
    multiset <int> :: iterator it;

    scanf("%d%d", &n2, &n1);

    for (i=0; i<n2; i++) {
        scanf("%s%d", s, &snaga2[i]);
        if (s[0] == 'A') {
            poz[i] = 1;
            atk[bratk++] = snaga2[i];
        }
        uk[i] = snaga2[i] + poz[i];
    }

    for (i=0; i<n1; i++)
        scanf("%d", &snaga1[i]);

    sort(snaga1, snaga1 + n1, greater<int>());
    sort(uk, uk+n2, greater<int>());

    for (i=0; i<n1; i++)
        S.insert(snaga1[i]);

    ne = 0;
    for (i=0; i<n2; i++) {
        if (!poz[i]) {
            it = S.lower_bound(snaga2[i] + 1);
            if (it == S.end()) {
                ne = 1;
                break;
            }
            else {
                S.erase(it);
            }
        }
    }

    tmp = 0;
    if (!ne) {
        for (i=0; i<n2; i++) {
            if (poz[i]) {
                it = S.lower_bound(snaga2[i]);
                if (it == S.end()) {
                    ne = 1;
                    break;
                }
                else {
                    tmp += *it - snaga2[i];
                    S.erase(it);
                }
            }
        }

        if (!ne) {
            for (; S.size(); ) {
                tmp += *S.begin();
                S.erase(S.begin());
            }
            rez = tmp;
        }
    }

    sort(atk, atk+bratk);

    for (i=1; i<=bratk; i++) {
        if (atk[i-1] < snaga1[i-1]) {
            for (j=tmp=0; j<i; j++)
                tmp += snaga1[j] - atk[j];
            rez = max(rez, tmp);
        }
    }

    printf("%d\n", rez);

    return 0;
}