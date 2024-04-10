#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const double eps=1e-9;
bool eq(double a,double b){return (abs(a-b)<eps);}
bool smaller(double a,double b){return (!eq(a,b)&&a<b);}

struct point
{
    double x=0,y=0;
    bool operator==(const point &o)const{return (eq(x,o.x)&&eq(y,o.y));}
    bool operator<(const point &o)const{return (smaller(x,o.x)||(eq(x,o.x)&&smaller(y,o.y)));}
};

struct shape
{
    double x=0,y=0;
    int m=0;
    friend shape operator+(shape a,shape b)
    {
        shape c;
        c.m=a.m+b.m;
        c.x=(a.x*a.m+b.x*b.m)/c.m;
        c.y=(a.y*a.m+b.y*b.m)/c.m;
        return c;
    }
};

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    n/=2;
    const int N=18;
    vector<pair<shape,string>> all[N+1];
    vector<pair<point,string>> v[N+1][N*N+1];
    function<void(int,int,string,shape)> gen=[&](int x,int y,string s,shape a)
    {
        if(x==n)
        {
            all[y].push_back({a,s});
            v[y][a.m].push_back({point{2*n-a.x,a.y},s});
            return;
        }
        shape up=shape{x+2.0/3,y+1.0/3,1}+shape{x+0.5,y/2.0,2*y};
        gen(x+1,y+1,s+"(",a+up);
        if(y>0)
        {
            shape down=shape{x+1.0/3,y-2.0/3,1}+shape{x+0.5,(y-1)/2.0,2*(y-1)};
            gen(x+1,y-1,s+")",a+down);
        }
    };
    gen(0,0,"",shape());
    for(int y=0;y<=n;y++) for(int a=0;a<=n*n;a++) sort(v[y][a].begin(),v[y][a].end());
    double x,y;
    cin >> x >> y;
    for(int h=0;h<=n;h++)
    {
        for(auto [a,s]:all[h])
        {
            auto [x1,y1,a1]=a;
            for(int a2=0;a2<=n*n;a2++)
            {
                double x2=(x*(a1+a2)-x1*a1)/a2;
                double y2=(y*(a1+a2)-y1*a1)/a2;
                auto it=lower_bound(v[h][a2].begin(),v[h][a2].end(),make_pair(point{x2,y2},string()));
                if(it!=v[h][a2].end()&&(*it).first==point{x2,y2})
                {
                    string res=s;
                    string tmp=(*it).second;
                    reverse(tmp.begin(),tmp.end());
                    for(char &c:tmp) c=(c=='('?')':'(');
                    cout << res+tmp << "\n";
                    exit(0);
                }
            }
        }
    }
    return 0;
}