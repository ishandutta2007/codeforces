#include <bits/stdc++.h>
#define int long long
#define y1 dwihweoighweoi
#define ld long double

using namespace std;

int x;
vector <int> v;

int f(int x)
{
    int k=0;
    while(x>1)
    {
        k++;
        x=x/2;
    }
    return k+1;
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> x;
    while(x!=1)
    {
        v.push_back(f(x));
        x^=(1ll << f(x))-1;
        x++;
        if(f(x)!=f(x-1))
        {
            v.push_back(0);
            x++;
        }
    }
    cout << 2*v.size() << "\n";
    for(auto to:v)
        cout << to << ' ';
}