//Come on, make Togliatti great again!
#include <bits/stdc++.h>
using namespace std;
const int sz=5e6+10;
long long ar[sz], inf=1e18;
int main()
{
    //freopen("input.txt", "r", stdin);
    int t, l, r, os=1e9+7;
    cin>>t>>l>>r;
    for(int a=1; a<=r; a++) ar[a]=inf;
    ar[1]=0;
    for(int a=1; a<=r; a++)
    {
        int q=2;
        long long va=ar[a]*2+1;
        for(int b=a+a; b<=r; b+=a)
        {
            ar[b]=min(ar[b], va);
            va+=ar[a]+q;
            q++;
        }
    }
    int st=1, an=0;
    for(int a=l; a<=r; a++)
    {
        an=(an+(ar[a]%os)*st)%os;
        st=(1ll*st*t)%os;
    }
    cout<<an;
}