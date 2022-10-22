#include <bits/stdc++.h>
#define int long long
#define ld long double
#define y1 sdopgh

using namespace std;

int n;
string s;

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> s;
    
    int k = 0;
    
    for(auto to:s)
    {
        if(to == 'D')
            k++;
        else k--;
    }
    
    if(k > 0)
        cout << "Danik";
    else if(k < 0)
        cout << "Anton";
    else cout << "Friendship";
}