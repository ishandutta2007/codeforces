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
        vector<int> v[2];
        for(int i=0;i<n;i++)
        {
            int a;
            cin >> a;
            v[a&1].push_back(a);
        }
        for(int i=0;i<2;i++) sort(v[i].begin(),v[i].end());
        int x=0;
        ll a=0;
        ll b=0;
        while(n--)
        {
            if(v[0].empty())
            {
                if(x==1) b+=v[1].back();
                v[1].pop_back();
            }
            else if(v[1].empty())
            {
                if(x==0) a+=v[0].back();
                v[0].pop_back();
            }
            else if(x==0)
            {
                if(v[0].back()>=v[1].back())
                {
                    a+=v[0].back();
                    v[0].pop_back();
                }
                else v[1].pop_back();
            }
            else
            {
                if(v[1].back()>=v[0].back())
                {
                    b+=v[1].back();
                    v[1].pop_back();
                }
                else v[0].pop_back();
            }
            x^=1;
        }
        if(a>b) cout << "Alice\n";
        else if(a<b) cout << "Bob\n";
        else cout << "Tie\n";
    }
    return 0;
}