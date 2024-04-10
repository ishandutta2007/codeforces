#include <bits/stdc++.h>
using namespace std;
int main()
{
    //freopen("input.txt", "r", stdin);
    int n;
    cin>>n;
    int ar[n], su=0, an=0;
    for(int a=0; a<n; a++)
    {
        cin>>ar[a];
        su+=ar[a];
    }
    sort(ar, ar+n);
    while(su*2<9*n)
    {
        su+=5-ar[an], an++;
    }
    cout<<an;
}