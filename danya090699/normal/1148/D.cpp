#include <bits/stdc++.h>
using namespace std;
const int sz=3e5+10;
int ar[sz][2];
bool comp(int a, int b)
{
    return ar[a][0]>ar[b][0];
}
bool comp2(int a, int b)
{
    return ar[a][0]<ar[b][0];
}
main()
{
    //freopen("input.txt", "r", stdin);
    int n;
    cin>>n;
    vector <int> sp[2];
    for(int a=0; a<n; a++)
    {
        int x, y;
        scanf("%d%d", &x, &y);
        if(x<y) sp[0].push_back(a);
        if(x>y) sp[1].push_back(a);
        ar[a][0]=x, ar[a][1]=y;
    }
    int an;
    if(sp[0].size()>sp[1].size()) an=0, sort(sp[0].begin(), sp[0].end(), comp);
    else an=1, sort(sp[1].begin(), sp[1].end(), comp2);

    cout<<sp[an].size()<<"\n";
    for(int a=0; a<sp[an].size(); a++) printf("%d ", sp[an][a]+1);
}