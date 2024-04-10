#include <bits/stdc++.h>
using namespace std;
struct el
{
    int f, l, di;
};
bool comp(el a, el b){return(a.di>b.di);}
int main()
{
    //freopen("input.txt", "r", stdin);
    int n, k, su=0, yk=0;
    cin>>n>>k;
    el ar[n];
    for(int a=0; a<n; a++) cin>>ar[a].f;
    for(int a=0; a<n; a++)
    {
        cin>>ar[a].l;
        ar[a].di=ar[a].l-ar[a].f;
    }
    sort(ar, ar+n, comp);
    for(int a=0; a<k; a++) su+=ar[a].f;
    for(int a=k; a<n; a++) su+=min(ar[a].f, ar[a].l);
    cout<<su;
}