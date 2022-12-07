#include <bits/stdc++.h>
#define int long long
using namespace std;
const int add=2e5, sz=2e5+100;
int n, k, ar[sz], cu=60;
main()
{
    //freopen("input.txt", "r", stdin);
    cin>>n>>k;
    while(n)
    {
        while(n<(1ll<<cu)) cu--;
        ar[cu+add]=1;
        n-=(1ll<<cu), k--;
    }
    if(k<0) cout<<"No";
    else
    {
        cout<<"Yes\n";
        for(int a=sz-1; ; a--)
        {
            if(ar[a]<=k)
            {
                ar[a-1]+=ar[a]*2, k-=ar[a], ar[a]=0;
            }
            else break;
        }
        int p=0;
        while(ar[p]==0) p++;
        for(int a=0; a<k; a++)
        {
            ar[p-1]+=2, ar[p]--, p--;
        }
        for(int a=sz-1; a>=0; a--)
        {
            while(ar[a])
            {
                cout<<a-add<<" ";
                ar[a]--;
            }
        }
    }
}