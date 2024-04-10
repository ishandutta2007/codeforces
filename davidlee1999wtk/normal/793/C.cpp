#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<vector>
#include<queue>
#include<map>
#include<set>
#include<stack>
#include<cstdlib>
#include<string>
#include<bitset>
#include<iomanip>
#include<deque>
#include<utility>
#define INF 1000000000
#define fi first
#define se second
#define N 100005
#define debug(x) cerr<<#x<<"="<<x<<endl
#define MP(x,y) make_pair(x,y)
using namespace std;
typedef long long LL;
typedef pair<int, int> pii;
typedef double Double;
struct Vector
{
    Double x, y;
    Vector(Double X = 0, Double Y = 0)
    {
        x = X, y = Y;
    }
    void Print(string name)
    {
        debug(name);
        cout << x << ' ' << y << endl;
        cout << endl;
    }
};


typedef Vector Point;
typedef vector<Point> Polygon;

const Double eps = 1e-11;
const Double pi = acos(-1.0);
Vector operator + (Vector A, Vector B) { return Vector(A.x + B.x, A.y + B.y); }
Vector operator - (Vector A, Vector B) { return Vector(A.x - B.x, A.y - B.y); }
Vector operator * (Vector A, Double p) { return Vector(A.x*p, A.y*p); }
Vector operator / (Vector A, Double p) { return Vector(A.x / p, A.y / p); }

bool operator < (const Vector& a, const Vector& b)
{
    return a.x<b.x || (a.x == b.x&&a.y<b.y);
}

int dcmp(Double x)
{
    if (fabs(x)<eps) return 0;
    else return x<0 ? -1 : 1;
}

bool operator == (const Vector& a, const Vector& b)
{
    return dcmp(a.x - b.x) == 0 && dcmp(a.y - b.y) == 0;
}

Double Dot(Vector A, Vector B)
{
    return A.x*B.x + A.y*B.y;
}

Double Len(Vector A)
{
    return sqrt(Dot(A, A));
}

Double Angle(Vector A, Vector B)
{
    return acos(Dot(A, B) / Len(A) / Len(B));
}

Double Angle(Vector A)
{
    return atan2(A.y, A.x);
}

Double Cross(Vector A, Vector B)
{
    return A.x*B.y - A.y*B.x;
}

Double Area2(Point A, Point B, Point C)
{
    return Cross(B - A, C - A);
}

Vector Rotate(Vector A, Double rad)  //counter-clockwise
{
    return Vector(A.x*cos(rad) - A.y*sin(rad), A.x*sin(rad) + A.y*cos(rad));
}

Vector Normal(Vector A) //Unit normal vector A
{
    Double L = Len(A);
    return Vector(-A.y / L, A.x / L);
}

struct Line
{
    Point P;
    Vector v;
    double ang;
    Line() {}
    Line(Point P, Vector v) :P(P), v(v)
    {
        ang = atan2(v.y, v.x);
    }
    bool operator<(const Line &L) const
    {
        return ang<L.ang;
    }
};

bool OnLeft(Line L, Point p)
{
    return dcmp(Cross(L.v, p - L.P))>0; //?????
}

int SameDir(Vector u, Vector v) //1-1
{
    return Dot(u, v) > 0 ? 1 : -1;
}

Point GLI(Point P, Vector v, Point Q, Vector w)
{
    Vector u = P - Q;
    Double t = Cross(w, u) / Cross(v, w);
    return P + v*t;
}

Point GLI(Line a, Line b)
{
    Vector u = a.P - b.P;
    Double t = Cross(b.v, u) / Cross(a.v, b.v);
    return a.P + a.v*t;
}

Double DisTL(Point P, Point A, Point B)
{
    Vector v1 = B - A, v2 = P - A;
    return fabs(Cross(v1, v2) / Len(v1));
}

Double DisTS(Point P, Point A, Point B)
{
    if (A == B) return Len(P - A);
    Vector v1 = B - A, v2 = P - A, v3 = P - B;
    if (dcmp(Dot(v1, v2))<0) return Len(v2);
    else if (dcmp(Dot(v1, v3))>0) return Len(v3);
    else return fabs(Cross(v1, v2)) / Len(v1);
}

