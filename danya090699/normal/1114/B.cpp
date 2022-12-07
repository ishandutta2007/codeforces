#include <bits/stdc++.h>
using namespace std;
int main()
{
    //freopen("input.txt", "r", stdin);
    int n, m, k;
    cin>>n>>m>>k;
    pair <int, int> ar[n];
    int us[n];
    for(int a=0; a<n; a++)
    {
        us[a]=0;
        cin>>ar[a].first;
        ar[a].second=a;
    }
    sort(ar, ar+n, greater <pair <int, int> >());
    long long an=0;
    for(int a=0; a<k*m; a++) us[ar[a].second]=1, an+=ar[a].first;
    cout<<an<<"\n";
    int q=0;
    for(int a=0; a<n; a++)
    {
        if(us[a])
        {
            q++;
            if(q%m==0 and q!=m*k) cout<<a+1<<" ";
        }
    }
}