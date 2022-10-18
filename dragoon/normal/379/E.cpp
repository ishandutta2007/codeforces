#pragma warning(disable:4786)
#include<list>
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<set>
#include<map>
#include<functional>
#include<string>
#include<cstring>
#include<cstdlib>
#include<queue>
#include<utility>
#include<fstream>
#include<sstream>
#include<cmath>
#include<stack>
#include<assert.h>
using namespace std;

#define MEM(a, b) memset(a, (b), sizeof(a))
#define CLR(a) memset(a, 0, sizeof(a))
#define MAX(a, b) ((a) > (b) ? (a) : (b))
#define MIN(a, b) ((a) < (b) ? (a) : (b))
#define ABS(X) ( (X) > 0 ? (X) : ( -(X) ) )
#define S(X) ( (X) * (X) )
#define SZ(V) (int )V.size()
#define FORN(i, n) for(i = 0; i < n; i++)
#define FORAB(i, a, b) for(i = a; i <= b; i++)
#define ALL(V) V.begin(), V.end()
#define IN(A, B, C)  ((B) <= (A) && (A) <= (C))

typedef pair<int,int> PII;
typedef pair<double, double> PDD;
typedef vector<int> VI;
typedef vector<PII > VP;


#define AIN(A, B, C) assert(IN(A, B, C))

//typedef int LL;
//typedef long long int LL;
//typedef __int64 LL;

//http://codeforces.com/contest/280/submission/3275722

#define mp make_pair
#define pb push_back

const double eps=1e-8;
const double pi=acos(-1.0);
const double inf=1e20;
const int maxp=1111;

//Compares a double to zero
int dblcmp(double d)
{
    if (fabs(d)<eps) return 0;
    return d > eps ? 1 : -1;
}

//square of a double
inline double sqr(double x)
{
	return x*x;
}

/*
point()						- Empty constructor
point(double x, double y)	- constructor
input()						- double input
output()					- .2lf output
operator ==					- compares x and y
operator <					- compares first by x, then by y
len()						- gives length from origin
len2()						- gives square of length from origin
distance(point p)			- gives distance from p
add(point p)				- returns new point after adding curresponging x and y
sub(point p)				- returns new point after subtracting curresponging x and y
mul(double b)				- returns new point after multiplieing x and y by b
div(double b)				- returns new point after divideing x and y by b
dot(point p)				- dot product
det(point p)				- cross product of 2d points
rad(point a, point b)		- Probably radius of circumcircle of the triangle
trunc(double r)				- return point that is truncated the distance from center to r
rotleft()					- returns 90 degree ccw rotated point
rotright()					- returns 90 degree cw rotated point
rotate(point p, double angle) - returns point after rotateing the point centering at p by angle radian ccw
*/
struct point 
{
    double x,y;

    point(){}

    point(double _x,double _y)
	{
		x = _x;
		y = _y;
	}

    void input()
    {
        scanf("%lf%lf",&x,&y);
    }

    void output()
    {
        printf("%.2f %.2f\n",x,y);
    }

    bool operator==(point a)const
    {
        return dblcmp(a.x - x) == 0 && dblcmp(a.y - y) == 0;
    }

    bool operator<(point a)const
    {
        return dblcmp(a.x - x) == 0 ? dblcmp(y - a.y) < 0 : x < a.x;
    }

	point operator-(point a)const
	{
		return point(x-a.x, y-a.y);
	}

    double len()
    {
        return hypot(x, y);
    }

    double len2()
    {
        return x * x + y * y;
    }

    double distance(point p)
    {
        return hypot(x - p.x, y - p.y);
    }

    point add(point p)
    {
        return point(x + p.x, y + p.y);
    }

    point sub(point p)
    {
        return point(x - p.x, y - p.y);
    }

    point mul(double b)
    {
        return point(x * b, y * b);
    }

    point div(double b)
    {
        return point(x / b, y / b);
    }

    double dot(point p)
    {
        return x*p.x+y*p.y;
    }
    double det(point p)
    {
        return x*p.y-y*p.x;
    }
    double rad(point a,point b)
    {
        point p=*this;
        return fabs(atan2(fabs(a.sub(p).det(b.sub(p))),a.sub(p).dot(b.sub(p))));
    }
    point trunc(double r)
    {
        double l=len();
        if (!dblcmp(l))return *this;
        r/=l;
        return point(x*r,y*r);
    }
    point rotleft()
    {
        return point(-y,x);
    }
    point rotright()
    {
        return point(y,-x);
    }
    point rotate(point p,double angle)
    {
        point v=this->sub(p);
        double c=cos(angle),s=sin(angle);
        return point(p.x+v.x*c-v.y*s,p.y+v.x*s+v.y*c);
    }        
};


