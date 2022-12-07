#include <bits/stdc++.h>
using namespace std;
const int sz=6e5+10;
int an[sz][3], q=0;
main()
{
    //freopen("input.txt", "r", stdin);
    int n;
    cin>>n;
    pair <int, int> ar[n];
    int va[n];
    for(int a=0; a<n; a++) scanf("%d", &ar[a].first), ar[a].second=a, va[a]=ar[a].first;
    sort(ar, ar+n);
    int p[n], le[n];
    for(int a=0; a<n; a++) scanf("%d", &p[a]);
    sort(p, p+n);
    vector <int> l, r;
    for(int a=0; a<n; a++)
    {
        if(ar[a].first<p[a]) l.push_back(ar[a].second);
        if(ar[a].first>p[a]) r.push_back(ar[a].second);

        le[ar[a].second]=abs(ar[a].first-p[a]);
    }
    reverse(l.begin(), l.end()), reverse(r.begin(), r.end());
    while(l.size() and r.size())
    {
        int i=l.back(), j=r.back();
        int d=min(le[i], le[j]);

        if(va[i]>=va[j]) break;

        an[q][0]=i+1, an[q][1]=j+1, an[q][2]=d, q++;

        le[i]-=d, le[j]-=d;

        if(le[i]==0) l.pop_back();
        if(le[j]==0) r.pop_back();
    }
    if(l.size() or r.size()) cout<<"NO";
    else
    {
        cout<<"YES\n"<<q<<"\n";
        for(int a=0; a<q; a++)
        {
            for(int b=0; b<3; b++) printf("%d ", an[a][b]);
            printf("\n");
        }
    }
}