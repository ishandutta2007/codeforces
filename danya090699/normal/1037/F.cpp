#include <bits/stdc++.h>
using namespace std;
const int mod=1e9+7;
int de(int x, int y){return x/y+(x%y>0);}
int su(int l, int r)
{
    if(l<=r) return ((1ll*(l+r)*(r-l+1))/2)%mod;
    else return 0;
}
int n, k, itq;
int f(int d)
{
    int q=d/k, os=d%k;
    return (1ll*su(itq-q+1, itq)*k+1ll*os*(itq-q))%mod;
}
int main()
{
    //freopen("input.txt", "r", stdin);
    cin>>n>>k;
    k--;
    itq=de(n, k);
    int ar[n], l[n], r[n];
    for(int a=0; a<n; a++) l[a]=-1;
    vector <pair <int, int> > st;
    for(int a=0; a<n; a++)
    {
        int x;
        scanf("%d", &x);
        while(st.size())
        {
            if(x>=st.back().first)
            {
                r[st.back().second]=a;
                st.pop_back();
            }
            else
            {
                l[a]=st.back().second;
                break;
            }
        }
        st.push_back(make_pair(x, a));
        ar[a]=x;
    }
    while(st.size())
    {
        r[st.back().second]=n;
        st.pop_back();
    }
    int an=0;
    for(int a=0; a<n; a++)
    {
        int cu=itq;
        int ld=a-l[a]-1, rd=r[a]-a-1;
        cu=(cu+f(ld))%mod;
        cu=(cu+mod-f(ld+1+rd))%mod;
        cu=(cu+f(rd))%mod;
        an=(an+1ll*ar[a]*cu)%mod;
    }
    cout<<an;
}