#include <bits/stdc++.h>
using namespace std;
#define ff first
#define ss second
#define ll long long
#define mp make_pair
#define pb push_back

const int N = 1e6 + 11;

int use[N],kol[N];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int x2;
    cin>>x2;
    use[1]=1;
    for (ll p=2; p<=1000000; p++)
    if (use[p]==0)
    {
        for (ll d=p*2; d<=1000000; d+=p)
        use[d]=p;
    }
    for (int i=1; i<=x2; i++)
    if (x2%i==0)
    {
        if (use[i]==0)
        {
            int l1=x2-i+1;
            int r1=x2;
            kol[l1]++;
            kol[r1+1]--;
        }
    }
    int res=x2;
    for (int i=1; i<=x2; i++)
    {
        kol[i]+=kol[i-1];
        if (kol[i]!=0)
        {
            int x=use[i];
            if (x==0) res=min(res,i); else res=min(res,i-x+1);
        }
    }
    cout<<res<<endl;
}