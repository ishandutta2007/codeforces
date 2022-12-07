#include <bits/stdc++.h>
using namespace std;
double eps=1e-9;
struct comp
{
    bool operator()(const pair <double, double> &l, const pair <double, double> &r) const
    {
        if(abs(l.first-r.first)>eps) return l.first<r.first;
        else if(abs(l.second-r.second)>eps) return l.second<r.second;
        else return false;
    }
};
int main()
{
    //freopen("input.txt", "r", stdin);
    int n, rq=0, cq=0;
    cin>>n;
    int ar[n][3];
    for(int a=0; a<n; a++) for(int b=0; b<3; b++) cin>>ar[a][b];
    set <pair <double, double>, comp> ve;
    for(int a=0; a<n; a++)
    {
        set <pair <double, double>, comp> se;
        for(int b=0; b<n; b++)
        {
            if(b!=a)
            {
                int x1=ar[a][0], y1=ar[a][1], r1=ar[a][2], x2=ar[b][0], y2=ar[b][1], r2=ar[b][2];
                if(!(x1==x2 and y1==y2))
                {
                    double a1=2*x1-2*x2, b1=2*y1-2*y2, c1=-pow(x1, 2)+pow(x2, 2)-pow(y1, 2)+pow(y2, 2)+pow(r1, 2)-pow(r2, 2), a2, b2, c2;
                    a2=b1, b2=-a1, c2=-a2*x1-b2*y1;
                    double x0=(-c1*b2+c2*b1)/(a1*b2-a2*b1);
                    double y0=(-c1*a2+c2*a1)/(b1*a2-b2*a1);
                    double d=pow(x0-x1, 2)+pow(y0-y1, 2);
                    if(d-pow(r1, 2)>eps) continue;
                    else if(abs(d-pow(r1, 2))<eps) se.insert(make_pair(x0, y0));
                    else
                    {
                        double k=sqrt((pow(r1, 2)-d)/(pow(a1, 2)+pow(b1, 2)));
                        double x3=x0+b1*k, y3=y0-a1*k, x4=x0-b1*k, y4=y0+a1*k;
                        se.insert(make_pair(x3, y3));
                        se.insert(make_pair(x4, y4));
                    }
                }
            }
        }
        if(se.size())
        {
            rq+=se.size();
            for(auto it=se.begin(); it!=se.end(); it++) ve.insert(*it);
        }
        else cq++;
    }
    if(cq<n) cq++;
    cout<<rq-ve.size()+cq+1;
}