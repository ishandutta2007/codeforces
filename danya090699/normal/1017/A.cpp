#include <bits/stdc++.h>
using namespace std;
int main()
{
    //freopen("input.txt", "r", stdin);
    int n;
    cin>>n;
    pair <int, int> ar[n];
    for(int a=0; a<n; a++)
    {
        int su=0;
        for(int b=0; b<4; b++)
        {
            int x;
            cin>>x;
            su+=x;
        }
        ar[a].first=su, ar[a].second=-(a+1);
    }
    sort(ar, ar+n);
    for(int a=0; a<n; a++) if(ar[a].second==-1) cout<<n-a;
}