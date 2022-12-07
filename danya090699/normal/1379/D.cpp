#include <bits/stdc++.h>
using namespace std;
main()
{
    //freopen("input.txt", "r", stdin);
    int n, h, m, k;
    cin>>n>>h>>m>>k;
    if(k==1)
    {
        cout<<"0 0\n";
        return 0;
    }
    int tr[n];
    map <int, int> ma;
    ma[0]=0;
    int su=0, bq=1e9, t;
    for(int a=0; a<n; a++)
    {
        int hh, mm;
        cin>>hh>>mm;
        int l=(mm+1)%(m/2), r=(mm+k-1)%(m/2);
        ma[l]++;
        if(r+1!=m/2)
        {
            ma[r+1]--;
            if(r<l) ma[0]++;
        }
        tr[a]=mm;
    }
    for(auto it=ma.begin(); it!=ma.end(); it++)
    {
        int p=(*it).first;
        su+=(*it).second;
        if(su<bq) bq=su, t=p;
    }

    cout<<bq<<" "<<t<<"\n";
    for(int a=0; a<n; a++)
    {
        int l=(tr[a]+1)%(m/2), r=(tr[a]+k-1)%(m/2);
        if(l<r and t>=l and t<=r) cout<<a+1<<" ";
        if(l>r and (t>=l or t<=r)) cout<<a+1<<" ";
    }
}