/*
Stores two points

line()								- Empty constructor
line(point a, point b)				- line through a and b
operator ==							- checks if two points are same
line(point p, double angle)			- one end p, another end at angle degree
line(double a, double b, double c)	- line of equation ax + by + c = 0
input()								- inputs a and b
adjust()							- orders in such a way that a < b
length()							- distance of ab
angle()								- returns 0 <= angle < 180
relation()							- 0 if collinear
									  1 if ccw
							  		  2 if cw
pointonseg(point p)					- returns 1 if point is on segment
parallel(line v)					- returns 1 if they are parallel
segcrossseg(line v)					- returns 0 if does not intersect
									  returns 1 if non-standard intersection
									  returns 2 if intersects
segcrossseg_inside(line v)			- returns 1 if intersects strictly inside
									  returns 0 if not
linecrossseg(line v)				- v is line
linecrossline(line v)				- 0 if parallel
									  1 if coincides
									  2 if intersects
crosspoint(line v)					- returns intersection point
dispointtoline(point p)				- distance from point p to the line
dispointtoseg(point p)				- distance from p to the segment
lineprog(point p)					- returns projected point p on ab line
symmetrypoint(point p)				- returns reflection point of p over ab
*/
struct line 
{
    point a,b;
    line(){}
    line(point _a,point _b)
    {
        a=_a;
        b=_b;
    }
    bool operator==(line v)
    {
        return (a==v.a)&&(b==v.b);
    }

    line(point p,double angle)
    {
        a=p;
        if (dblcmp(angle-pi/2)==0)
        {
            b=a.add(point(0,1));
        }
        else 
        {
            b=a.add(point(1,tan(angle)));
        }
    }       
    //ax+by+c=0
    line(double _a,double _b,double _c)
    {
        if (dblcmp(_a)==0)
        {
            a=point(0,-_c/_b);
            b=point(1,-_c/_b);
        }
        else if (dblcmp(_b)==0)
        {
            a=point(-_c/_a,0);
            b=point(-_c/_a,1);
        }
        else 
        {
            a=point(0,-_c/_b);
            b=point(1,(-_c-_a)/_b);
        }
    }
    void input()
    {
        a.input();
        b.input();
    }
    void adjust()
    {
        if (b<a)swap(a,b);
    }
    double length()
    {
        return a.distance(b);
    }
    double angle()
    {
        double k=atan2(b.y-a.y,b.x-a.x);
        if (dblcmp(k)<0)k+=pi;
        if (dblcmp(k-pi)==0)k-=pi;
        return k;
    }
    int relation(point p)
    {
        int c=dblcmp(p.sub(a).det(b.sub(a)));
        if (c<0)return 1;
        if (c>0)return 2;
        return 3;
    }
    bool pointonseg(point p)
    {
        return dblcmp(p.sub(a).det(b.sub(a)))==0&&dblcmp(p.sub(a).dot(p.sub(b)))<=0;
    }
    bool parallel(line v)
    {
        return dblcmp(b.sub(a).det(v.b.sub(v.a)))==0;
    }
    int segcrossseg(line v)
    {
        int d1=dblcmp(b.sub(a).det(v.a.sub(a)));
        int d2=dblcmp(b.sub(a).det(v.b.sub(a)));
        int d3=dblcmp(v.b.sub(v.a).det(a.sub(v.a)));
        int d4=dblcmp(v.b.sub(v.a).det(b.sub(v.a)));
        if ((d1^d2)==-2&&(d3^d4)==-2)return 2;
        return (d1==0&&dblcmp(v.a.sub(a).dot(v.a.sub(b)))<=0||
			d2==0&&dblcmp(v.b.sub(a).dot(v.b.sub(b)))<=0||
			d3==0&&dblcmp(a.sub(v.a).dot(a.sub(v.b)))<=0||
			d4==0&&dblcmp(b.sub(v.a).dot(b.sub(v.b)))<=0);        
    }        
    int segcrossseg_inside(line v)
    {
		if(v.pointonseg(a) || v.pointonseg(b) || pointonseg(v.a) || pointonseg(v.b)) return 0;
        int d1=dblcmp(b.sub(a).det(v.a.sub(a)));
        int d2=dblcmp(b.sub(a).det(v.b.sub(a)));
        int d3=dblcmp(v.b.sub(v.a).det(a.sub(v.a)));
        int d4=dblcmp(v.b.sub(v.a).det(b.sub(v.a)));
        if ((d1^d2)==-2&&(d3^d4)==-2)return 1;
        return (d1==0&&dblcmp(v.a.sub(a).dot(v.a.sub(b)))<=0||
			d2==0&&dblcmp(v.b.sub(a).dot(v.b.sub(b)))<=0||
			d3==0&&dblcmp(a.sub(v.a).dot(a.sub(v.b)))<=0||
			d4==0&&dblcmp(b.sub(v.a).dot(b.sub(v.b)))<=0);        
    }        
    int linecrossseg(line v)//*this seg v line
    {
        int d1=dblcmp(b.sub(a).det(v.a.sub(a)));
        int d2=dblcmp(b.sub(a).det(v.b.sub(a)));
        if ((d1^d2)==-2)return 2;
        return (d1==0||d2==0);
    }
    int linecrossline(line v)
    {
        if ((*this).parallel(v))
        {
            return v.relation(a)==3;
        }
        return 2;
    }
    point crosspoint(line v)
    {
        double a1=v.b.sub(v.a).det(a.sub(v.a));
        double a2=v.b.sub(v.a).det(b.sub(v.a));
        return point((a.x*a2-b.x*a1)/(a2-a1),(a.y*a2-b.y*a1)/(a2-a1));
    }
    double dispointtoline(point p)
    {
        return fabs(p.sub(a).det(b.sub(a)))/length();
    }
    double dispointtoseg(point p)
    {
        if (dblcmp(p.sub(b).dot(a.sub(b)))<0||dblcmp(p.sub(a).dot(b.sub(a)))<0)
        {
            return MIN(p.distance(a),p.distance(b));
        }
        return dispointtoline(p);
    }
    point lineprog(point p)
    {
        return a.add(b.sub(a).mul(b.sub(a).dot(p.sub(a))/b.sub(a).len2()));
    }
    point symmetrypoint(point p)
    {
        point q=lineprog(p);
        return point(2*q.x-p.x,2*q.y-p.y);
    }   
};

