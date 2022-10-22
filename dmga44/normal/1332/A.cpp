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

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;
    while(t--)
    {
        int a,b,c,d;
        cin >> a >> b >> c >> d;
        int x,y,x1,x2,y1,y2;
        cin >> x >> y >> x1 >> y1 >> x2 >> y2;
        if(x1<=x-a+b && x-a+b<=x2 && y1<=y-c+d && y-c+d<=y2 && (!(a||b) || (x1!=x2)) && (!(c||d) || (y1!=y2)))
            db("Yes")
        else
            db("No")
    }

    return 0;
}
/**
3
3 2 2 2
0 0 -2 -2 2 2
3 1 4 1
0 0 -1 -1 1 1
1 1 1 1
1 1 1 1 1 1
**/