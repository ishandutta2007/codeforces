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
#include <deque>
#define int long long
using namespace std;
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    string s;
    cin >> s;
    set<char> used;
    vector<int> pos;
    for (int i=0; i < s.size(); i++){
        if (s[i] == '*') pos.push_back(i);
        else used.insert(s[i]);
    }
    int m;
    cin >> m;
    vector<string> ss;
    for (int i=0; i < m; i++){
        string s1;
        cin >> s1;
        bool d = true;
        for (int j=0; j < n; j++){
            if (s[j] == '*') continue;
            if (s[j] != s1[j]) d = false;
        }
        if (d) ss.push_back(s1);
    }
    m = ss.size();
    int answer = 0;
    for (char symb='a'; symb <= 'z'; symb++){
        if (used.count(symb)) continue;
        bool can = true;
        for (int i=0; i < m; i++){
            bool th = false;
            for (int j=0; j < pos.size(); j++){
                if (ss[i][pos[j]] == symb) th = true;
                if (used.count(ss[i][pos[j]])) th = true;
            }
            can &= th;
        }
        answer += can;
    }
    cout << answer << endl;
    return 0;
}