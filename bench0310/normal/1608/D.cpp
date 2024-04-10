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
    vector<string> s(n);
    for(int i=0;i<n;i++) cin >> s[i];
    auto poly=[&](string t)->vector<int>
    {
        if(t=="??") return {1,2,1};
        else if(t=="W?"||t=="?W") return {1,1,0};
        else if(t=="WW") return {1,0,0};
        else if(t=="B?"||t=="?B") return {0,1,1};
        else if(t=="BB") return {0,0,1};
        else return {0,1,0};
    };
    auto add=[&](ll a,ll b){return (a+b)%mod;};
    auto sub=[&](ll a,ll b){return (a-b+mod)%mod;};
    auto mul=[&](ll a,ll b){return (a*b)%mod;};
    queue<vector<int>> q;
    for(int i=0;i<n;i++) q.push(poly(s[i]));
    while(q.size()>=2)
    {
        vector<int> a=q.front();
        q.pop();
        vector<int> b=q.front();
        q.pop();
        q.push(multiply(a,b));
    }
    vector<int> dp=q.front();
    int res=dp[dp.size()/2];
    auto match=[&](int i,string t)->int
    {
        for(int j=0;j<2;j++) if(s[i][j]!='?'&&s[i][j]!=t[j]) return 0;
        return 1;
    };
    int opt=1;
    for(int i=0;i<n;i++)
    {
        int c=(match(i,"WB")+match(i,"BW"));
        opt=mul(opt,c);
    }
    res=sub(res,opt);
    int x=1,y=1;
    for(int i=0;i<n;i++)
    {
        x&=match(i,"WB");
        y&=match(i,"BW");
    }
    res=add(res,add(x,y));
    cout << res << "\n";
    return 0;
}