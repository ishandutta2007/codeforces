#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int q;
    cin >> q;
    while(q--)
    {
        string s,t;
        cin >> s >> t;
        int n=s.size(),m=t.size();
        int l=lcm(n,m);
        string a,b;
        for(int i=0;i<l/n;i++) a+=s;
        for(int i=0;i<l/m;i++) b+=t;
        if(a==b) cout << a << "\n";
        else cout << "-1\n";
    }
    return 0;
}