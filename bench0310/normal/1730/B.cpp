#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--)
    {
        int n;
        cin >> n;
        vector<array<int,2>> v(n);
        for(int j=0;j<2;j++) for(int i=0;i<n;i++) {cin >> v[i][j]; v[i][j]*=2;}
        ranges::sort(v);
        vector<int> l(n,0);
        for(int i=0;i<n;i++) l[i]=max((i>0?l[i-1]:-(1<<30)),v[i][1]-v[i][0]);
        vector<int> r(n,0);
        for(int i=n-1;i>=0;i--) r[i]=max((i+1<n?r[i+1]:0),v[i][1]+v[i][0]);
        array<int,2> res={(1<<30),0};
        if(n==1) res={v[0][1],v[0][0]};
        for(int i=0;i+1<n;i++)
        {
            int x=(r[i+1]-l[i])/2;
            x=max(x,v[i][0]);
            x=min(x,v[i+1][0]);
            res=min(res,{max(l[i]+x,r[i+1]-x),x});
        }
        cout << res[1]/2;
        if(res[1]&1) cout << ".5";
        cout << "\n";
    }
    return 0;
}