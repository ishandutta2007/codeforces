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
#include <cassert>
#include <cstdio>
#define int long long
using namespace std;
signed main()
{
    ios_base::sync_with_stdio(false);
    int n;
    set<string> ss;
    cin >> n;
    for (int i=0; i < n; i++){
        string s;
        cin >> s;
        if (!ss.count(s)){
            cout << "NO" << endl;
        }
        else cout << "YES" << endl;
        ss.insert(s);
    }
    return 0;
}