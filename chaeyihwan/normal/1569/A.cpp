#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin >> t;
    while(t--){
        int n; cin >> n;
        string s; cin >> s;
        bool flag = true;
        for(int i=0;i<n-1;i++)
        {
            if(s[i] != s[i+1])
            {
                cout << i+1 << " " << i+2 << "\n";
                flag = false;
                break;
            }
        }
        if(flag) cout << "-1 -1\n";
    }
}