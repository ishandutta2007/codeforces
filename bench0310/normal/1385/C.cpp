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
        vector<int> a(n);
        for(int i=0;i<n;i++) cin >> a[i];
        bool b=0;
        int idx=n-2;
        while(idx>=0)
        {
            if(a[idx]<a[idx+1]) b=1;
            if(b==1&&a[idx]>a[idx+1]) break;
            idx--;
        }
        cout << idx+1 << "\n";
    }
    return 0;
}