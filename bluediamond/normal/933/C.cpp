#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
bool home = 1;

mt19937 rng(10000);
uniform_real_distribution<ld> distrib(0,10);

const ld eps=1e-14;
ld ang;

struct Circle{
        ld x;
        ld y;
        ld r;
};

struct Point{
        ld x;
        ld y;
};

bool is_eq(ld a,ld b){
        return abs(a-b)<eps;
}

bool operator < (Point a,Point b){
        if(!is_eq(a.x,b.x))return a.x<b.x;
        if(!is_eq(a.y,b.y))return a.y<b.y;
        return 0;
}

bool operator == (Point a,Point b) {
        return is_eq(a.x,b.x)&&is_eq(a.y,b.y);
}

ld sqr(ld x){
        return x*x;
}

void rot(ld &x,ld &y,ld ang){

        ld X,Y;
        X = x*cos(ang) - y*sin(ang);
        Y = x*sin(ang) + y*cos(ang);
        x = X;
        y = Y;
}

vector<Point> get(Circle F,Circle S){
        vector<Point> sol;
        ld x2=S.x-F.x;
        ld y2=S.y-F.y;
        ld r2=S.r;
        ld r1=F.r;
        ld ang=atan2(x2,y2);
        rot(x2,y2,ang);
        assert(is_eq(x2,0));

        ld y=(sqr(r1)-sqr(r2)+sqr(y2))/(2*y2);

        ld x_sq=r1*r1-y*y;

        if(x_sq<-eps) return sol;

        if(is_eq(x_sq,0)){
                x_sq=0;
        }

        x_sq=max(x_sq,(ld)0);

        sol.push_back({-sqrt(x_sq),y});
        sol.push_back({+sqrt(x_sq),y});

        for(auto&it:sol){
                rot(it.x,it.y,-ang);

                it.x+=F.x;
                it.y+=F.y;
        }


        /**
        for(auto&it:sol){
                cout<<" = "<<fixed<<setprecision(10)<<sqr(F.x-it.x)+sqr(F.y-it.y)-F.r*F.r<<"\n";
                cout<<" = "<<fixed<<setprecision(10)<<sqr(S.x-it.x)+sqr(S.y-it.y)-S.r*S.r<<"\n";
        }
        **/
        return sol;
}



signed main() {
#ifdef ONLINE_JUDGE
  home = 0;
#endif


        if (home) {
                freopen("iron_man.txt", "r", stdin);
        }
        else {
                ios::sync_with_stdio(0); cin.tie(0);
        }


        int n;
        cin>>n;
        assert(n<=3);
        vector<Circle> circles(n);
        for(auto&circle:circles){

                cin>>circle.x>>circle.y>>circle.r;
        }

        vector<set<Point>> fr(n);
        for(int i=0;i<n;i++){
                for(int j=i+1;j<n;j++){
                        Circle a=circles[i];
                        Circle b=circles[j];
                        vector<Point> pts=get(a,b);
                        for(auto&pt:pts){
                                fr[i].insert(pt);
                                fr[j].insert(pt);
                        }
                }
        }

        int single=0;

        vector<int> good;
        for(int i=0;i<n;i++){
                if(fr[i].empty()){
                        single++;
                }else{
                        good.push_back(i);
                }
        }
        int comps;
        if(n==1){
                assert(single==1);
                comps=0;
        }
        if(n==2){
                assert(single==0||single==2);
                if(single==0){
                        comps=1;
                }else{
                        assert(single==2);
                        comps=0;
                }
        }

        if(n==3){
                assert(single==0||single==1||single==3);
                if(single==0){
                        comps=1;
                }else{
                        if(single==1){
                                comps=1;
                        }else{
                                assert(single==3);
                                comps=0;
                        }
                }
        }
        int e=0;
        set<Point> pt;
        for(auto&i:good){
                e+=(int)fr[i].size();
                for(auto&p:fr[i]){
                        pt.insert(p);
                }
        }
        int v=(int)pt.size();
        cout<<e-v+comps+1+single<<"\n";
}