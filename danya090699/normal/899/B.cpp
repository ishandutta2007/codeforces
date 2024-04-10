#include <bits/stdc++.h>
using namespace std;
int main()
{
    //freopen("input.txt", "r", stdin);
    int mo[48]={31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31,
                31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31,
                31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31,
                31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int n, fo=0;
    cin>>n;
    int ar[n];
    for(int a=0; a<n; a++) cin>>ar[a];
    for(int a=0; a<48; a++)
    {
        bool ok=1;
        for(int b=0; b<n; b++) if(ar[b]!=mo[(a+b)%48]) ok=0;
        if(ok) fo=1;
    }
    if(fo) cout<<"Yes";
    else cout<<"No";
}