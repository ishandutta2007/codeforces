#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    const int inf=(1<<30);
    while(t--)
    {
        int n;
        cin >> n;
        vector<int> a;
        int mn=inf;
        for(int i=0;i<n;i++)
        {
            int b;
            cin >> b;
            if(b<=0) a.push_back(b);
            else mn=min(mn,b);
        }
        sort(a.begin(),a.end());
        int d=inf-1;
        for(int i=0;i<(int)a.size()-1;i++) d=min(d,a[i+1]-a[i]);
        cout << a.size()+(d>=mn) << "\n";
    }
    return 0;
}