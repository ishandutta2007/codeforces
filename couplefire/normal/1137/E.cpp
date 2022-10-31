#include <bits/stdc++.h>
using namespace std;
#define MAXN 300005

struct point{
    long long pos; long long add;
    point(long long pp, long long aa){pos = pp, add = aa;};
};

long long prefixB[MAXN] = {0};
long long prefixS[MAXN] = {0};
long long idx = 0;
long long cur = 1;
vector<point> points;

long long getX(point a){
    return a.pos;
}

long long getY(point a){
    return prefixB[cur]-prefixB[a.add-1]+a.pos*(prefixS[cur]-prefixS[a.add-1]);
}

long double slope(point a, point b){
    return (0.0+getY(b)-getY(a))/(0.0+getX(b)-getX(a));
}

void goPop(){
    while(points.size() > 1 && slope(points.back(), points[points.size()-2]) >= 0) points.pop_back();
}

int main(){
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    long long n, m; cin >> n >> m;
    points.push_back({idx,1});
    idx = n;
    for(; cur<=m; cur++){
        long long t; cin >> t;
        if(t == 1){
            long long k; cin >> k;
            points.clear();
            points.push_back({0,cur});
            prefixB[cur] = prefixB[cur-1];
            prefixS[cur] = prefixS[cur-1];
            idx += k;
        }
        else if(t == 2){
            long long k; cin >> k;
            point pp = {idx, cur};
            // cout << points.size() << endl;
            while(points.size()>1 && slope(points.back(),pp) < slope(points[points.size()-2], points.back())){
                points.pop_back();
            }
            points.push_back(pp);
            idx += k;
            prefixB[cur] = prefixB[cur-1];
            prefixS[cur] = prefixS[cur-1];
        }
        else{
            long long b, s; cin >> b >> s;
            prefixB[cur] = prefixB[cur-1]+b;
            prefixS[cur] = prefixS[cur-1]+s;
        }
        goPop();
        cout << points.back().pos+1 << " " << getY(points.back()) << endl;
    }
}