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
        string a,b;
        cin >> a >> b;
        int res=[&]()
        {
            vector<int> v(20);
            for(int i=0;i<n;i++)
            {
                if(a[i]>b[i]) return -1;
                if(a[i]<b[i]) v[a[i]-'a']|=(1<<(b[i]-'a'));
            }
            int c=0;
            for(int i=0;i<20;i++)
            {
                if(v[i]>0)
                {
                    c++;
                    int p=countr_zero(uint32_t(v[i]));
                    v[p]|=(v[i]^(1<<p));
                }
            }
            return c;
        }();
        cout << res << "\n";
    }
    return 0;
}