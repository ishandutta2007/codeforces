#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#include <bits/stdc++.h>
using namespace std;

const double rot = 234.0;
const double eps = (double)1.0/1000000000.0;
const int maxn = 1000005;

struct point{
    double x, y;
    point(double xx, double yy){x = xx, y = yy;}
    double mag(){return sqrt((long double)x*x+(long double)y*y);}
};

struct line{
    double m, c;
    line(double mm, double cc){m = mm, c = cc;}
};

double dist(point a, point b){
    return sqrt(((long double)a.x-b.x)*((long double)a.x-b.x)+((long double)a.y-b.y)*((long double)a.y-b.y));
}

line pointslope(point a, double m){
    return line(m, -a.x*m+a.y);
}

line pointpoint(point a, point b){
    double m = (b.y-a.y)/(b.x-a.x);
    return pointslope(a, m);
}

point intersect(line a, line b){
    double x = (b.c-a.c)/(a.m-b.m);
    double y = a.m*x+a.c;
    return {x, y};
}

double shoelace(vector<point> arr){
    int n = arr.size(); arr.push_back(arr.front());
    double res = 0;
    for(int i = 0; i<n; i++){
        res += (arr[i].x*arr[i+1].y-arr[i].y*arr[i+1].x)/2;
    }
    return abs(res);
}

point rotate(point a, double ang){
    double r = a.mag(), aa = atan2(a.y, a.x);
    return {r*cos(aa+ang), r*sin(aa+ang)};
}

double width, height; int n;
vector<pair<point, point>> arr[maxn];
double area[maxn];

int main(){
    scanf("%lf %lf %d", &width, &height, &n);
    for(int i = 0; i<n; i++){
        int k; scanf("%d", &k);
        vector<point> tmp;
        for(int j = 0; j<k; j++){
            double a, b; scanf("%lf %lf", &a, &b);
            tmp.push_back({a, b});
            tmp.back() = rotate(tmp.back(), rot);
        }
        area[i] = shoelace(tmp);
        tmp.push_back(tmp.front());
        for(int j = 0; j<k; j++) arr[i].push_back({tmp[j], tmp[j+1]});
    }
    int q; scanf("%d", &q);
    for(int i = 0; i<q; i++){
        double rx, ry, r; scanf("%lf %lf %lf", &rx, &ry, &r);
        point center = {rx, ry};
        center = rotate(center,rot);
        double tot = 0;
        vector<int> ids;
        bool flag = false;
        for(int id = 0; id<n; id++){
            int cnt = 0;
            for(pair<point, point> pp: arr[id]){
                point a = pp.first, b = pp.second;
                if(dist(a, center) <= r+eps || dist(b, center) <= r+eps){
                    tot += area[id]; ids.push_back(id);
                    flag = 1;
                    break;
                }
                line cur = pointpoint(a, b);
                line perp = pointslope(center, -1.0/cur.m);
                point bruh = intersect(cur, perp);
                if(dist(bruh, center) <= r+eps && ((a.x <= bruh.x+eps && bruh.x <= b.x+eps) || (b.x <= bruh.x+eps && bruh.x <= a.x+eps))){
                    tot += area[id]; ids.push_back(id);
                    flag = 1;
                    break;
                }

                line para(0, center.y);
                point lol = intersect(cur, para);
                if(lol.x+eps > center.x) continue;
                if(((a.x <= lol.x+eps && lol.x <= b.x+eps) || (b.x <= lol.x+eps && lol.x <= a.x+eps))) cnt++;
            }
            if(!flag && (cnt&1)){
                tot += area[id]; ids.push_back(id);
            }
        }
        printf("%lf %d ", tot, (int)ids.size());
        for(int x : ids) printf("%d ", x);
        printf("\n");
    }
}