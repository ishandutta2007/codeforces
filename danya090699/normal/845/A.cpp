//Come on, make Togliatti great again!
#include <bits/stdc++.h>
using namespace std;
int main()
{
    //freopen("input.txt", "r", stdin);
    int n;
    cin>>n;
    n*=2;
    int ar[n];
    for(int a=0; a<n; a++) cin>>ar[a];
    sort(ar, ar+n);
    if(ar[n/2-1]!=ar[n/2]) cout<<"YES";
    else cout<<"NO";
}