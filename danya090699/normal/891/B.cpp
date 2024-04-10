#include <bits/stdc++.h>
using namespace std;
int main()
{
    //freopen("input.txt", "r", stdin);
    int n;
    cin>>n;
    pair <int, int> ar[n];
    for(int a=0; a<n; a++)
    {
        cin>>ar[a].first;
        ar[a].second=a;
    }
    sort(ar, ar+n);
    int an[n];
    for(int a=1; a<n; a++) an[ar[a].second]=ar[a-1].first;
    an[ar[0].second]=ar[n-1].first;
    for(int a=0; a<n; a++) cout<<an[a]<<" ";
}