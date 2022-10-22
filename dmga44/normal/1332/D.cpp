#include <bits/stdc++.h>
#define db(x) cout << (x) << '\n';
#define all(v) (v).begin(),(v).end()
#define allr(v) (v).rbegin(),(v).rend()
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll,ll> pii;
typedef pair<double,ll> pdi;
typedef pair<string,ll> psi;
typedef pair<ll,string> pls;
typedef pair<ll,pii> pip;
typedef pair<pii,pii> ppp;

int a[3][3];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    a[0][0]=(1<<17);
    a[0][1]=(1<<17);
    a[0][2]=(1<<17);
    a[1][1]=(1<<17);
    a[1][2]=(1<<17);
    a[2][1]=(1<<17);

    int k;
    cin >> k;
    a[0][0]|=k;
    a[1][0]|=k;
    a[2][0]|=k;
    a[2][1]|=k;
    a[2][2]|=k;

    cout << "3 3\n";
    for(int i=0;i<3;cout << '\n',i++)
        for(int j=0;j<3;j++)
            cout << a[i][j] << ' ';

    return 0;
}