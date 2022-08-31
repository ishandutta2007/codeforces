#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair <int, int> pii;
typedef vector<int> vi;

#define mp make_pair
#define pb push_back

#define FOR(i, a, b) for (int i=a; i<b; i++)
#define F0R(i, a) for (int i=0; i<a; i++)

#define f first
#define s second
#define lb lower_bound
#define ub upper_bound
#define endl "\n"

const int MOD = 1000000007;
double PI = 4*atan(1);

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int px,py,vx,vy,a,b,c,d;
    double vx1, vy1;
    cin >> px >> py >> vx >> vy >> a >> b >> c >> d;
    double mag = sqrt(vx*vx+vy*vy);
    vx1 = vx/mag, vy1 = vy/mag;
    cout << fixed << setprecision(12);
    cout << (vx1*b+px) << " " << (vy1*b+py) << endl;
    cout << (-a/2.0*vy1+px) << " " << (a/2.0*vx1+py) << endl;
    cout << (-c/2.0*vy1+px) << " " << (c/2.0*vx1+py) << endl;
    cout << (-c/2.0*vy1+px-d*vx1) << " " << (c/2.0*vx1+py-d*vy1) << endl;
    cout << (c/2.0*vy1+px-d*vx1) << " " << (-c/2.0*vx1+py-d*vy1) << endl;
    cout << (c/2.0*vy1+px) << " " << (-c/2.0*vx1+py) << endl;
    cout << (a/2.0*vy1+px) << " " << (-a/2.0*vx1+py) << endl;

}