#include <iostream>
#include <vector>
#include <algorithm>
#include <stdio.h>
#include <sstream>
#include <string>
#include <map>
#include <set>
#include <stdlib.h>
#include <cmath>
#include <math.h>
#include <fstream>
#include <bitset>
#include <time.h>
#include <queue>
#define int long long
using namespace std;
signed main()
{
    string s;
    vector<pair<int, int> > data;
    cin >> s;
    data.push_back(make_pair(0, 0));
    for (int i=1; i<=s.size(); i++){
        if (s[i - 1] == 'a'){
            data.push_back(make_pair(data[i - 1].first + 1, data[i - 1].second));
        }
        else {
            data.push_back(make_pair(data[i - 1].first, data[i - 1].second + 1));
        }
    }
    int ans = 0;
    for (int i=0; i <= s.size(); i++){
        for (int j=0; j <= s.size(); j++){
            int l, r;
            l = min(i, j);
            r = max(i, j);
            ans = max(ans, data[l].first + data[r].second - data[l].second + data[s.size()].first - data[r].first);
        }
    }
    cout << ans << endl;
    return 0;
}