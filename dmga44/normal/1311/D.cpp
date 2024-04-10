#include <bits/stdc++.h>
#define db(x) cout << (x) << '\n';
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<double,ll> pdi;
typedef pair<string,ll> psi;
typedef pair<int,pii> pip;
typedef pair<pii,pii> ppp;
#define MAXN 20005

vector<int> divs[MAXN];

void criba()
{
    for(int i=1;i<MAXN;i++)
        for(int j=i;j<MAXN;j+=i)
            divs[j].push_back(i);
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    criba();

    int t;
    cin >> t;
    while(t--)
    {
        int res=1e5;
        int A=-1;
        int B=-1;
        int C=-1;
        int a,b,c;
        cin >> a >> b >> c;
        for(int i=1;i<=min(b+res,(int)2e4);i++)
        {
            int v=abs(b-i),v2=i;
            int aa=-1;
            for(auto div : divs[i])
            {
                if(v2>abs(div-a))
                {
                    v2=abs(div-a);
                    aa=div;
                }
            }
            int v3=min(c%i,i-(c%i)),cc=-1;
            if(c%i<i-(c%i))
            {
                cc=c-(c%i);
            }
            else
                cc=c+i-(c%i);
            if(res>v+v2+v3)
            {
                res=v+v2+v3;
                A=aa;
                B=i;
                C=cc;
            }
        }
        db(res)
        cout << A << ' ' << B << ' ' << C << '\n';
    }

    return 0;
}