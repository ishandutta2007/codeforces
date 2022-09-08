#include <map>
#include <set>
#include <stack>
#include <cmath>
#include <queue>
#include <vector>
#include <cstdio>
#include <string>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <algorithm>

using namespace std;

const int max_n = 111111, inf = 1111111111;

const int max_p = 111111;

int used[max_p];
vector<int> P;

void get_all_primes() {
    for (int i = 2; i < max_p; ++i) {
        if (used[i] == 0) {
            P.push_back(i);
            if (((long long) i) * i < max_p) {
                for (int j = i * i; j < max_p; j += i) {
                    used[j] = 1;
                }
            }
        }
    }
}

int n, pozs[max_n], pozs2[max_n];
vector<pair<int, int> > v, ans;

void my_swap(int p1, int p2) {
    swap(pozs[pozs2[p1]], pozs[pozs2[p2]]);
    swap(pozs2[p1], pozs2[p2]);
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    get_all_primes();
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
        pozs[i] = i;
        pozs2[i] = i;
        int x;
        scanf("%d", &x);
        v.push_back(make_pair(x, i));
    }
    sort(v.begin(), v.end());
    for (int i = 1; i <= n; ++i) {
        int poz = pozs[v[i - 1].second];
        /*cout << i << ' ' << poz << " : " << endl;
        for (int j = 1; j <= n; ++j) {
            cout << pozs[j] << ' ';
        }
        cout << endl;*/
        while (poz != i) {
            //cout << poz << endl;
            vector<int>::iterator it = upper_bound(P.begin(), P.end(), poz - i + 1);
            --it;
            int np = poz - *it + 1;
            //ans.push_back(make_pair(min(pozs2[poz], pozs2[np]), max(pozs2[poz], pozs2[np])));
            ans.push_back(make_pair(min(poz, np), max(poz, np)));
            my_swap(poz, np);
            poz = np;
        }
    }
    printf("%d\n", ans.size());
    for (int i = 0; i < ans.size(); ++i) {
        printf("%d %d\n", ans[i].first, ans[i].second);
    }
    return 0;
}