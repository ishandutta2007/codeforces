#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,q;
    cin >> n >> q;
    string s;
    cin >> s;
    auto f=[&](int a)->int
    {
        if(a<0||a+2>=n) return 0;
        return (s.substr(a,3)=="abc");
    };
    int c=0;
    for(int i=0;i<n;i++) c+=f(i);
    while(q--)
    {
        int p;
        char a;
        cin >> p >> a;
        p--;
        for(int i=p-2;i<=p;i++) c-=f(i);
        s[p]=a;
        for(int i=p-2;i<=p;i++) c+=f(i);
        cout << c << "\n";
    }
    return 0;
}