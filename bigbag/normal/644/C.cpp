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

int n;
string s;
char a[55];
map<string, int> m;
vector<string> q;
pair<vector<string>, string> v[max_n];
vector<vector<string> > ans;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    scanf("%d", &n);
    int cnt = 0;
    for (int i = 0; i < n; ++i) {
        scanf("%s", a);
        s = a + 7;
        int poz = s.find('/');
        string pr = s;
        if (poz != -1) {
            pr = s.substr(0, poz);
        }
        if (!m.count(pr)) {
            m[pr] = cnt;
            ++cnt;
        }
        int num = m[pr];
        string q = "";
        if (poz != -1) {
            q = s.substr(poz);
        }
        v[num].first.push_back(q);
        v[num].second = pr;
    }
    for (int i = 0; i < cnt; ++i) {
        sort(v[i].first.begin(), v[i].first.end());
        v[i].first.erase(unique(v[i].first.begin(), v[i].first.end()), v[i].first.end());
        /*cout << t[i] << " : ";
        for (int j = 0; j < v[i].size(); ++j) {
            cout << "[" << v[i][j] << "] ";
        }
        cout << endl;*/
    }
    sort(v, v + cnt);
    for (int i = 0; i < cnt; ) {
        int poz = i;
        while (i < cnt && v[poz].first == v[i].first) {
            ++i;
        }
        if (poz + 1 < i) {
            q.clear();
            for (int j = poz; j < i; ++j) {
                q.push_back(v[j].second);
            }
            ans.push_back(q);
        }
    }
    printf("%d\n", ans.size());
    for (int i = 0; i < ans.size(); ++i) {
        for (int j = 0; j < ans[i].size(); ++j) {
            printf("http://%s ", ans[i][j].c_str());
        }
        printf("\n");
    }
    return 0;
}