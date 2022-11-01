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
        vector<int> a(n+1,0);
        int sum=0;
        for(int i=1;i<=n;i++)
        {
            cin >> a[i];
            sum+=a[i];
        }
        sort(a.begin()+1,a.end(),greater<int>());
        if((sum%n)==0)
        {
            int lim=sum/n;
            int k=1;
            while(a[k]>lim) k++;
            cout << k-1 << "\n";
        }
        else cout << "-1\n";
    }
    return 0;
}