#include <bits/stdc++.h>
#define db(x) cout << (x) << '\n';
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pii;
typedef pair<pii,pii> ppp;

bool check(vector<ppp> args)
{
    if(args.size()==1)
        return 1;
    vector<int> xs1,xs2,ys1,ys2;
    for(auto y : args)
    {
//        cout << y.first.first << ' ' << y.first.second << ' ' << y.second.first << ' ' << y.second.second << '\n';
        xs1.push_back(y.first.first);
        xs2.push_back(y.second.first);
        ys1.push_back(y.first.second);
        ys2.push_back(y.second.second);
    }

    sort(xs1.begin(),xs1.end());
    sort(xs2.begin(),xs2.end());
    sort(ys1.begin(),ys1.end());
    sort(ys2.begin(),ys2.end());

    int t=-1,v=0,n=args.size();
    for(auto y : args)
    {
        int a=y.first.first;
        int b=y.first.second;
        int pa1=lower_bound(xs1.begin(),xs1.end(),a)-xs1.begin();
        int pa2=lower_bound(xs2.begin(),xs2.end(),a+1)-xs2.begin();
        int ca=pa1-pa2;
        if(!ca && pa1)
        {
            t=0;
            v=a;
        }

        int pb1=lower_bound(ys1.begin(),ys1.end(),b)-ys1.begin();
        int pb2=lower_bound(ys2.begin(),ys2.end(),b+1)-ys2.begin();
        int cb=pb1-pb2;
        if(!cb && pb1)
        {
            t=1;
            v=b;
        }
    }
    if(t==-1)
        return 0;

    vector<ppp> p1,p2;
    for(auto y : args)
    {
        if(t)
        {
            if(y.first.second>=v)
                p2.push_back(y);
            else
                p1.push_back(y);
        }
        else
        {
            if(y.first.first>=v)
                p2.push_back(y);
            else
                p1.push_back(y);
        }
    }

    return check(p1) && check(p2);
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll n,x1,x2,y1,y2;
    cin >> n;
    vector<ppp> res;
    for(int i=0;i<n;i++)
    {
        cin >> x1 >> y1 >> x2 >> y2;
        res.push_back(ppp(pii(x1,y1),pii(x2,y2)));
    }

    bool ok=check(res);
    if(ok)
        db("YES")
    else
        db("NO")

    return 0;
}