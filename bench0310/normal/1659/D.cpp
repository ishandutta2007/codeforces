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
        vector<int> c(n+1,0);
        ll s=0;
        for(int i=1;i<=n;i++)
        {
            cin >> c[i];
            s+=c[i];
        }
        int ones=(s/n);
        vector<int> a(n+1,0);
        vector<int> e(n+1,0);
        int d=0;
        for(int i=n;i>=2;i--)
        {
            int x=c[i]-d;
            a[i]=(x==i);
            if(ones>0)
            {
                d++;
                e[i-ones+1]++;
            }
            ones-=(a[i]==1);
            d-=e[i];
        }
        a[1]=(ones==1);
        for(int i=1;i<=n;i++) cout << a[i] << " \n"[i==n];
    }
    return 0;
}