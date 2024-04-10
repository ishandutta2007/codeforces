#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops","omit-frame-pointer","inline")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,sse4.1,sse4.2,popcnt,abm,mmx,avx,avx2,fma,tune=native")
#pragma GCC option("arch=native","no-zero-upper") //Enable AVX

#include <bits/stdc++.h>
#define db(x) cout << (x) << '\n';
#define all(v) (v).begin(),(v).end()
#define allr(v) (v).rbegin(),(v).rend()
#define f first
#define s second
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef double ld;
typedef pair<ll,ll> pii;
typedef pair<ld,ll> pdi;
typedef pair<ld,ld> pdd;
typedef pair<ld,pii> pdp;
typedef pair<string,ll> psi;
typedef pair<ll,string> pls;
typedef pair<string,string> pss;
typedef pair<ll,pii> pip;
typedef pair<pii,pii> ppp;
typedef complex<ld> point;
typedef vector<point> polygon;
typedef pair<point,int> ppi;
#define prec(n) cout.precision(n); cout<<fixed
#define mod (ll)(1e9+7)
#define eps (1e-9)
const ll oo=(ll)(1e11);
#define pi acos(-1)
#define MAXN (ll)(1e6+5)

int szs[MAXN];
polygon ps[MAXN];
vector<ld> ds[MAXN];
ld as[MAXN];
char cs[MAXN];

double read0()
{
    scanf("%s",cs);
    double res=0;
    int p=0;
    bool past_dot=0;
    double p10=0.1;
    while(cs[p]!='\0')
    {
        if(cs[p]=='.')
        {
            past_dot=1;
            p++;
            continue;
        }
        double vp=cs[p]-'0';
        if(past_dot)
        {
            res+=vp*p10;
            p10/=10.0;
        }
        else
        {
            res*=10;
            res+=vp;
        }
        p++;
    }
    return res;
}

point read()
{
    double x=read0();
    double y=read0();
//    cin >> x >> y;
//    scanf("%f%f",&x,&y);
    return point(x,y);
}

#define NEXT(i) (((i) + 1) % n)

struct line { point p, q; };
using segment = line;

double dot(point a, point b) { return real(conj(a) * b); }

ld cross(point a, point b) { return imag(conj(a) * b); }

int ccw(point a, point b, point c)
{
	b -= a; c -= a;
	if (cross(b, c) > 0) return +1; // counter clockwise
	if (cross(b, c) < 0) return -1; // clockwise
	if (dot(b, c) < 0) return +2; // c--a--b on line
	if (dot(b, b) < dot(c, c)) return -2; // a--b--c on line
	return 0;
}

bool intersectSS(const segment &s, const segment &t)
{
	return ccw(s.p, s.q, t.p) * ccw(s.p, s.q, t.q) <= 0
			&& ccw(t.p, t.q, s.p) * ccw(t.p, t.q, s.q) <= 0;
}

ld area2(const polygon &P)
{
	ld A = 0;
	for (int i = 0, n = P.size(); i < n; ++i)
		A += cross(P[i], P[NEXT(i)]);
	return fabs(A/2);
}

ld min_dis(ld ab,ld ac,ld bc)
{
    ld cos_abc=(ac*ac-ab*ab-bc*bc)/(-2.0*ab*bc);
    ld cos_acb=(ab*ab-ac*ac-bc*bc)/(-2.0*ac*bc);
    if(min(cos_abc,cos_acb)<=eps)
        return min(ab,ac);

    return sqrt(1-cos_abc*cos_abc)*ab;
}

ld give_me_random_ang()
{
    ld ang=(((ll)rand()*(1ll<<15))+(ll)rand())%(1<<20);
    ang/=(ld)(1<<20);
    ang*=2*pi;
    return ang;
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

//    freopen(".in","r",stdin);

    prec(6);

    srand(time(0));

    ld w,h;
    int n;
//    cin >> w >> h >> n;
    scanf("%lf%lf%d",&w,&h,&n);
    for(int i=0;i<n;i++)
    {
//        cin >> szs[i];
        scanf("%d",&szs[i]);
        for(int j=0;j<szs[i];j++)
        {
            point p=read();
            ps[i].push_back(p);
//            cout << i << ' ' << j << ' ' << p.real() << ' ' << p.imag() << '\n';
        }
        for(int j=0;j<szs[i];j++)
            ds[i].push_back(abs(ps[i][j]-ps[i][(j+1)%szs[i]]));
        as[i]=area2(ps[i]);
    }

    int q;
//    cin >> q;
    scanf("%d",&q);
    while(q--)
    {
        ld r;
        point c=read();
//        cin >> rr;
        scanf("%lf",&r);
        ld a=0;
        vector<int> indexes;
        for(int i=0;i<n;i++)
        {
            vector<ld> ds2(szs[i]);
            bool ok=0;
            int c1=0;
            int c2=0;
//            ld a1=give_me_random_ang();
            ld a2=give_me_random_ang();
//            segment l1={c,c+point(oo*cos(a1),oo*sin(a1))};
            segment l2={c,c+point(oo*cos(a2),oo*sin(a2))};
            for(int j=0;j<szs[i];j++)
            {
                ds2[j]=abs(c-ps[i][j]);
//                c1+=intersectSS(l1,{ps[i][j],ps[i][(j+1)%szs[i]]});
                c2+=intersectSS(l2,{ps[i][j],ps[i][(j+1)%szs[i]]});
            }

            ok=(ok|((c1&1)||(c2&1)));

            for(int j=0;j<szs[i] && !ok;j++)
                ok=(ok|(min_dis(ds2[j],ds2[(j+1)%szs[i]],ds[i][j]))<=r+eps);
            if(ok)
            {
                a+=as[i];
                indexes.push_back(i);
            }
        }

        cout << a << ' ' << indexes.size();
        for(auto y : indexes)
            cout << ' ' << y;
        cout << '\n';
    }

    return 0;
}
/**
10 10 3
4 2 2 3 2 3 3 2 3
3 3.5 2 4.5 2 4.5 3
4 7 8 7.5 8.5 8 8 7.5 9
1
5 2.5 0.5

100 100 1
4 0 0 4 0 4 4 0 4
1
2 2 1

10 10 3
4 2 2 3 2 3 3 2 3
3 3.5 2 4.5 2 4.5 3
4 7 8 7.5 8.5 8 8 7.5 9
5
2 3.5 0.5
3.3 2 0.4
5 2.5 0.5
7.5 8.5 0.5
3 7 0.5
**/
//#include <bits/stdc++.h>
//using namespace std;
//
//typedef long long ll;
//typedef long unsigned long ull;
//typedef double long ld;
//
//const ld pi = acos(ld(-1));
//
//string row;
//
//int main() {
//	ios::sync_with_stdio(!cin.tie(0));
//
//    freopen(".in","w",stdout);
//
//	int n = 60000;
//	cout << setprecision(5) << fixed;
//	cout << "1000000000.0 1000000000.0 " << n << '\n';
//
//	{
//		ostringstream poly;
//		int k = 40;
//		poly << k;
//		for (int i=0; i<k; i++) {
//			int x = int(sin(pi * i / k) * 48 + 48);
//			int y = int(cos(pi * i / k) * 48 + 48);
//			poly << ' ' << x << ' ' << y;
//		}
//		poly << '\n';
//		row = poly.str();
//	}
//
//	for (int i=0; i<n; i++) {
//		cout << row;
//	}
//
//	int q = 2;
//	cout << q << '\n';
//	while (q--) {
//		cout << "1.0 1.0 1.0\n";
//	}
//}