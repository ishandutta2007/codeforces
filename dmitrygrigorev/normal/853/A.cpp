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
#define int long long
using namespace std;
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("1.txt", "r", stdin);
    int n, k;
    cin >> n >> k;
    vector<int> data(n), ans(n);
    for (int i=0; i < n; i++){
        cin >> data[i];
    }
    vector<pair<int, int> > ss;
    set<int> has;
    for (int i=0; i < n; i++){
        has.insert(i+k);
        ss.push_back(make_pair(data[i], i));
    }
    sort(ss.begin(), ss.end(), greater<pair<int, int> >());
    int answer = 0;
    for (int i=0; i < n; i++){
        int element = ss[i].second;
        set<int>::iterator next = has.upper_bound(element-1);
        int number = *next;
        ans[element] = number+1;
        answer += ss[i].first * abs(element - number);
        has.erase(next);
    }
    cout << answer << endl;
    for (int i=0; i < n; i++){
        cout << ans[i] << " ";
    }
    return 0;
}