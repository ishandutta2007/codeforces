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
#include <complex>
#define int long long
using namespace std;
int n, ai;
set<pair<int, int> > ms;
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin >> n;
    for (int i=0; i < n; i++){
        cin >> ai;
        pair<int, int> p = make_pair(ai, i);
        ms.insert(p);
    }
    int ost = n;
    int minimum = -1;
    int answer = 0;
    int last = n;
    while (true){
        if (ost == 0) break;
        pair<int, int> p = *ms.begin();
        set<pair<int, int> >::iterator fin = ms.end();
        set<pair<int, int> >::iterator it = ms.upper_bound(make_pair(p.first, minimum));
        if (it != fin && p.first == (*it).first){
            minimum = (*it).second;
            ms.erase(it);
            ost--;
        }
        else{
            answer += last;
            last = ost;
            minimum = -1;
        }
    }
    answer += last;
    cout << answer << endl;
    return 0;
}