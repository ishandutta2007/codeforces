#include <bits/stdc++.h>
#define int long long
using namespace std;
main()
{
    //freopen("input.txt", "r", stdin);
    int n, k;
    cin>>n>>k;
    int ar[n];
    for(int a=0; a<n; a++) scanf("%lld", &ar[a]);
    vector <int> suf;
    suf.push_back(ar[n-1]);
    for(int a=n-2; a>=0; a--) suf.push_back(suf.back()+ar[a]);
    int an=suf.back();
    suf.pop_back();
    sort(suf.begin(), suf.end(), greater <int>());
    for(int a=0; a<k-1; a++) an+=suf[a];
    cout<<an;
}