bool OnSegment(Point P, Point A, Point B)
{
    return dcmp(DisTL(P, A, B)) == 0 && dcmp(Dot(P - A, P - B))<0 && !(P == A) && !(P == B);
}

double calc_time(Vector u, Vector v)
{
    //debug(SameDir(u, v));
    //debug(Dot(u, v));
    return Len(u) / Len(v) * SameDir(u, v);
}

int PInP(Point p, Point* poly, int n)
{
    int wn = 0, k, d1, d2;
    for (int i = 0; i<n; i++)
    {
        if (dcmp(DisTS(p, poly[i], poly[(i + 1) % n]) == 0)) return -1;
        k = dcmp(Cross(poly[(i + 1) % n] - poly[i], p - poly[i]));
        d1 = dcmp(poly[i].y - p.y);
        d2 = dcmp(poly[(i + 1) % n].y - p.y);
        if (k>0 && d1 <= 0 && d2>0) wn++;
        if (k<0 && d2 <= 0 && d1>0) wn--;
    }
    if (wn) return 1;
    else return 0;
}

double in[N], out[N];
double x_1, y_1, x_2, y_2;
Point pt[4];
Line line[4];
int main()
{
    int n, i, k;
    cin >> n;
    cin >> x_1 >> y_1 >> x_2 >> y_2;
    pt[0] = Point(x_1, y_1);
    pt[1] = Point(x_2, y_1);
    pt[2] = Point(x_2, y_2);
    pt[3] = Point(x_1, y_2);
    for (i = 0; i < 4; i++)
        line[i] = Line(pt[i], pt[(i + 1) % 4] - pt[i]);
    for (i = 1; i <= n; i++)
    {
        Point ms;
        Vector dv;
        Line tra;
        vector<int> in_p_num;
        vector<double> in_tm;
        scanf("%lf%lf%lf%lf", &ms.x, &ms.y, &dv.x, &dv.y);
        if (dcmp(Dot(dv, dv)) == 0) //0
        {
            if (PInP(ms, pt, 4) == 1)
                in[i] = 0, out[i] = INF;
            else
            {
                printf("-1\n");
                return 0;
            }
            continue;
        }
        tra = Line(ms, dv);
        //
        for (k = 0; k < 4; k++)
            if (dcmp(Cross(pt[k] - ms, dv) / Len(dv)) == 0)
            {
                in_tm.push_back(calc_time(pt[k] - ms, dv));
                in_p_num.push_back(k);
            }

        Point I_P;
        for (k = 0; k < 4; k++)
        {
            //debug(i);
            //debug(k);
            if (dcmp(Cross(line[k].v, dv)) != 0)
            {
                I_P = GLI(line[k], tra);
                //debug(tra.P.x);
                //debug(tra.P.y);
                //debug(tra.v.x);
                //debug(tra.v.y);
                //debug(i);
                //I_P.Print("I_P");
                //debug(i);
                //debug(k);
                if (OnSegment(I_P, pt[k], pt[(k + 1) % 4]))
                    in_tm.push_back(calc_time(I_P - ms, dv));
            }
        }
        if (in_p_num.size() == 2)
            if((in_p_num[0]^in_p_num[1])!=2)
            {
                printf("-1\n");
                return 0;
            }
        if (in_tm.size() == 2)
        {
            sort(in_tm.begin(), in_tm.end());
            in[i] = in_tm[0];
            out[i] = in_tm[1];
        }
        else
        {
            printf("-1\n");
            return 0;
        }
    }
    double l = *max_element(in + 1, in + 1 + n), r = *min_element(out + 1, out + 1 + n);
    //debug(l);
    //debug(r);
    l = max(l, 0.0);
    
    if (dcmp(r - l) > 0)
        printf("%.12f\n", l);
    else printf("-1\n");
    return 0;
}
// davidlee1999WTK 2016/
// srO myk Orz
// ios::sync_with_stdio(false);
//#pragma comment(linker, "/STACK:102400000,102400000") compiler c++,not g++
/*
1
0 0 1 1
0.5 0.5 1 0

1
99998 99998 99999 99999
0 0 99999 100000
*/