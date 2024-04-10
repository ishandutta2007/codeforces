#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,m;
    cin >> n >> m;
    vector<int> sieve(n+1);
    for(int i=0;i<=n;i++) sieve[i]=i;
    for(ll i=2;i<=n;i++)
    {
        if(sieve[i]!=i) continue;
        for(ll j=i*i;j<=n;j+=i) sieve[j]=min(sieve[j],(int)i);
    }
    vector<vector<int>> primes(n+1);
    for(int i=1;i<=n;i++)
    {
        int a=i;
        while(a>1)
        {
            int x=sieve[a];
            primes[i].push_back(x);
            while((a%x)==0) a/=x;
        }
    }
    vector<bool> collider(n+1,0);
    vector<int> now(n+1,0);
    while(m--)
    {
        char t;
        int x;
        cin >> t >> x;
        if(t=='+')
        {
            if(collider[x]==1) cout << "Already on\n";
            else
            {
                int id=0;
                for(int p:primes[x]) if(now[p]!=0) id=now[p];
                if(id==0)
                {
                    cout << "Success\n";
                    collider[x]=1;
                    for(int p:primes[x]) now[p]=x;
                }
                else cout << "Conflict with " << id << "\n";
            }
        }
        else if(t=='-')
        {
            if(collider[x]==0) cout << "Already off\n";
            else
            {
                collider[x]=0;
                for(int p:primes[x]) now[p]=0;
                cout << "Success\n";
            }
        }
    }
    return 0;
}