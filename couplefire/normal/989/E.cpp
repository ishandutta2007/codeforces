#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

void maximize(double &a,double b)
{
  a=max(a,b);
}

typedef long long int ll;

struct point {
  ll x,y;
  point() {}
  point(ll x,ll y):x(x),y(y) {}
};

ll prodesc(point p1,point p2)
{
  return p1.x*p2.x+p1.y*p2.y;
}

ll prodvec(point p1,point p2)
{
  return p1.x*p2.y-p1.y*p2.x;
}

point operator-(point p1,point p2)
{
  return point(p1.x-p2.x,p1.y-p2.y);
}

struct line {
  point p,v;
  line() {}
  line(point p,point v):p(p),v(v) {}
};

bool belongs(point p,line l)
{
  return prodvec(l.p-p,l.v)==0;
}

int n;
typedef vector<vector<double> > mat;

mat operator*(mat m1,mat m2)
{
  mat m(n,vector<double> (n,0));
  for (int i=0;i<n;i++)
    for (int j=0;j<n;j++)
      for (int k=0;k<n;k++)
	m[i][j]+=m1[i][k]*m2[k][j];
  return m;
}

vector<double> operator*(vector<double> v,mat m)
{
  vector<double> r(n,0);
  for (int j=0;j<n;j++)
    for (int i=0;i<n;i++)
      r[j]+=v[i]*m[i][j];
  return r;
}

const int limit=205;

point p[limit];
int nl;
vector<int> p2l[limit];
vector<int> l2p[limit*limit];

const int tope=15;
mat vm[tope];

int main()
{
  cout.setf(ios::fixed);
  cout.precision(10);
  ios::sync_with_stdio(false);
  cin>>n;
  for (int i=0;i<n;i++)
    cin>>p[i].x>>p[i].y;
  for (int i=0;i<n;i++) {
    for (int j=i+1;j<n;j++) {
      line l(p[i],p[j]-p[i]);
      bool error=false;
      for (int k=0;k<j and not error;k++)
	error=k!=i and belongs(p[k],l);
      if (not error) {
	for (int k=0;k<n;k++) {
	  if (belongs(p[k],l)) {
	    p2l[k].push_back(nl);
	    l2p[nl].push_back(k);
	  }
	}
	nl++;
      }
    }
  }
  mat m(n,vector<double> (n,0));
  for (int u=0;u<n;u++) {
    vector<int> &vl=p2l[u];
    int nvl=int(vl.size());
    for (int ivl=0;ivl<nvl;ivl++) {
      int l=vl[ivl];
      vector<int> &vu=l2p[l];
      int nvu=int(vu.size());
      for (int ivu=0;ivu<nvu;ivu++) {
	int v=vu[ivu];
	m[v][u]+=1.0/nvl/nvu;
      }
    }
  }
  vm[0]=m;
  for (int steps=1;steps<tope;steps++)
    vm[steps]=vm[steps-1]*vm[steps-1];
  int cases;
  cin>>cases;
  for (int cas=0;cas<cases;cas++) {
    int p,t;
    cin>>p>>t;
    p--;
    t--;
    vector<double> V(n,0);
    V[p]=1;
    for (int b=0;b<tope;b++)
      if (t&(1<<b))
	V=V*vm[b];
    double sol=0;
    vector<int> vl=p2l[p];
    int nvl=int(vl.size());
    for (int ivl=0;ivl<nvl;ivl++) {
      int l=vl[ivl];
      double pl=0;
      vector<int> &vu=l2p[l];
      int nvu=int(vu.size());
      for (int ivu=0;ivu<nvu;ivu++) {
	int v=vu[ivu];
	pl+=1.0/nvu*V[v];
      }
      maximize(sol,pl);
    }
    cout<<sol<<endl;
  }
}