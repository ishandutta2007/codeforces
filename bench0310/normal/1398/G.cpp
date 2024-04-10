#include <bits/stdc++.h>
#pragma GCC optimize ("Ofast")

using namespace std;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    const int N=200001;
    const int M=1000000;
    int n,x,y;
    cin >> n >> x >> y;
    bitset<N> b;
    for(int i=0;i<n+1;i++)
    {
        int a;
        cin >> a;
        b[a]=1;
    }
    vector<bool> ok(x+1,0);
    for(int i=1;i<=x;i++) ok[i]=(b&(b<<i)).any();
    vector<int> sieve(M+1,0);
    for(int i=1;i<=M;i++) sieve[i]=i;
    for(ll i=2;i<=M;i++)
    {
        if(sieve[i]!=i) continue;
        for(ll j=i*i;j<=M;j+=i) if(sieve[j]==j) sieve[j]=i;
    }
    vector<int> divisors;
    vector<array<int,2>> f;
    function<void(int,int)> gen=[&](int idx,int now)
    {
        divisors.push_back(now);
        if(idx==(int)f.size()) return;
        int p=1;
        gen(idx+1,now);
        for(int i=0;i<f[idx][1];i++)
        {
            p*=f[idx][0];
            gen(idx+1,now*p);
        }
    };
    auto fact=[&](int a)
    {
        divisors.clear();
        f.clear();
        if(a==1) return;
        array<int,2> now={sieve[a],0};
        int t=a;
        while(t>1)
        {
            if(sieve[t]==now[0]) now[1]++;
            else
            {
                f.push_back(now);
                now={sieve[t],1};
            }
            t/=sieve[t];
        }
        f.push_back(now);
    };
    int q;
    cin >> q;
    while(q--)
    {
        int l;
        cin >> l;
        fact(l);
        gen(0,1);
        int res=-1;
        for(int d:divisors)
        {
            if((d-2*y)/2>=0&&((d-2*y)%2)==0&&(d-2*y)/2<=x&&ok[(d-2*y)/2]==1) res=max(res,d);
        }
        cout << res << " ";
    }
    cout << "\n";
    return 0;
}