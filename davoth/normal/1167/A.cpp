#include <bits/stdc++.h>
using namespace std;
int main() {
    int t;
    cin >> t;
    vector<string> a;
    for(int i=0; i<t; i++){
        int n;
        string s;
        cin >> n >> s;
        n-=11;
        int c=0;
        for(int j=0; j<=n; j++){
            if(s[j]=='8'){
                a.push_back("YES\n");
                c=1;
                break;
            }
        }
        if(c==0) a.push_back("NO\n");
    }
    for(int i=0; i<t; i++){
        cout << a[i];
    }
    return 0;
}