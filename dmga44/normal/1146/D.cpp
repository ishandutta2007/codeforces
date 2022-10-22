#include <bits/stdc++.h>
#define db(x) cout << (x) << '\n';
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define MAXN 33000005

bool mk[MAXN];

ll gcd(ll a,ll b)
{
    if(!b)
        return a;
    return gcd(b,a%b);
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll m,a,b;
    cin >> m >> a >> b;
    mk[0]=1;
    ll res=1,sum=1;
    for(int i=1;i<=min(m,max(a,b)*330);i++)
    {
        if(i-a>=0 && mk[i-a])
        {
            queue<int> q;
            q.push(i);
            mk[i]=1;
            while(!q.empty())
            {
                int u=q.front();
                q.pop();
                sum++;
                if(u+a<=i && !mk[u+a])
                {
                    mk[u+a]=1;
                    q.push(u+a);
                }
                if(u-b>=0 && !mk[u-b])
                {
                    mk[u-b]=1;
                    q.push(u-b);
                }
            }
        }
        res+=sum;
    }

    if(m>(max(a,b)*330))
    {
        ll d=(m-(max(a,b)*330));
        res+=sum*d;
        ll g=gcd(a,b);
        res+=((((d/g)-1)*(d/g))/2)*g;
        res+=(d/g)*((m%g)+1);
        db(res)
    }
    else
        db(res)

    return 0;
}