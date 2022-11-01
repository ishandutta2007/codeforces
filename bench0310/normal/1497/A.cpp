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
        vector<int> v(101,0);
        for(int i=0;i<n;i++)
        {
            int a;
            cin >> a;
            v[a]++;
        }
        for(int i=0;i<n;i++)
        {
            if(v[i]>0)
            {
                cout << i << " ";
                v[i]--;
            }
            else break;
        }
        for(int i=0;i<=100;i++)
        {
            while(v[i]--) cout << i << " ";
        }
        cout << "\n";
    }
    return 0;
}