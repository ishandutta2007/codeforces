#include <bits/stdc++.h>
using namespace std;
int main()
{
    //freopen("input.txt", "r", stdin);
    int n, m, k;
    cin>>n>>m>>k;
    int ar[n];
    for(int a=0; a<n; a++) cin>>ar[a];
    vector <int> sp;
    for(int a=0; a+1<n; a++) sp.push_back(ar[a+1]-ar[a]-1);
    sort(sp.begin(), sp.end(), greater <int>());
    int an=m-(ar[0]-1)-(m-ar[n-1]);
    for(int a=0; a<min(k-1, int(sp.size())); a++) an-=sp[a];
    cout<<an;
}