#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
#include <queue>
   
#include <cassert>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <bitset>
using namespace std;
  
typedef long long ll;

bool only_with_automation(string s1, string s2)
{
    swap(s1, s2);
    for (int i = 0, j = 0; i < (int) s1.length(); ++i) {
        while (j < (int) s2.length() && s2[j] != s1[i]) ++j;
        if (j >= (int) s2.length()) return false;
        ++j;
    }
    return true;
}

bool only_with_array(string s1, string s2)
{
    if (s1.length() != s2.length()) return false;
    int c1[26];
    int c2[26];
    for (int i = 0; i < 26; ++i) c1[i] = c2[i] = 0;
    for (int i = 0; i < (int) s1.length(); ++i) ++c1[s1[i] - 'a'];
    for (int i = 0; i < (int) s2.length(); ++i) ++c2[s2[i] - 'a'];
    for (int i = 0; i < 26; ++i)
        if (c1[i] != c2[i])
            return false;
    return true;
}


bool with_both(string s1, string s2)
{
    int c1[26];
    int c2[26];
    for (int i = 0; i < 26; ++i) c1[i] = c2[i] = 0;
    for (int i = 0; i < (int) s1.length(); ++i) ++c1[s1[i] - 'a'];
    for (int i = 0; i < (int) s2.length(); ++i) ++c2[s2[i] - 'a'];
    for (int i = 0; i < 26; ++i)
        if (c1[i] < c2[i])
            return false;
    return true;
}

int main()
{
  //  freopen("input.txt", "r", stdin);
   // freopen("output.txt", "w", stdout);

    string s1, s2;
    
    cin >> s1 >> s2;
    
    if (only_with_automation(s1, s2)) {
        cout << "automaton" << endl;
        return 0;
    }
    
    if (only_with_array(s1, s2)) {
        cout << "array" << endl;
        return 0;
    }
    
    if (with_both(s1, s2)) {
        cout << "both" << endl;
        return 0;
    }
    
    cout << "need tree" << endl;

    return 0;
}