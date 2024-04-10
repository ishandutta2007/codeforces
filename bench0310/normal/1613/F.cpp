#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const int mod=998244353;
const int root=15311432;
const int root_1=469870224;
const int root_pw=(1<<23);

int fpow(int b,int e)
{
    int res=1;
    while(e)
    {
        if(e&1) res=((ll)res*b)%mod;
        b=((ll)b*b)%mod;
        e/=2;
    }
    return res;
}

void fft(vector<int> &a,bool inv)
{
    int n=a.size();
    for(int i=1,j=0;i<n;i++)
    {
        int bit=(n/2);
        for(;j&bit;bit/=2) j^=bit;
        j^=bit;
        if(i<j) swap(a[i],a[j]);
    }
    for(int len=2;len<=n;len*=2)
    {
        int wlen=(inv?root_1:root);
        for(int i=len;i<root_pw;i*=2) wlen=((ll)wlen*wlen)%mod;
        for(int i=0;i<n;i+=len)
        {
            int w=1;
            for(int j=0;j<len/2;j++)
            {
                int u=a[i+j];
                int v=((ll)a[i+j+len/2]*w)%mod;
                a[i+j]=(u+v<mod?u+v:u+v-mod);
                a[i+j+len/2]=(u-v>=0?u-v:u-v+mod);
                w=((ll)w*wlen)%mod;
            }
        }
    }
    if(inv)
    {
        int n_1=fpow(n,mod-2);
        for(int &x:a) x=((ll)x*n_1)%mod;
    }
}

vector<int> multiply(vector<int> a,vector<int> b)
{
    int n=1;
    int t=((int)a.size()+(int)b.size()-2);
    while(n<(int)(a.size()+b.size())) n*=2;
    a.resize(n);
    b.resize(n);
    fft(a,0);
    fft(b,0);
    for(int i=0;i<n;i++) a[i]=((ll)a[i]*b[i])%mod;
    fft(a,1);
    a.resize(t+1);
    return a;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    vector<int> d(n+1,0);
    for(int i=1;i<=n-1;i++)
    {
        int a,b;
        cin >> a >> b;
        d[a]++;
        d[b]++;
    }
    for(int i=2;i<=n;i++) d[i]--;
    auto add=[&](ll a,ll b){return (a+b)%mod;};
    auto sub=[&](ll a,ll b){return (a-b+mod)%mod;};
    auto mul=[&](ll a,ll b){return (a*b)%mod;};
    queue<vector<int>> q;
    for(int i=1;i<=n;i++) q.push({1,d[i]});
    while(q.size()>=2)
    {
        vector<int> a=q.front();
        q.pop();
        vector<int> b=q.front();
        q.pop();
        q.push(multiply(a,b));
    }
    vector<int> dp=q.front();
    ll res=0;
    vector<ll> f(n+1,1);
    for(int i=1;i<=n;i++) f[i]=mul(f[i-1],i);
    for(int i=0;i<=n;i++)
    {
        ll t=mul(dp[i],f[n-i]);
        if((i%2)==0) res=add(res,t);
        else res=sub(res,t);
    }
    cout << res << "\n";
    return 0;
}