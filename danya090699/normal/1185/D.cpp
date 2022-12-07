#include <bits/stdc++.h>
using namespace std;
main()
{
    //freopen("input.txt", "r", stdin);
    int n;
    cin>>n;
    pair <int, int> ar[n];
    for(int a=0; a<n; a++)
    {
        scanf("%d", &ar[a].first);
        ar[a].second=a+1;
    }
    sort(ar, ar+n);
    map <int, int> q;
    for(int a=0; a+1<n; a++) q[ar[a+1].first-ar[a].first]++;
    for(int a=0; a<n; a++)
    {
        int su=0;
        if(a)
        {
            int x=ar[a].first-ar[a-1].first;
            q[x]--, su+=x;
            if(q[x]==0) q.erase(x);
        }
        if(a+1<n)
        {
            int x=ar[a+1].first-ar[a].first;
            q[x]--, su+=x;
            if(q[x]==0) q.erase(x);
        }
        if(a and a+1<n) q[su]++;
        if(q.size()<2)
        {
            cout<<ar[a].second;
            return 0;
        }
        if(a and a+1<n)
        {
            q[su]--;
            if(q[su]==0) q.erase(su);
        }
        if(a)
        {
            q[ar[a].first-ar[a-1].first]++;
        }
        if(a+1<n)
        {
            q[ar[a+1].first-ar[a].first]++;
        }
    }
    cout<<-1;
}