#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,m;
    cin >> n >> m;
    string s,t;
    cin >> s >> t;
    s="$"+s+"$";
    t="$"+t+"$";
    vector<int> one(m+1,0);
    int idx=1;
    for(int i=1;i<=n;i++)
    {
        if(s[i]==t[idx]) one[idx++]=i;
    }
    vector<int> two(m+1,0);
    idx=m;
    for(int i=n;i>=1;i--)
    {
        if(s[i]==t[idx]) two[idx--]=i;
    }
    int res=0;
    for(int i=1;i<m;i++) res=max(res,two[i+1]-one[i]);
    cout << res << "\n";
    return 0;
}