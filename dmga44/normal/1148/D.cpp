#include <bits/stdc++.h>
#define db(x) cout << (x) << '\n';
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define MAXN 300005

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n,a,b;
    cin >> n;
    vector<pii> t1,t2;
    for(int i=0;i<n;i++)
    {
        cin >> a >> b;
        if(a>b)
            t1.push_back(pii(a,i));
        else
            t2.push_back(pii(b,i));
    }

    sort(t2.rbegin(),t2.rend());
    sort(t1.begin(),t1.end());

    if(t2.size()>t1.size())
    {
        db(t2.size())
        for(auto y : t2)
            cout << y.second+1 << ' ';
    }
    else
    {
        db(t1.size())
        for(auto y : t1)
            cout << y.second+1 << ' ';
    }

    return 0;
}