#include <bits/stdc++.h>
#define db(x) cout << (x) << '\n';
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;

int main()
{
//    ios_base::sync_with_stdio(0);
//    cin.tie(0);

    int t;
    cin >> t;
    while(t--)
    {
        int n,res=0;
        cin >> n;
        for(int i=0;(1<<i)<=n;i++)
        {
            vector<int> v1,v2;
            for(int j=1;j<=n;j++)
            {
                if(j&(1<<i))
                    v1.push_back(j);
                else
                    v2.push_back(j);
            }
            cout << v1.size() << ' ' << v2.size() << ' ';
            for(auto y : v1)
                cout << y << ' ';
            for(auto y : v2)
                cout << y << ' ';
            cout << '\n';
            cout.flush();
            int x;
            cin >> x;
            res=max(res,x);
        }
        cout << "-1 " << res << '\n';
        cout.flush();
    }

    return 0;
}