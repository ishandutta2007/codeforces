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

bool r[55], c[55];

vector<int> ans;

int main() {
  // freopen("1.in", "r", stdin);

    int n;
    cin >>n;
    fill(r, r+n, 0);
    fill(c, c+n, 0);
    for(int i = 0; i < n*n; ++i) {
        int h, v;
        cin >> h >> v;
        if(!r[h] && !c[v]) {
                ans.push_back(i+1);
                r[h] = c[v] = 1;
        }
    }

    for(int i = 0; i < ans.size(); ++i){
        cout << ans[i];
    if(i != ans.size()-1) cout << " ";
    else cout << "\n";
}

  return 0;
}