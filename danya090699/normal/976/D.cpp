#include <bits/stdc++.h>
using namespace std;
int main()
{
    //freopen("input.txt", "r", stdin);
    int m, n;
    cin>>m;
    int ar[m];
    for(int a=0; a<m; a++) cin>>ar[a];
    n=ar[m-1]+1;
    vector <pair <int, int> > an;
    for(int a=0; m-1-a>=a; a++)
    {
        int p=m-1-a;
        for(int b=0; b<ar[a]; b++)
        {
            for(int c=1; c<n; c++) an.push_back(make_pair(c, n));
            n--;
        }
        if(p>0) n-=ar[p]-ar[p-1];
        for(int b=p; b>=a; b--) ar[b]-=ar[a];
    }
    cout<<an.size()<<"\n";
    for(int a=0; a<an.size(); a++) printf("%d %d\n", an[a].first, an[a].second);
}