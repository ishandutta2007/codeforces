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
        int n,x,y;
        cin >> n >> x >> y;
        string a,b;
        cin >> a >> b;
        int c=0;
        vector<int> v;
        for(int i=0;i<n;i++)
        {
            if(b[i]=='1') a[i]^=('0'^'1');
            if(a[i]=='1')
            {
                c++;
                v.push_back(i);
            }
        }
        if((c%2)==0)
        {
            if(x>=y)
            {
                if(c==2&&v[0]+1==v[1]) cout << min(x,2*y) << "\n";
                else cout << ll(c/2)*y << "\n";
            }
        }
        else cout << "-1\n";
    }
    return 0;
}