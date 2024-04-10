#include <bits/stdc++.h>
using namespace std;
const int sz=1e3+10;
pair <int, int> ar[sz];
bool comp(int a, int b){return ar[a].first+ar[a].second<ar[b].first+ar[b].second;}
int main()
{
    //freopen("input.txt", "r", stdin);
    int n;
    cin>>n;
    int p[n], an[n];
    for(int a=0; a<n; a++) cin>>ar[a].first;
    for(int a=0; a<n; a++) cin>>ar[a].second;
    for(int a=0; a<n; a++) an[a]=0, p[a]=a;
    sort(p, p+n, comp);
    int yk=0, q=n;
    while(yk<n)
    {
        int cq=ar[p[yk]].first+ar[p[yk]].second;
        while(yk<n)
        {
            if(ar[p[yk]].first+ar[p[yk]].second==cq) an[p[yk]]=q, yk++;
            else break;
        }
        q--;
    }
    bool ok=1;
    for(int a=0; a<n; a++)
    {
        int lq=0, rq=0;
        for(int b=0; b<a; b++) if(an[b]>an[a]) lq++;
        for(int b=a+1; b<n; b++) if(an[b]>an[a]) rq++;
        if(lq!=ar[a].first or rq!=ar[a].second) ok=0;
    }
    if(ok)
    {
        cout<<"YES\n";
        for(int a=0; a<n; a++) cout<<an[a]<<" ";
    }
    else cout<<"NO";
}