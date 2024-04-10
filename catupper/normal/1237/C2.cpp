#include<iostream>
#include<cstdio>
#include<algorithm>
#include<map>
#include<vector>
using namespace std;
typedef pair<int, int> P;
typedef pair<P, P> Q;

vector<Q> points;


Q l, r, x, y;
int n;
int main(){
    scanf("%d", &n);
    for(int i = 0;i < n;i++){
        int x, y, z;
        scanf("%d%d%d", &x, &y, &z);
        points.push_back(Q(P(x, y),P(z,i+1)));
    }
    sort(points.begin(), points.end());
    for(int i = 0;i < n/2;i++){
        Q a = points.back();points.pop_back();
        Q b = points.back();points.pop_back();
        if(points.empty()){
            printf("%d %d\n", a.second.second, b.second.second);
            continue;
        }
        Q c = points.back();points.pop_back();
        Q d = points.back();points.pop_back();
        if(b.first.first != c.first.first || a.first.first == b.first.first && a.first.second == b.first.second){
            printf("%d %d\n", a.second.second, b.second.second);
            points.push_back(d);
            points.push_back(c);
        }
        else if(b.first.second == c.first.second || c.first.first != d.first.first || c.first.second != d.first.second){
            printf("%d %d\n", b.second.second, c.second.second);
            points.push_back(d);
            points.push_back(a);
        }
        else
        {
            printf("%d %d\n", c.second.second, d.second.second);
            points.push_back(b);
            points.push_back(a);

        }
        
    }
    return 0;
}