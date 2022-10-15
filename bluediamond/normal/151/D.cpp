#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

const int N=2000+5;
const ll MOD=1000000007;
vector<int>v[N];
bool viz[N];
int n,sz,len;

void dfs(int nod)
{
    viz[nod]=1;
    for(auto nou:v[nod])
    {
        if(viz[nou]==0)
        {
            dfs(nou);
        }
    }
}

ll expow(ll a,ll b)
{
    ll ans=1;
    while(b)
    {
        if(b%2)
        {
            ans=(ll)ans*a%MOD;
        }
        b/=2;
        a=(ll)a*a%MOD;
    }
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>sz>>len;
    for(int i=1;i+len-1<=n;i++)
    {
        int st=i;
        int dr=i+len-1;
        while(st<dr)
        {
            v[st].push_back(dr);
            v[dr].push_back(st);
            st++;
            dr--;
        }
    }
    int cnt=0;
    for(int i=1;i<=n;i++)
    {
        if(viz[i]==0)
        {
            cnt++;
            dfs(i);
        }
    }
    ll ans=expow(sz,cnt);
    cout<<ans<<"\n";
    return 0;
}