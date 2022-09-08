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

const int max_n = 111111, inf = 1000000000;

int n, tp[max_n], x[max_n];
multiset<int> q;
char s[11];
vector<pair<int, int> > ans;

void write(pair<int, int> p) {
    if (p.first == 0) {
        printf("insert %d\n", p.second);
    } else if (p.first == 1) {
        printf("getMin %d\n", p.second);
    } else {
        printf("removeMin\n");
    }
}

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%s", s);
        if (s[0] == 'i') {
            tp[i] = 0;
            scanf("%d", &x[i]);
        } else if (s[0] == 'g') {
            tp[i] = 1;
            scanf("%d", &x[i]);
        } else {
            tp[i] = 2;
        }
    }
    for (int i = 0; i < n; ++i) {
        if (tp[i] == 0) {
            q.insert(x[i]);
        } else if (tp[i] == 2) {
            if (q.size() == 0) {
                ans.push_back(make_pair(0, -inf));
                q.insert(-inf);
            }
        } else {
            int mn = -inf - 1;
            while (q.size()) {
                mn = *q.begin();
                if (mn < x[i]) {
                    ans.push_back(make_pair(2, 0));
                    q.erase(q.find(mn));
                } else {
                    break;
                }
            }
            if (mn != x[i]) {
                q.insert(x[i]);
                ans.push_back(make_pair(0, x[i]));
            }
        }
        ans.push_back(make_pair(tp[i], x[i]));
        if (tp[i] == 2) {
            int mn = *q.begin();
            q.erase(q.find(mn));
        }
    }
    printf("%d\n", ans.size());
    for (int i = 0; i < ans.size(); ++i) {
        write(ans[i]);
    }
    return 0;
}