/*
n, p, line l for each side

input(n)						- inputs n size polygon
add(point p)					- adds a point at end of the list
getline()						- populates line array
cmp								- comparison in convex_hull order
norm()							- sorting in convex_hull order
getconvex(polygon &convex)		- returns convex hull in convex (monotone chain)
isconvex()						- checks if convex
relationpoint(point q)			- returns 3 if q is a vertex
										  2 if on a side
										  1 if inside
										  0 if outside
relationline(line u)			- returns 1 if there is some intersection
										  0 if no intersection
										  2 if intersect at corner
convexcut(line u,polygon &po)	- left side of u in po
getcircumference()				- returns side length
getarea()						- returns area
getdir()						- returns 0 for cw, 1 for ccw
getbarycentre()					- returns barycenter / cg
areaintersection(polygon po)	- not implemented
areaunion(polygon po)			- not implemented
areacircle(circle c)			- intersection area of circle and polygon
relationcircle(circle c)		- returns 0 if outside circle
										  1 if tangent
										  2 if inside
mincircle()						- returns minimum enclosing circle
circlecover()					- i think there is mistake. it tries to find minimum enclosing circle
pointinpolygon(point q)			- -1 if not on polygon, non negative number.. side index
inside_polygon(point q, int on_edge=1) 
			- returns on_edge if on edge, otherwise 0 for outside 1 for inside
isdiagonal(int a, int b)		- checks if p[a], p[b] is diagonal or not. returns 0/1
*/
struct polygon 
{
    int n;
    point p[maxp];
    line l[maxp];
    void input(int _n)
    {
        n=_n;
        for (int i=0;i<n;i++)
        {
            p[i].input();
        }
    }
    void add(point q)
    {
        p[n++]=q;
    }
    void getline()
    {
        for (int i=0;i<n;i++)
        {
            l[i]=line(p[i],p[(i+1)%n]);
        }
    }
    struct cmp
    {
        point p;
        cmp(const point &p0){p=p0;}
        bool operator()(const point &aa,const point &bb)
        {
            point a=aa,b=bb;
            int d=dblcmp(a.sub(p).det(b.sub(p)));
            if (d==0)
            {
                return dblcmp(a.distance(p)-b.distance(p))<0;
            }
            return d>0;
        }
    };
    void norm()
    {
        point mi=p[0];
        for (int i=1;i<n;i++)mi=MIN(mi,p[i]);
        sort(p,p+n,cmp(mi));
    }
    void getconvex(polygon &convex)
    {
        int i;
        sort(p,p+n);
        convex.n=n;
        for (i=0;i<MIN(n,2);i++)
        {
            convex.p[i]=p[i];
        }
        if (n<=2)return;
        int &top=convex.n;
        top=1;
        for (i=2;i<n;i++)
        {
            while (top&&convex.p[top].sub(p[i]).det(convex.p[top-1].sub(p[i]))<=0)
                top--;
            convex.p[++top]=p[i];
        }
        int temp=top;
        convex.p[++top]=p[n-2];
        for (i=n-3;i>=0;i--)
        {
            while (top!=temp&&convex.p[top].sub(p[i]).det(convex.p[top-1].sub(p[i]))<=0)
                top--;
            convex.p[++top]=p[i];
        }
    }
    bool isconvex()
    {
        bool s[3];
        memset(s,0,sizeof(s));
        int i,j,k;
        for (i=0;i<n;i++)
        {
            j=(i+1)%n;
            k=(j+1)%n;
            s[dblcmp(p[j].sub(p[i]).det(p[k].sub(p[i])))+1]=1;
            if (s[0]&&s[2])return 0;
        }
        return 1;
    }
    int relationpoint(point q)
    {
        int i,j;
        for (i=0;i<n;i++)
        {
            if (p[i]==q)return 3;
        }
        getline();
        for (i=0;i<n;i++)
        {
            if (l[i].pointonseg(q))return 2;
        }
        int cnt=0;
        for (i=0;i<n;i++)
        {
            j=(i+1)%n;
            int k=dblcmp(q.sub(p[j]).det(p[i].sub(p[j])));
            int u=dblcmp(p[i].y-q.y);
            int v=dblcmp(p[j].y-q.y);
            if (k>0&&u<0&&v>=0)cnt++;
            if (k<0&&v<0&&u>=0)cnt--;
        }
        return cnt!=0;
    }
    int relationline(line u)
    {
        int i,k=0;
        getline();
        for (i=0;i<n;i++)
        {
            if (l[i].segcrossseg(u)==2)return 1;
            if (l[i].segcrossseg(u)==1)k=1;
        }
        if (!k)return 0;
        vector<point>vp; 
        for (i=0;i<n;i++)
        {
            if (l[i].segcrossseg(u))
            {
                if (l[i].parallel(u))
                {
                    vp.pb(u.a);
                    vp.pb(u.b);
                    vp.pb(l[i].a);
                    vp.pb(l[i].b);
                    continue;
                }
                vp.pb(l[i].crosspoint(u));
            }
        }
        sort(vp.begin(),vp.end());
        int sz=vp.size();
        for (i=0;i<sz-1;i++)
        {
            point mid=vp[i].add(vp[i+1]).div(2);
            if (relationpoint(mid)==1)return 1;
        }
        return 2;
    }
    void convexcut(line u,polygon &po)
    {
        int i;
        int &top=po.n;
        top=0;
        for (i=0;i<n;i++)
        {
            int d1=dblcmp(p[i].sub(u.a).det(u.b.sub(u.a)));
            int d2=dblcmp(p[(i+1)%n].sub(u.a).det(u.b.sub(u.a)));
            if (d1>=0)po.p[top++]=p[i];
            if (d1*d2<0)po.p[top++]=u.crosspoint(line(p[i],p[(i+1)%n]));
        }
    }
    double getcircumference()
    {
        double sum=0;
        int i;
        for (i=0;i<n;i++)
        {
            sum+=p[i].distance(p[(i+1)%n]);
        }
        return sum;
    }
    double getarea()
    {
        double sum=0;
        int i;
        for (i=0;i<n;i++)
        {
            sum+=p[i].det(p[(i+1)%n]);
        }
        return fabs(sum)/2;
    }
    bool getdir()
    {
        double sum=0;
        int i;
        for (i=0;i<n;i++)
        {
            sum+=p[i].det(p[(i+1)%n]);
        }
        if (dblcmp(sum)>0)return 1;
        return 0;
    }
    point getbarycentre()
    {
        point ret(0,0);
        double area=0;
        int i;
        for (i=1;i<n-1;i++)
        {
            double tmp=p[i].sub(p[0]).det(p[i+1].sub(p[0]));
            if (dblcmp(tmp)==0)continue;
            area+=tmp;
            ret.x+=(p[0].x+p[i].x+p[i+1].x)/3*tmp;
            ret.y+=(p[0].y+p[i].y+p[i+1].y)/3*tmp;
        }
        if (dblcmp(area))ret=ret.div(area);
        return ret;
    }
    double areaintersection(polygon po)
    {
    }
    double areaunion(polygon po)
    {
        return getarea()+po.getarea()-areaintersection(po);
    }
    int circlecover(double r)
    {
        int ans=0,i,j;
        vector<pair<double,int> >v;
        for (i=0;i<n;i++)
        {
            v.clear();
            for (j=0;j<n;j++)if (i!=j)
            {
                point q=p[i].sub(p[j]);
                double d=q.len();
                if (dblcmp(d-2*r)<=0)
                {
                    double arg=atan2(q.y,q.x);
                    if (dblcmp(arg)<0)arg+=2*pi;
                    double t=acos(d/(2*r));
                    v.push_back(make_pair(arg-t+2*pi,-1));
                    v.push_back(make_pair(arg+t+2*pi,1));
                }
            }
            sort(v.begin(),v.end());
            int cur=0;
            for (j=0;j<v.size();j++)
            {
                if (v[j].second==-1)++cur;
                else --cur;
                ans=MAX(ans,cur);
            }
        }
        return ans+1;
    }           
    int pointinpolygon(point q)
    {
        if (getdir())reverse(p,p+n);
        if (dblcmp(q.sub(p[0]).det(p[n-1].sub(p[0])))==0)
        {
            if (line(p[n-1],p[0]).pointonseg(q))return n-1;
            return -1;
        }
        int low=1,high=n-2,mid;
        while (low<=high)
        {
            mid=(low+high)>>1;
            if (dblcmp(q.sub(p[0]).det(p[mid].sub(p[0])))>=0&&dblcmp(q.sub(p[0]).det(p[mid+1].sub(p[0])))<0)
            {
                polygon c;
                c.p[0]=p[mid];
                c.p[1]=p[mid+1];
                c.p[2]=p[0];
                c.n=3;
                if (c.relationpoint(q))return mid;
                return -1;
            }
            if (dblcmp(q.sub(p[0]).det(p[mid].sub(p[0])))>0)
            {
                low=mid+1;
            }
            else 
            {
                high=mid-1;
            }
        }
        return -1;
    }   

