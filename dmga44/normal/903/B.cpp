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

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int h1,a1,c1;
    cin >> h1>> a1>> c1;
    int h2,a2;
    cin >> h2 >> a2;
    int tar=(h2-1)/a1+1;
    for(int i=0;i<100000;i++)
    {
        int h=h1+i*(c1-a2);
        if(h>a2*(tar-1))
        {
            db(i+tar)
            for(int j=0;j<i;j++)
                cout << "HEAL\n";
            for(int j=0;j<tar;j++)
                db("STRIKE")
            break;
        }
    }

    return 0;
}