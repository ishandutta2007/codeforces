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
        vector<int> p(n,0);
        for(int i=0;i<n;i++) cin >> p[i];
        string s;
        cin >> s;
        vector<array<int,3>> v(n);
        for(int i=0;i<n;i++) v[i]={s[i]-'0',p[i],i};
        ranges::sort(v);
        vector<int> q(n);
        for(int i=0;i<n;i++) q[v[i][2]]=i+1;
        for(int i=0;i<n;i++) cout << q[i] << " \n"[i==n-1];
    }
    return 0;
}