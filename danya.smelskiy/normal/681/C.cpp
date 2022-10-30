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
vector<pair<string,int> > v;

int main(int argc, const char * argv[]) {
//    freopen("/Users/danya.smelskiy/Documents/Danya/Resources/input.txt","r",stdin);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n;
    multiset<int> ss;
    int x;
    for (int i = 1; i <= n; ++i) {
        string s;
        cin >> s;
        if (s[0] == 'r') {
            if (ss.size() == 0) {
                v.push_back({"insert ", -1e9});
                v.push_back({"removeMin", 0});
            } else {
                ss.erase(ss.begin());
                v.push_back({"removeMin", 0});
            }
        } else if (s[0] == 'i') {
            cin >> x;
            ss.insert(x);
            v.push_back({"insert", x});
        } else {
            cin >> x;
            while (!ss.empty()) {
                int y = *ss.begin();
                if (y < x) {
                    v.push_back({"removeMin", 0});
                    ss.erase(ss.begin());
                } else break;
            }
            if (ss.empty() || *ss.begin() != x) {
                ss.insert(x);
                v.push_back({"insert", x});
            }
            v.push_back({"getMin", x});
        }
    }
    cout << v.size() << '\n';
    for (int i = 0; i < v.size(); ++i) {
        cout << v[i].first;
        if (v[i].first[0] != 'r') cout << " " << v[i].second;
        cout << '\n';
    }
}