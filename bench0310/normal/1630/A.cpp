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
        int n,k;
        cin >> n >> k;
        vector<bool> v(n,0);
        auto add=[&](int a,int b)
        {
            v[a]=v[b]=1;
            cout << a << " " << b << "\n";
        };
        if(k!=n-1)
        {
            add(k,n-1);
            if(k!=0) add(0,n-1-k);
            for(int i=0;i<n;i++) if(!v[i]) add(i,n-1-i);
        }
        else if(n>=8)
        {
            vector<int> x,y;
            for(int i=0;(1<<i)<n;i++)
            {
                x.push_back((1<<i));
                y.push_back(n-1-(1<<i));
            }
            int m=x.size();
            for(int i=0;i<m;i++) add(x[i],y[(i+1)%m]);
            for(int i=0;i<n;i++) if(!v[i]) add(i,n-1-i);
        }
        else cout << "-1\n";
    }
    return 0;
}