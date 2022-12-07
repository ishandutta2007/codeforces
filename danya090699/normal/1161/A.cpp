#include <bits/stdc++.h>
using namespace std;
int main()
{
    //freopen("input.txt", "r", stdin);
    int n, k;
    cin>>n>>k;
    int ar[k], l[n], r[n], us[n];
    for(int a=0; a<n; a++) l[a]=1, r[a]=1, us[a]=0;
    for(int a=0; a<k; a++)
    {
        int x;
        scanf("%d", &ar[a]);
        ar[a]--;
    }
    for(int a=k-1; a>=0; a--)
    {
        int x=ar[a];
        if(x)
        {
            if(us[x-1]) l[x]=0;
        }
        else l[x]=0;

        if(x+1<n)
        {
            if(us[x+1]) r[x]=0;
        }
        else r[x]=0;

        us[x]=1;
    }
    int an=0;
    for(int a=0; a<n; a++)
    {
        if(us[a]) an+=l[a]+r[a];
        else
        {
            an++;
            if(a) an++;
            if(a+1<n) an++;
        }
    }
    cout<<an;
}