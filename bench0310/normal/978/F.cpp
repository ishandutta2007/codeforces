#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
    int n,k;
    cin >> n >> k;
    vector<int> r(n+1,0);
    vector<array<int,2>> v(n);
    for(int i=1;i<=n;i++)
    {
        cin >> r[i];
        v[i-1][0]=r[i];
        v[i-1][1]=i;
    }
    sort(v.begin(),v.end());
    int now=-1;
    vector<int> res(n+1,0);
    for(int i=0;i<n;i++)
    {
        res[v[i][1]]=now+1;
        if(i<n-1&&v[i][0]<v[i+1][0]) now=i;
    }
    while(k--)
    {
        int a,b;
        cin >> a >> b;
        if(r[a]<r[b]) swap(a,b);
        if(r[a]!=r[b]) res[a]--;
    }
    for(int i=1;i<=n;i++) cout << res[i] << " \n"[i==n];
    return 0;
}