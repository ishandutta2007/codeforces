#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, w;
    cin>>n>>w;
    int ar[n];
    pair <int, int> ar2[n];
    for(int a=0; a<n; a++)
    {
        cin>>ar[a];
        int q=ar[a]/2+ar[a]%2;
        w-=q;
        ar2[a].first=ar[a], ar2[a].second=a;
    }
    if(w>=0)
    {
        sort(ar2, ar2+n);
        for(int a=0; a<n; a++)
        {
            ar2[a].first=ar2[a].first/2+ar2[a].first%2;
        }
        for(int a=n-1; a>=0; a--)
        {
            while(ar2[a].first<ar[ar2[a].second] and w>0)
            {
                ar2[a].first++, w--;
            }
        }
        int an[n];
        for(int a=0; a<n; a++) an[ar2[a].second]=ar2[a].first;
        for(int a=0; a<n; a++) cout<<an[a]<<" ";
    }
    else cout<<-1;
}