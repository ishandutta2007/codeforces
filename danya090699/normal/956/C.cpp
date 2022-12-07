#include <bits/stdc++.h>
using namespace std;
int main()
{
    //freopen("input.txt", "r", stdin);
    int n;
    cin>>n;
    int ar[n], ar2[n];
    for(int a=0; a<n; a++)
    {
        cin>>ar[a];
        ar2[a]=ar[a];
    }
    for(int a=1; a<n; a++) ar[a]=max(ar[a], ar[a-1]);
    for(int a=n-2; a>=0; a--) ar[a]=max(ar[a], ar[a+1]-1);
    long long an=0;
    for(int a=0; a<n; a++) an+=ar[a]-ar2[a];
    cout<<an;
}