/*  * In the name of GOD 
    * Thanks God */
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second
const int N = 111;
string s[N];

int32_t main(){
    set <int> vo = {'A', 'E', 'I', 'O', 'U', 'Y', 'a', 'e', 'i', 'o', 'u', 'y'};
    int i = 0;
    while (cin >> s[i])
        i++;
    char lst;
    if (s[i - 1] == "?")
        lst = s[i - 2][s[i - 2].size() - 1];
    else
        lst = s[i - 1][s[i - 1].size() - 2];
    //cout << lst;
    if (vo.count(lst)) {
        cout << "YES";
    }else {
        cout << "NO";
    }
}