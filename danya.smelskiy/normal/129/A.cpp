#include<bits/stdc++.h>
#define ull unsigned long long
#define ll long long
#define ld long double
#define ff first
#define ss second
#define pb push_back
#define mp make_pair
#define sqr(a) ((a)*(a))
#define bs ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#define el "\n"
using namespace std;

void file()
{
    freopen("input.in","r",stdin);
    freopen("output.out","w",stdout);
}

int n,a[100000],sum,ans;

int main()
{
    //bs;
    //file();
    cin>>n;
    for(int i=1;i<=n;++i)
    {
        cin>>a[i];
        sum+=a[i];
    }
    for(int i=1;i<=n;++i)
    {
        if((sum-a[i])%2==0)
        {
            ans++;
        }
    }
    cout<<ans;
}