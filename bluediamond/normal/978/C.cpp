#include <bits/stdc++.h>


using namespace std;

typedef long long ll;
typedef long double ld;
#define mp make_pair
#define pb push_back
#define ff first
#define ss second

const int N=2e5+5;
int n,q;
ll v[N];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin>>n>>q;
    for(int i=1;i<=n;i++) cin>>v[i];
    ll cur=0;
    int p=1;
    ll lst=0;
    while(q--)
    {
        ll x; cin>>x; cur+=x-lst; lst=x;
        while(cur>v[p]) cur-=v[p++];
        cout<<p<<" "<<cur<<"\n";
    }
}
/**

1 5 70 100 1000

**/