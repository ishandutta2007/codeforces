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
        int n,m;
        cin >> n >> m;
        vector<int> v(m,0);
        for(int i=0;i<n;i++)
        {
            int a;
            cin >> a;
            v[a%m]++;
        }
        int res=0;
        for(int i=1;i<(m+1)/2;i++) if(v[i]>0||v[m-i]>0) res+=(1+max(0,abs(v[i]-v[m-i])-1));
        if(v[0]>0) res++;
        if((m%2)==0&&v[m/2]>0) res++;
        cout << res << "\n";
    }
    return 0;
}