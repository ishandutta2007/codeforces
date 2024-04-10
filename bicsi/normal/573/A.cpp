#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> Pair;

unordered_set<int> Set;

int main() {
    #ifndef ONLINE_JUDGE
    freopen("debug.in", "r", stdin);
    #endif // ONLINE_JUDGE

    int n, a;
    cin>>n;

    for(int i=1; i<=n; i++) {
        cin>>a;
        while(a % 2 == 0) a /= 2;
        while(a % 3 == 0) a /= 3;

        Set.insert(a);
    }

    if(Set.size() == 1) cout << "Yes";
    else cout << "No";



    return 0;
}