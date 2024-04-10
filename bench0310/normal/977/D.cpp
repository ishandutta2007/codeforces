#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    vector<array<ll,3>> v(n);
    for(int i=0;i<n;i++)
    {
        ll a;
        cin >> a;
        ll t=a;
        int x=0,y=0;
        while((t%2)==0)
        {
            x++;
            t/=2;
        }
        while((t%3)==0)
        {
            y++;
            t/=3;
        }
        v[i]={x,y,a};
    }
    sort(v.begin(),v.end(),[&](const array<ll,3> &a,const array<ll,3> &b){return (a[0]<b[0]||(a[0]==b[0]&&a[1]>b[1]));});
    for(int i=0;i<n;i++) cout << v[i][2] << " \n"[i==n-1];
    return 0;
}