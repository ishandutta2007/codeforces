#include <bits/stdc++.h>
#define db(x) cout << (x) << '\n';
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int x;
    cin >> x;
    if(!x)
    {
        db(0)
        return 0;
    }
    int res=0;
    vector<int> r;
    while(((x+1)&(-(x+1)))!=(x+1))
    {
        if(res&1)
            x++;
        else
        {
            int p=0;
            while((1<<p)<=x)
                p++;
            x=(x^((1<<p)-1));
            r.push_back(p);
        }
        res++;
    }

    db(res)
    for(auto y : r)
        cout << y << ' ';

    return 0;
}