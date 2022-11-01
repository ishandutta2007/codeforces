#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,k;
    cin >> n >> k;
    if((n&1)&&!(k&1))
    {
        cout << "-1\n";
        cout.flush();
        return 0;
    }
    auto ok=[&](int d)->bool
    {
        if((n&1)!=((k*d)&1)) return 0;
        int mx=1+2*(((k*d-n)/2+n-1)/n);
        return (mx<=d);
    };
    int d=(n+k-1)/k;
    while(ok(d)==0) d++;
    vector<int> c(n+1,1);
    int x=k*d-n;
    while(x>0)
    {
        for(int i=1;i<=n;i++)
        {
            if(x>0)
            {
                c[i]+=2;
                x-=2;
            }
        }
    }
    vector<int> queries[d];
    int q=0;
    for(int i=1;i<=n;i++)
    {
        assert(c[i]<=d);
        for(int j=0;j<c[i];j++)
        {
            queries[q].push_back(i);
            q=(q+1)%d;
        }
    }
    int res=0;
    for(int i=0;i<d;i++)
    {
        cout << "? ";
        for(int j=0;j<k;j++) cout << queries[i][j] << " \n"[j==k-1];
        cout.flush();
        int r;
        cin >> r;
        res^=r;
    }
    cout << "! " << res << "\n";
    cout.flush();
    return 0;
}