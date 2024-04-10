#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    auto q=[&](int w)->int
    {
        cout << "? " << w << endl;
        int h;
        cin >> h;
        return h;
    };
    int l=0,r=4000000+2000;
    while(l<r-1)
    {
        int m=(l+r)/2;
        if(q(m)==1) r=m;
        else l=m;
    }
    int opt=r;
    for(int h=1;h<=n;h++)
    {
        int w=r/h;
        int t=q(w);
        if(t!=0) opt=min(opt,w*t);
    }
    cout << "! " << opt << endl;
    return 0;
}