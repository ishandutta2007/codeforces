#include <bits/stdc++.h>
#define db(x) cout << (x) << '\n';
#define all(v) (v).begin(),(v).end()
#define allr(v) (v).rbegin(),(v).rend()
#define f first
#define s second
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<double,ll> pdi;
typedef pair<string,ll> psi;
typedef pair<ll,string> pls;
typedef pair<string,string> pss;
typedef pair<int,pii> pip;
typedef pair<pii,pii> ppp;
#define MAXN 105

bool mk[MAXN];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    for(int i=0;i<MAXN;i++)
        if(i%3==0)
            mk[i]=1;
    for(int i=0;i<MAXN;i++)
        if(mk[i])
            for(int j=i+7;j<MAXN;j+=7)
                mk[j]=1;

    int t;
    cin >> t;
    while(t--)
    {
        int n;
        cin >> n;
        if(mk[n])
            db("YES")
        else
            db("NO")
    }
    return 0;
}