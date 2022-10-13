#include <bits/stdc++.h>

using namespace std;
typedef int var;

int main() {
    #ifndef ONLINE_JUDGE
    freopen("debug.in", "r", stdin);
    freopen("debug.out", "w", stdout);
    #endif // ONLINE_JUDGE


    var n;
    cin>>n;
    char c;

    stack<char> S;

    for(var i=1; i<=n; i++) {
        cin>>c;
        if(S.size() && S.top() != c) S.pop();
        else S.push(c);
    }

    cout<<S.size();
    return 0;
}