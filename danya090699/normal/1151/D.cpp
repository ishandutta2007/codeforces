#include <bits/stdc++.h>
using namespace std;
bool comp(pair <int, int> a, pair <int, int> b)
{
    return a.first-a.second>b.first-b.second;
}
int main()
{
    //freopen("input.txt", "r", stdin);
    int n;
    cin>>n;
    pair <int, int> ar[n];
    for(int a=0; a<n; a++) scanf("%d%d", &ar[a].first, &ar[a].second);
    sort(ar, ar+n, comp);
    long long an=0;
    for(int a=0; a<n; a++) an+=1ll*ar[a].first*(a)+1ll*ar[a].second*(n-a-1);
    cout<<an;
}