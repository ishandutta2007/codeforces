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
int x;
vector<int> v, v1, v2;


int main(int argc, const char * argv[]) {
//    freopen("/Users/danya.smelskiy/Documents/Danya/Resources/input.txt","r",stdin);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> x;
        v.push_back(x);
    }
    sort(v.begin(), v.end());
    for (int i = 2; i < (int)v.size(); ++i)
        if (v[i] == v[i - 2]) {
            cout << "NO\n";
            return 0;
        }
    for (int i = 0; i < (int)v.size(); ++i)
        if (i & 1) v1.push_back(v[i]);
        else v2.push_back(v[i]);
    reverse(v2.begin(), v2.end());
    cout << "YES\n";
    cout << (int)v1.size() << '\n';
    for (int i = 0; i < (int)v1.size(); ++i)
        cout << v1[i] << " ";
    cout << '\n';
    cout << (int)v2.size() << '\n';
    for (int i = 0; i < (int)v2.size(); ++i)
        cout << v2[i] << " ";
    cout << '\n';
    
    
}