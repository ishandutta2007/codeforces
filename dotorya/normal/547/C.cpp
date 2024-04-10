//*
#include <stdio.h>
#include <string.h>
#include <limits.h>
#include <queue>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <functional>
#define MOD 1000000007
#pragma warning(disable:4996)
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<double, double> pdd;
typedef set<int>::iterator siit;

int isDivided[500050];
bool prime_chk[500050];
vector <int> prime_list;
void generatePrime() {
    for (int i = 2; i <= 500000; i++) {
        if (prime_chk[i]) continue;
        for (int j = 2 * i; j <= 500000; j += i) prime_chk[j] = true;
    }

    for (int i = 2; i <= 500000; i++) {
        if (prime_chk[i]) continue;
        prime_list.push_back(i);
    }
}

int inpu[200050];
int cnt1[250];
set <int> S;
void count1() {
    for (int i = 0; i <= 200; i++) {
        int t = i;
        while (t != 0) {
            if (t % 2 == 1) cnt1[i]++;
            t /= 2;
        }
        if (cnt1[i] % 2 == 0) cnt1[i] = 1;
        else cnt1[i] = -1;
    }
    return;
}
int main() {
    int N, Q, i, j,k, t, t2;
    generatePrime();
    count1();
    scanf("%d %d", &N, &Q);
    for (i = 1; i <= N; i++) scanf("%d", &inpu[i]);

    ll ANS = 0;
    for (i = 1; i <= Q; i++) {
        int tx = 0;
        scanf("%d", &t);
        t2 = inpu[t];
        vector <int> tpr;
        for (j = 0; prime_list[j] * prime_list[j] <= t2; j++) {
            if (t2 % prime_list[j] != 0) continue;
            tpr.push_back(prime_list[j]);
            while (t2 % prime_list[j] == 0) t2 /= prime_list[j];
        }
        if (t2 != 1) tpr.push_back(t2);

        for (j = 0; j < (1 << tpr.size()); j++) {
            int mul = 1, tmp = j;
            for (k = 0; k < tpr.size(); k++) {
                if (tmp % 2 == 1) mul *= tpr[k];
                tmp /= 2;
            }
            tx += isDivided[mul] * cnt1[j];
        }

        if (S.count(t) == 0) {
            S.insert(t);
            ANS += tx;
            for (j = 1; j*j <= inpu[t]; j++) {
                if (inpu[t] % j != 0) continue;
                isDivided[j]++;
                if (j*j != inpu[t]) isDivided[inpu[t] / j]++;
            }
        }
        else {
            S.erase(t);
            ANS -= tx;
            if (inpu[t] == 1) ANS += 1;
            for (j = 1; j*j <= inpu[t]; j++) {
                if (inpu[t] % j != 0) continue;
                isDivided[j]--;
                if (j*j != inpu[t]) isDivided[inpu[t] / j]--;
            }
        }
        printf("%lld\n", ANS);
    }
    return 0;
}
//*/