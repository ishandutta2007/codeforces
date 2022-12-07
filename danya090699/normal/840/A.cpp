//Come on, make Togliatti great again!
#include <bits/stdc++.h>
using namespace std;
const int sz=2e5+10;
int ar2[sz];
bool comp(int a, int b){return ar2[a]>ar2[b];}
int main()
{
    //freopen("input.txt", "r", stdin);
    int n;
    cin>>n;
    int ar[n], ar3[n], an[n];
    for(int a=0; a<n; a++)
    {
        cin>>ar[a];
        ar3[a]=a;
    }
    for(int a=0; a<n; a++) cin>>ar2[a];
    sort(ar, ar+n);
    sort(ar3, ar3+n, comp);
    for(int a=0; a<n; a++) an[ar3[a]]=ar[a];
    for(int a=0; a<n; a++) cout<<an[a]<<" ";
}