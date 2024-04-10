#include <bits/stdc++.h>
using namespace std;
#define rep(i,a,n) for (int i=a;i<n;i++)
#define per(i,a,n) for (int i=n-1;i>=a;i--)
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define all(x) (x).begin(),(x).end()
#define fi first
#define se second
#define SZ(x) ((int)(x).size())
typedef vector<int> VI;
typedef basic_string<int> BI;
typedef long long ll;
typedef pair<int,int> PII;
typedef double db;
mt19937 mrand(random_device{}()); 
const ll mod=1000000007;
int rnd(int x) { return mrand() % x;}
ll powmod(ll a,ll b) {ll res=1;a%=mod; assert(b>=0); for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}
ll gcd(ll a,ll b) { return b?gcd(b,a%b):a;}
// head

typedef double db;
const db EPS = 1e-9;
  
inline int sign(db a) { return a < -EPS ? -1 : a > EPS; }
  
inline int cmp(db a, db b){ return sign(a-b); }
  
struct P {
	db x, y;
	P() {}
	P(db _x, db _y) : x(_x), y(_y) {}
	P operator+(P p) { return {x + p.x, y + p.y}; }
	P operator-(P p) { return {x - p.x, y - p.y}; }
	P operator*(db d) { return {x * d, y * d}; }
	P operator/(db d) { return {x / d, y / d}; }
 
	bool operator<(P p) const { 
		int c = cmp(x, p.x);
		if (c) return c == -1;
		return cmp(y, p.y) == -1;
	}
 
	bool operator==(P o) const{
		return cmp(x,o.x) == 0 && cmp(y,o.y) == 0;
	}
 
	db dot(P p) { return x * p.x + y * p.y; }
	db det(P p) { return x * p.y - y * p.x; }
	 
	db distTo(P p) { return (*this-p).abs(); }
	db alpha() { return atan2(y, x); }
	void read() { cin>>x>>y; }
	void write() {cout<<"("<<x<<","<<y<<")"<<endl;}
	db abs() { return sqrt(abs2());}
	db abs2() { return x * x + y * y; }
	P rot90() { return P(-y,x);}
	P unit() { return *this/abs(); }
	int quad() const { return sign(y) == 1 || (sign(y) == 0 && sign(x) >= 0); }
	P rot(db an){ return {x*cos(an)-y*sin(an),x*sin(an) + y*cos(an)}; }
};

#define cross(p1,p2,p3) ((p2.x-p1.x)*(p3.y-p1.y)-(p3.x-p1.x)*(p2.y-p1.y))
#define crossOp(p1,p2,p3) sign(cross(p1,p2,p3))
  
bool chkLL(P p1, P p2, P q1, P q2) {
	db a1 = cross(q1, q2, p1), a2 = -cross(q1, q2, p2);
	return sign(a1+a2) != 0;
}
 
P isLL(P p1, P p2, P q1, P q2) {
	db a1 = cross(q1, q2, p1), a2 = -cross(q1, q2, p2);
	return (p1 * a2 + p2 * a1) / (a1 + a2);
}

P p[10];
db pi=acos(-1.0);
db eval(P a,P b,P c) {
	db f1=a.distTo(b),f2=a.distTo(c),f3=b.distTo(c);
	if (f1>f2) swap(f1,f2);
	if (f1>f3) swap(f1,f3);
	if (f2>f3) swap(f2,f3);
	db ans=f1+f2;
	if (f1*f1+f1*f2+f2*f2>=f3*f3) {
		if ((b-a).det(c-a)>=0) swap(b,c);
		ans=min(ans,c.distTo(a+(b-a).rot(pi/3)));
	}
	return ans;
}

db eval(db x,db y) {
	return max({eval(P(x,y),p[0],p[1]),eval(P(x,y),p[0],p[2]),eval(P(x,y),p[1],p[2])});
}

db eval(db x) {
	db l=-1e4,r=1e4;
	rep(rd,0,200) {
		db fl=(l*2+r)/3,fr=(l+r*2)/3;
		if (eval(x,fl)>eval(x,fr)) l=fl; else r=fr;
	}
	//printf("cc %.10f %.10f %.10f\n",x,l,eval(x,l));
	return eval(x,l);
}

int main() {
	rep(i,0,3) p[i].read();	
	db l=-1e4,r=1e4;
	rep(rd,0,200) {
		db fl=(l*2+r)/3,fr=(l+r*2)/3;
		if (eval(fl)>eval(fr)) l=fl; else r=fr;
	}
	printf("%.10f\n",eval(l));
}