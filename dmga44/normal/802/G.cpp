#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cout.tie(0);
//    freopen(".in","r",stdin);

    string headi = "heidi";
    string S;

    cin >> S;

    int p1 = 0;
    for(int i = 0;i < S.size();i++){
        if(S[i] == headi[p1])
            p1++;
        if(p1 == headi.size()){
            cout << "YES\n";
            return 0;
        }
    }
    cout << "NO\n";

    return 0;
}