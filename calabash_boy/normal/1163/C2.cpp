#include <bits/stdc++.h>
using namespace std;
template<class type> 
struct point{
    type x,y;
    point(){};
    point(type x_,type y_):x(x_),y(y_){}
    point operator +(const point &p)const {return point(x + p.x,y + p.y);}
    point operator -(const point &p)const {return point(x - p.x,y - p.y);}
    //a related to b
    //clockwise : positive
    //anti-clockwise : negative
    //share a line : zero
    type cross(const point &p)const {return x * p.y - y * p.x;}
};
typedef point<long long> pt;
const int maxn = 1000+ 5;
vector<pair<pt,pt>> lines;

int n;
pt points[maxn];
int main(){
    cin>>n;
    for (int i=1;i<=n;i++){
        long long x,y;
        cin>>x>>y;
        points[i] = pt(x,y);
    }
    sort(points+ 1,points+ 1 + n,[](pt pa,pt pb){
        return pa.y == pb.y? pa.x < pb.x: pa.y < pb.y;   
        
    }); 
    for (int i=1;i<=n;i++){
        for (int j=i+1;j<=n;j++){
            pt vec = points[j] - points[i];
            lines.push_back(make_pair(points[i],vec));
        }
    }    
    int N = 0;
    sort(lines.begin(),lines.end(),[](pair<pt,pt> x,pair<pt,pt> y){
        return x.second.cross(y.second) < 0; 
    });
    long long ans = 0;
    vector<pair<pt,pt> > group;
    pt vec;
    for (int i=0;i<lines.size();i++){
        if (i == 0 || vec.cross(lines[i].second)!= 0){
            int sz = group.size();
            ans -= 1ll * sz * (sz - 1) / 2;
            group.clear();
            N ++;
            group.push_back(lines[i]);
            vec = lines[i].second;
        }else{
            bool same = false;
            for (auto pr : group){
                if (vec.cross(pr.first - lines[i].first) == 0){
                    same = true;
                    break;
                }
            }
            if (!same){
                group.push_back(lines[i]);
                N++;
            }

        }
    }
    int sz = group.size();
    ans -= 1ll *sz * (sz - 1 ) /2 ; 
    ans += 1ll * N * (N- 1)/ 2;
    cerr<<N<<endl;
    cout<<ans<<endl;
    return 0;
}