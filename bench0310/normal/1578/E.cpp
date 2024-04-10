#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,m;
    cin >> n >> m;
    vector<pair<string,int>> v(n);
    for(int i=0;i<n;i++)
    {
        cin >> v[i].first;
        v[i].second=i+1;
        for(int j=1;j<m;j+=2) v[i].first[j]=('Z'-(v[i].first[j]-'A'));
    }
    sort(v.begin(),v.end());
    for(int i=0;i<n;i++) cout << v[i].second << " \n"[i==n-1];
    return 0;
}