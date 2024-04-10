#include <bits/stdc++.h>
using namespace std;
const int sz=3e5+10;
int n, ar[sz], p[sz];
vector <pair <int, int> > an;
void sw2(int a, int b)
{
    an.push_back({a+1, b+1});
    swap(p[ar[a]], p[ar[b]]), swap(ar[a], ar[b]);
}
void sw(int a, int b)
{
    if(b-a>=n/2) sw2(a, b);
    else if(b<n/2) sw2(b, n-1), sw2(a, n-1), sw2(b, n-1);
    else if(a>=n/2) sw2(a, 0), sw2(b, 0), sw2(a, 0);
    else
    {
        sw2(0, b), sw2(0, n-1), sw2(a, n-1), sw2(0, n-1), sw2(0, b);
    }
}
main()
{
    //freopen("input.txt", "r", stdin);
    cin>>n;
    for(int a=0; a<n; a++)
    {
        scanf("%d", &ar[a]);
        ar[a]--;
        p[ar[a]]=a;
    }
    for(int a=0; a<n; a++) if(ar[a]!=a) sw(a, p[a]);
    cout<<an.size()<<"\n";
    for(int a=0; a<an.size(); a++) printf("%d %d\n", an[a].first, an[a].second);
}