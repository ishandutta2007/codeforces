#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    vector<array<ll,2>> v(n);
    ll res=0;
    for(int i=0;i<n;i++)
    {
        string s;
        cin >> s;
        int a=0;
        for(char c:s) a+=(c=='s');
        int b=((int)s.size()-a);
        v[i]={a,b};
        int x=0;
        for(char c:s)
        {
            if(c=='s') x++;
            else res+=x;
        }
    }
    sort(v.begin(),v.end(),[](array<ll,2> a,array<ll,2> b){return (a[0]*b[1]>a[1]*b[0]);});
    ll x=0;
    for(int i=0;i<n;i++)
    {
        res+=(v[i][1]*x);
        x+=v[i][0];
    }
    cout << res << "\n";
    return 0;
}