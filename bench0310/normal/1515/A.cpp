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
        int n,x;
        cin >> n >> x;
        vector<int> v(n,0);
        int sum=0;
        for(int i=0;i<n;i++)
        {
            cin >> v[i];
            sum+=v[i];
        }
        if(sum!=x)
        {
            cout << "YES\n";
            int now=0;
            while(!v.empty())
            {
                if(now+v.back()!=x)
                {
                    cout << v.back() << " ";
                    now+=v.back();
                    v.pop_back();
                }
                else
                {
                    cout << v[v.size()-2] << " ";
                    now+=v[v.size()-2];
                    v.erase(v.begin()+v.size()-2);
                }
            }
            cout << "\n";
        }
        else cout << "NO\n";
    }
    return 0;
}