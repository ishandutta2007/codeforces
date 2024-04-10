#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int z;
    cin >> z;
    while(z--)
    {
        int n;
        cin >> n;
        auto q=[&](int t,int i,int j,int x)->int
        {
            cout << "? " << t << " " << i << " " << j << " " << x << "\n";
            cout.flush();
            int r;
            cin >> r;
            if(r==-1) exit(0);
            return r;
        };
        int m12=max(q(1,1,2,n-1),q(1,2,1,n-1));
        int m13=max(q(1,1,3,n-1),q(1,3,1,n-1));
        int m23=max(q(1,2,3,n-1),q(1,3,2,n-1));
        vector<int> res(n+1,0);
        int s=0;
        if(m12==m13) s=1;
        else if(m12==m23) s=2;
        else s=3;
        res[s]=max({m12,m13,m23});
        int a=res[s];
        auto solve_bigger=[&]()
        {
            for(int j=1;j<=n;j++)
            {
                if(j==s||res[j]!=0) continue;
                int t=q(1,s,j,n-1);
                if(t>a) res[j]=t;
            }
        };
        auto solve_smaller=[&]()
        {
            for(int i=1;i<=n;i++)
            {
                if(i==s||res[i]!=0) continue;
                int t=q(2,i,s,1);
                if(t<a) res[i]=t;
            }
        };
        if(a<=n/2)
        {
            solve_bigger();
            solve_smaller();
        }
        else
        {
            solve_smaller();
            solve_bigger();
        }
        cout << "!";
        for(int i=1;i<=n;i++) cout << " " << res[i];
        cout << "\n";
        cout.flush();
    }
    return 0;
}