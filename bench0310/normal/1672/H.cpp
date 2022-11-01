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
    s="$"+s;
    vector<int> zero(n+1,0);
    for(int i=2;i<=n;i++) zero[i]=(zero[i-1]+(s[i-1]=='0'&&s[i]=='0'));
    vector<int> one(n+1,0);
    for(int i=2;i<=n;i++) one[i]=(one[i-1]+(s[i-1]=='1'&&s[i]=='1'));
    while(q--)
    {
        int l,r;
        cin >> l >> r;
        int a=zero[r]-zero[l];
        int b=one[r]-one[l];
        int m=min(a,b);
        cout << a+b-m+1 << "\n";
    }
    return 0;
}