#include <bits/stdc++.h>
using namespace std;

int main(){
    // freopen("a.in", "r", stdin);
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        string s; cin >> s;
        if((int)s.size()==1 || s[0]==s[1]){
            cout << string(2, s[0]) << '\n';
            continue;
        }
        int len = 0;
        while(len<n && (len==0 || s[len]<=s[len-1])) 
            ++len;
        string sub = "";
        for(int i = 0; i<len; ++i)
            sub += s[i];
        string rsub = sub;
        reverse(rsub.begin(), rsub.end());
        cout << sub+rsub << '\n';
    }
}