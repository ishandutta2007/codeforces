#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>

using namespace std;

multiset<int> s;
vector<int> ans;

int gcd(int a, int b) {
    if(b == 0) return a;
    return gcd(b, a%b);
}

int main() {
  // freopen("1.in", "r", stdin);

    int n;
    cin >>n;
    for(int i = 0; i < n*n; ++i) {
        int a;
        cin >> a;
        s.insert(a);
    }

    while(!s.empty()) {
        int k = *s.rbegin();
        s.erase(s.find(k));
        for(int i = 0; i < ans.size(); ++i) {
            int g = gcd(k, ans[i]);
            s.erase(s.find(g));
            s.erase(s.find(g));
        }
        ans.push_back(k);
    }

    for(int i = 0; i < ans.size(); ++i) {
        cout << ans[i];
        if(i == ans.size()-1) cout << "\n";
        else cout << " ";
    }

  return 0;
}