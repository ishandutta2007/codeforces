#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<vector>
#include<map>
#include<set>
#include<string>
#include<queue>
#include<stack>
using namespace std;
#define MOD 1000000007
#define INF (1<<29)
#define LINF (1LL<<60)
#define EPS (1e-10)
typedef long long Int;
typedef pair<Int, Int> P;

class Vec{
public:
    double x, y;
    Vec(double x = 0, double y = 0):x(x),y(y){}

    Vec &read(){
        cin >> x >> y;
        return *this;
    }

    void print(){
        printf("%.10lf %.10lf\n", x, y);
    }

    bool operator<(const Vec &other) const{
        if(x < other.x)return true;
        if(x == other.x && y < other.y)return true;
        return false;
    }
    
    Vec operator+(const Vec &other)
        {
            Vec result = *this;
            result.x += other.x;
            result.y += other.y;
            return result;
        }

    Vec operator-(const Vec &other)
        {
            Vec result = *this;
            result.x -= other.x;
            result.y -= other.y;
            return result;
        }

    Vec operator*(const double &k)
        {
            Vec result = *this;
            result.x *= k;
            result.y *= k;
            return result;
        }

    Vec operator/(const double &k)
        {
            Vec result = *this;
            result.x /= k;
            result.y /= k;
            return result;
        } 
    
    double cross(const Vec &other)
        {
            return x*other.y - y*other.x;
        }

    double dot(const Vec &other){
        return x*other.x + y*other.y;
    }
    
    bool operator==(const Vec &other) const
        {
            return abs(x - other.x) < EPS && abs(y - other.y) < EPS;
        }

    bool operator!=(const Vec &other) const
        {
            return !(*this == other);
        }

    double norm()
        {
            return sqrt(x*x+y*y);
        }

    double norm2()
        {
            return x*x+y*y;
        }

    Vec standard(){
        Vec result = *this;
        return result/result.norm();
    }
};

//cw:1, ccw:-1, other:0
Int CCW(Vec a, Vec b, Vec c){
    b = b - a;
    c = c - a;
    if(b.cross(c) > EPS)return -1;
    if(b.cross(c) < -EPS)return 1;
    return 0;
}

double dist(Vec a, Vec b){
    return (a-b).norm();
}

// needs geometry-vector
class Line{
public:
    Vec a, b;
    Vec vect;
    Line(Vec a = Vec(), Vec b = Vec()):a(a),b(b),vect(b-a){}

    //projection
    Vec proj(Vec p){
        p = p - a;
        return a + vect * vect.dot(p) / vect.norm2();
    }

    //reflection
    Vec reflect(Vec p){
        return proj(p) * 2 - p;
    }

    bool onSegment(Vec p){
        return abs((p-a).cross(b-a)) < EPS && (p-a).dot(p-b) < EPS;
    }

    //other -> LineSegment(not inclusive), this -> Line
    bool _intersect(Line other){
        return CCW(a, b, other.a) * CCW(a, b, other.b) < 0;
    }

    //other, this: both are LineSegment(inclusive)
    bool intersect(Line other){
        return onSegment(other.a) || onSegment(other.b) || other.onSegment(a) || other.onSegment(b) || (_intersect(other) && other._intersect(*this));
    }

    //low accuracy
    Vec crossPoint(Line &other){
        double ratio = (a - other.a).cross(vect) / other.vect.cross(vect);
        return other.a + other.vect * ratio;
    }

    double dist(Vec p){
        Vec pp = proj(p);
        if(onSegment(pp))return ::dist(p, pp);
        else return min(::dist(p, a), ::dist(p, b));
    }
    
    double dist(Line &other){
        if(intersect(other))return 0;
        return min(min(dist(other.a), dist(other.b)), min(other.dist(a), other.dist(b)));
    }
};



//needs line
class Polygon{
public:
    vector<Vec> points;
    Int n;
    Polygon(){}
    void read(Int _n){
        n = _n;
        points.clear();
        while(_n--)points.push_back(Vec().read());
    }
    Polygon &set(vector<Vec> &v){
        points = v;
        n = points.size();
        return *this;
    }
    Vec& operator[](int index)
        {
            index %= n;
            if(index < 0)index += n;
            return points[index];
        }
    //Signed Area
    double area(){
        double area = 0;
        for(int i = 0;i < n;i++){
            area += points[i].cross(points[(i+1)%n]);
        }
        return area / 2;
    }

    //inside:2, onEdge:1, outside:0
    Int inPolygon(Vec p){
        Int crossCount = 0;
        Line halfLine(p, Vec(p.x+1,INF));
        for(int i = 0;i < n;i++){
            if(Line(points[i], points[(i+1)%n]).onSegment(p))return 1;
            if(Line(points[i], points[(i+1)%n]).intersect(halfLine))crossCount++;
            if(halfLine.onSegment(points[i])){
                crossCount--;
            }

        }
        return (crossCount%2)*2;
    }
};

//needs polygon
//OnLine OK
Polygon convexHull(vector<Vec> points){
    sort(points.begin(), points.end());
    if(points.size() <= 2)return Polygon().set(points);
    vector<Vec> res;
    int n = points.size();
    for(int i = 0;i < n;i++){
        while(res.size() > 1 && CCW(res[res.size() - 2], res[res.size() - 1], points[i]) == 1)res.pop_back();
        res.push_back(points[i]);
    }
    int k = res.size();
    for(int i = n-2;i >= 0;i--){
        while(res.size() > k && CCW(res[res.size() - 2], res[res.size() - 1], points[i]) == 1)res.pop_back();
        res.push_back(points[i]);
    }
    res.pop_back();
    return Polygon().set(res);
}


bool used[108000];
Int n;

int main(){
    cin >> n;
    vector<Vec> points(n);
    for(int i = 0;i < n;i++){
        cin >> points[i].x >> points[i].y;        
    }
    Polygon ch = convexHull(points);
    int current = 0;
    while(points[current] != ch[0])current++;
    cout << current + 1 << endl;
    string s;
    cin >> s;

    s += '1';
    for(char c:s){
        int pos = 0;
        while(ch[pos] != points[current])pos++;
        if(c == 'L')pos++;
        else pos--;
        int nxt = 0;
        while(points[nxt] != ch[pos])nxt++;
        cout << nxt + 1 << endl;
        used[current] = true;
        current = nxt;
        vector<Vec> tmp;
        for(int i = 0;i < n;i++)if(!used[i])tmp.push_back(points[i]);
        ch = convexHull(tmp);
    }
    return 0;
}