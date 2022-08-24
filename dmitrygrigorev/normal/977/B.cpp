#include <bits/stdc++.h>
#define int long long
using namespace std;
signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    string s;
    cin >> s;
    map<string, int> mm;
    for (int i=1; i < s.size(); i++){
        string p = "";
        p += s[i-1];
        p += s[i];
        mm[p]++;
    }
    string x = "";
    int res=0;
    for (int i=1; i < s.size(); i++){
        string p = "";
        p += s[i-1];
        p += s[i];
        if (mm[p] > res){
            res = mm[p];
            x = p;
        }
    }
    cout << x;
    return 0;
}


/*

1
6 6
3 6
3 4
1 4
1 2
1 3
2 3

*/