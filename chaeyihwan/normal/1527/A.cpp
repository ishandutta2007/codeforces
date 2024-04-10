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
        int M = 0;
        for(int i=0;i<31;i++)
        {
            if((1<<i) & n)
            {
                M = i;
            }
        }

        cout << (1<<M) - 1 << "\n";
    }
}