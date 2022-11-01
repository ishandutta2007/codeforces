#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int op=0;

int one(int a)
{
    assert(op<10000);
    op++;
    cout << "A " << a << "\n";
    cout.flush();
    int x;
    cin >> x;
    return x;
}

int two(int a)
{
    assert(op<10000);
    op++;
    cout << "B " << a << "\n";
    cout.flush();
    int x;
    cin >> x;
    return x;
}

void three(int a)
{
    assert(op<10000);
    op++;
    cout << "C " << a << "\n";
    cout.flush();
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    const int N=100000;
    vector<bool> sieve(N+1,1);
    sieve[0]=sieve[1]=0;
    for(ll i=2;i<=N;i++)
    {
        if(sieve[i]==0) continue;
        for(ll j=i*i;j<=N;j+=i) sieve[j]=0;
    }
    int n;
    cin >> n;
    vector<int> primes;
    for(int i=1;i<=n;i++) if(sieve[i]==1) primes.push_back(i);
    vector<int> small;
    vector<int> big;
    for(int p:primes)
    {
        if((ll)p*p>n) big.push_back(p);
        else small.push_back(p);
    }
    int sz=sqrt(big.size());
    int rm=0;
    int bigprime=1;
    for(int i=0;i<(int)big.size();i++)
    {
        two(big[i]);
        rm+=(n/big[i]);
        if(((i+1)%sz)==0||i==(int)big.size()-1)
        {
            if(n-one(1)!=rm)
            {
                for(int j=i;j>i-sz;j--)
                {
                    if(one(big[j])==1)
                    {
                        bigprime=big[j];
                        break;
                    }
                }
            }
        }
        if(bigprime!=1) break;
    }
    int res=bigprime;
    for(int p:small)
    {
        two(p);
        vector<int> pw;
        pw.push_back(1);
        while(pw.back()*p<=n) pw.push_back(pw.back()*p);
        int c=pw.size()-1;
        int l=0,r=c+1;
        while(l<r-1)
        {
            int m=(l+r)/2;
            if(one(pw[m])==1) l=m;
            else r=m;
        }
        res*=pw[l];
    }
    three(res);
    return 0;
}