	double xmult(point a, point b, point c)
	{
		return (b - a).det(c - a);
	}

	int inside_polygon(point q, int on_edge=1)
	{
		point q2;
		int i=0,count;

		while (i<n)
		{
			for(count = i = 0, q2.x = rand()+10000, q2.y = rand() + 10000; i<n; i++)
				if(dblcmp(xmult(q,p[i],p[(i+1)%n]))==0 && (p[i].x-q.x)*(p[(i+1)%n].x-q.x)<eps && (p[i].y-q.y)*(p[(i+1)%n].y-q.y)<eps)
					return on_edge;
				else if(dblcmp(xmult(q,q2,p[i]))==0)
					break;
				else if(xmult(q,p[i],q2)*xmult(q,p[(i+1)%n],q2)<-eps&&xmult(p[i],q,p[(i+1)%n])*xmult(p[i],q2,p[(i+1)%n])<-eps)
					count++;
		}
		
		return count&1;
	}

	int isdiagonal(int a, int b)
	{
		int i;

		if(a == b || (a + 1)%n == b || (b + 1)%n == a) return 0;

		getline();

		line x(p[a], p[b]);
		for(i = 0; i < n; i++) if(a != i && b != i)
			if(x.pointonseg(p[i]))
				return 0;

		for(i = 0; i < n; i++)
			if(l[i].segcrossseg_inside(x))
				return 0;

		point y = p[a].add(p[b]).div(2.);
		if(inside_polygon(y, 0) == 0) return 0;
		return 1;
	}
};

double height[304][304];
double ans[304];

int main()
{
	int n, k, t;
	int i, j;

	scanf("%d %d", &n, &k);
	for(i = 0; i < n; i++)
		for(j = 0; j <= k; j++)
			scanf("%lf", &height[i][j]);

	for(i = 0; i < n; i++) ans[i] = 0;

	for(i = 1; i <= k; i++)
	{
		for(j = 0; j < n; j++)
		{
			polygon X[2];
			X[0].n = 4;
			X[0].p[0] = point(i - 1, 0);
			X[0].p[1] = point(i, 0);
			X[0].p[2] = point(i, height[j][i]);
			X[0].p[3] = point(i - 1, height[j][i - 1]);

			int u = 0, v = 1;
			for(t = 0; t < j; t++)
			{
				X[u].convexcut(line( point(i, height[t][i]), point(i - 1, height[t][i - 1]) ), X[v]);
				u = 1 - u;
				v = 1 - v;
			}

			ans[j] += X[u].getarea();

		}
	}

	for(i = 0; i < n; i++)
		printf("%.10lf\n", ans[i]);

	return 0;
}