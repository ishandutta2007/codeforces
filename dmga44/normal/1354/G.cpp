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
#define pi acos(-1)

int main()
{
//    ios_base::sync_with_stdio(0);
//    cin.tie(0);
//    cout.tie(0);

    srand(time(0));

    int t;
    cin >> t;
    while(t--)
    {
        int n,k;
        cin >> n >> k;
        bool ok=1;
        for(int i=0;i<27;i++)
        {
            cout << "? 1 1\n";
            cout << "1\n";
            cout << rand()%(n-1)+2 << '\n';
            cout.flush();
            string s;
            cin >> s;
            if(s[0]=='S')
                ok=0;
        }

        if(!ok)
        {
            cout << "! " << 1 << '\n';
            cout.flush();
            continue;
        }

        int p=1;
        while(ok)
        {
            int ma=min(n-p,p);
            cout << "? " << ma << ' ' << ma << '\n';
            for(int i=1;i<=ma;i++)
                cout << i << ' ';
            cout << '\n';
            for(int i=1;i<=ma;i++)
                cout << p+i << ' ';
            cout << '\n';
            cout.flush();
            string s;
            cin >> s;
            if(s[0]=='F')
            {
                ok=0;
                continue;
            }
            p*=2;
        }

        int ma=min(n-p,p);
        int res=0;
        for(int i=(1<<9);i;i>>=1)
        {
            int len=res+i;
            if(len>ma)
                continue;

            cout << "? " << len << ' ' << len << '\n';
            for(int i=1;i<=len;i++)
                cout << i << ' ';
            cout << '\n';
            for(int i=1;i<=len;i++)
                cout << p+i << ' ';
            cout << '\n';
            cout.flush();
            string s;
            cin >> s;
            if(s[0]=='E')
                res+=i;
        }

        cout << "! " << res+p+1 << '\n';
        cout.flush();
    }

    return 0;
}