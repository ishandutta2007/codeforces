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
#define MAXN 1000005

bool ok[MAXN];
int mi[MAXN],ma[MAXN];
vector<int> mas,mis;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;
    for(int i=0;i<n;i++)
    {
        int l;
        cin >> l;
        vector<int> a(l);
        for(int j=0;j<l;j++)
            cin >> a[j];
        int cant=0;
        for(int j=1;j<l;j++)
            cant+=(a[j]<=a[j-1]);

        ok[i]=(l!=1 && (cant!=l-1));
        if(ok[i])
        {
            mi[i]=-1;
            ma[i]=1e6+5;
        }
        else
        {
            mi[i]=a[l-1];
            ma[i]=a[0];
        }
        mas.push_back(ma[i]);
        mis.push_back(mi[i]);
    }

    sort(all(mas));
    sort(all(mis));

    ll res=0;
    for(int i=0;i<n;i++)
    {
        int p=lower_bound(all(mas),mi[i]+1)-mas.begin();
        res+=(n-p);
    }

    for(int i=0;i<n;i++)
    {
        int p=lower_bound(all(mis),ma[i])-mis.begin();
        res+=p;
    }

    db(res/2)

    return 0;
}
/**
5
1 1
1 1
1 2
1 4
1 3
**/