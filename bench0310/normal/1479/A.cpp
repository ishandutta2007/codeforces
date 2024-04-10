#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    vector<int> val(n+2,-1);
    val[0]=val[n+1]=n+1;
    auto q=[&](int x)->int
    {
        if(val[x]!=-1) return val[x];
        cout << "? " << x << "\n";
        cout.flush();
        cin >> val[x];
        return val[x];
    };
    auto ch=[&](int x)->int
    {
        if(q(x-1)>q(x)&&q(x)<q(x+1))
        {
            cout << "! " << x << "\n";
            cout.flush();
            exit(0);
        }
        if(q(x-1)>q(x)&&q(x)>q(x+1)) return -1;
        else return 1;
    };
    int l=1,r=n;
    ch(l);
    ch(r);
    while(l<r-1)
    {
        int m=(l+r)/2;
        int t=ch(m);
        if(t==-1) l=m;
        else r=m;
    }
    return 0;
}