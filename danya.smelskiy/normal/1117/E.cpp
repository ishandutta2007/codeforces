# include <iostream>
# include <cmath>
# include <algorithm>
# include <stdio.h>
# include <cstdint>
# include <cstring>
# include <string>
# include <cstdlib>
# include <vector>
# include <bitset>
# include <map>
# include <queue>
# include <ctime>
# include <stack>
# include <set>
# include <list>
# include <random>
# include <deque>
# include <functional>
# include <iomanip>
# include <sstream>
# include <fstream>
# include <complex>
# include <numeric>
# include <immintrin.h>
# include <cassert>
# include <array>
# include <tuple>
# include <unordered_set>
# include <unordered_map>
using namespace std;


int n;
string s;
vector<int> gg1[100], gg2[100];

vector<pair<vector<int>, vector<int> > > solve(vector<pair<vector<int>, vector<int> > > v) {
    string z = "";
    for (int i = 0; i < n; ++i)
        z += "a";
    for (int i = 0; i < v.size(); ++i) {
        vector<int> v1 = v[i].first, v2 = v[i].second;
        int gr = (int)v1.size();
        gr = (gr + 26 - 1) / 26;
        int last = 0;
        for (int j = 0; j < v1.size(); ++j) {
            z[v1[j]] = char(last + 'a');
            if ((j + 1) % gr == 0) ++last;
        }
    }
    cout << "? " << z << endl;
    string zz;
    cin >> zz;
    vector<pair<vector<int>, vector<int> > > res;
    for (int i = 0; i < v.size(); ++i) {
        vector<int> v1 = v[i].first, v2 = v[i].second;
        vector<pair<char, int> > v3;
        for (int j = 0; j < 26; ++j) {
            gg1[j].clear();
            gg2[j].clear();
        }
        for (int j = 0; j < v2.size(); ++j) {
            int x = v2[j];
            gg2[zz[x] - 'a'].push_back(x);
        }
        int gr = (int)v1.size();
        gr = (gr + 25) / 26;
        int last = 0;
        for (int j = 0; j < v1.size(); ++j) {
            gg1[last].push_back(v1[j]);
            if ((j + 1) % gr == 0) ++last;
        }
        for (int j = 0; j < 26; ++j) if (gg1[j].size() > 0)
            res.push_back({gg1[j], gg2[j]});
    }
    return res;
}

int main(int argc, const char * argv[]) {
//    freopen("/Users/danya.smelskiy/Documents/Danya/Resources/input.txt","r",stdin);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> s;
    n = (int)s.size();
    vector<pair<vector<int>, vector<int> > > iv;
    vector<int> v1, v2;
    for (int i = 0; i < n; ++i) {
        v1.push_back(i);
    }
    v2 = v1;
    iv.push_back(make_pair(v1, v2));
    iv = solve(iv);
    iv = solve(iv);
    iv = solve(iv);
    string ans = s;
    for (int i = 0; i < iv.size(); ++i) {
        v1 = iv[i].first;
        v2 = iv[i].second;
        int x = v1[0];
        int y = v2[0];
        ans[x] = s[y];
    }
    cout << "! " << ans << endl;
}