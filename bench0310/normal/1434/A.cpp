#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    array<int,6> a;
    for(int i=0;i<6;i++) cin >> a[i];
    int n;
    cin >> n;
    vector<array<int,2>> v;
    for(int i=0;i<n;i++)
    {
        int b;
        cin >> b;
        for(int j=0;j<6;j++) v.push_back({b-a[j],i});
    }
    sort(v.begin(),v.end());
    vector<int> c(n,0);
    int in=0;
    int r=-1;
    int res=2000000000;
    for(int l=0;l<6*n;l++)
    {
        while(r+1<6*n&&in<n)
        {
            r++;
            c[v[r][1]]++;
            if(c[v[r][1]]==1) in++;
        }
        if(in<n) break;
        res=min(res,v[r][0]-v[l][0]);
        c[v[l][1]]--;
        if(c[v[l][1]]==0) in--;
    }
    cout << res << "\n";
    return 0;
}