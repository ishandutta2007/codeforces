#include <bits/stdc++.h>
#define db(x) cout << (x) << '\n';
#define all(v) (v).begin(),(v).end()
#define allr(v) (v).rbegin(),(v).rend()
#define f first
#define s second
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll,ll> pii;
typedef pair<double,ll> pdi;
typedef pair<string,ll> psi;
typedef pair<ll,string> pls;
typedef pair<string,string> pss;
typedef pair<ll,pii> pip;
typedef pair<pii,pii> ppp;
typedef complex<ld> point;
#define MAXN 1005

vector<int> ps[MAXN];
int res[MAXN],n;

int ask(int l,int r)
{
    bool mk[MAXN];
    for(int i=0;i<MAXN;i++)
        mk[i]=0;
    for(int i=l;i<=r;i++)
        for(auto y : ps[i])
            mk[y]=1;
    vector<int> pos;
    for(int i=1;i<=n;i++)
        if(!mk[i])
            pos.push_back(i);

    if(pos.size()==0)
        return -1;
    cout << "? " << pos.size();
    for(auto y : pos)
        cout << ' ' << y;
    cout << '\n';
    cout.flush();
    int res;
    cin >> res;
    return res;

}

int main()
{
//    ios_base::sync_with_stdio(0);
//    cin.tie(0);
//    cout.tie(0);

    int t;
    cin >> t;
    while(t--)
    {
        int k,c,x;
        cin >> n >> k;
        for(int i=0;i<k;i++)
        {
            cin >> c;
            for(int j=0;j<c;j++)
            {
                cin >> x;
                ps[i].push_back(x);
            }
        }

        int ma=ask(0,-1);
        int pos=0;
        for(int i=(1<<9);i;i>>=1)
        {
            if(pos+i>k)
                continue;
            int x=ask(pos,pos+i-1);
            if(x==ma)
            {
                for(int j=pos;j<=pos+i-1;j++)
                    res[j]=ma;
                pos+=i;
            }
            else
            {
                for(int j=pos+i;j<k;j++)
                    res[j]=ma;
            }
        }
        res[pos]=ask(pos,pos);

        cout << "!";
        for(int i=0;i<k;i++)
            cout << ' ' << res[i];
        cout << '\n';
        cout.flush();

        for(int i=0;i<k;i++)
        {
            ps[i].clear();
            res[i]=0;
        }
        string s;
        cin >> s;
    }

    return 0;
}
/**
1
4 2
2 1 3
2 2 4
**/