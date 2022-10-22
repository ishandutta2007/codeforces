#include <bits/stdc++.h>
#define int long long
#define ld long double
#define y1 sdopgh

using namespace std;

int p, k;
vector <int> v;

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> p >> k;
    int y=0;
    while(p)
    {
        y^=1;
        int c=p%k;
        int x=(k-c)%k;
        if(y)
            x=-c;

        v.push_back(abs(x));
        p+=x;
        p/=k;
    }
    cout << v.size() << endl;
    for(auto to:v)
        cout << to << ' ';
}