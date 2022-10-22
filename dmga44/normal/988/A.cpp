#include <bits/stdc++.h>
#define db(x) cout << (x) << '\n';
using namespace std;
typedef long long ll;

map<int,int> m;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n,k,xi;
    cin >> n >> k;
    for(int i=0;i<n;i++)
    {
        cin >> xi;
        m[xi]=i;
    }

    if(m.size()>=k)
    {
        db("YES")
        auto it=m.begin();
        for(int i=0;i<k;i++,it++)
            cout << (*it).second+1 << ' ';
    }
    else
        db("NO")

    return 0;
}