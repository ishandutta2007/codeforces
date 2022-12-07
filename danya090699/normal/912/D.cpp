#include <bits/stdc++.h>
#define int long long
using namespace std;
int n, m, r, k;
int go[4][2]={{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
int mi(int a, int b)
{
    if(a<b) return a;
    else return b;
}
int ma(int a, int b)
{
    if(a<b) return b;
    else return a;
}
int f(int x, int y)
{
    int ve=mi(x, n-r)-ma(0, x+1-r)+1;
    int go=mi(y, m-r)-ma(0, y+1-r)+1;
    return ve*go;
}
main()
{
    //freopen("input.txt", "r", stdin);
    cin>>n>>m>>r>>k;
    int q=(n-r+1)*(m-r+1);
    double an=0;
    set <pair <int, int> , greater < pair <int, int> > > se;
    se.insert(make_pair(f(n/2, m/2), (n/2)*m+m/2));
    set <int> us;
    us.insert((n/2)*m+m/2);
    while(k)
    {
        int va=(*se.begin()).first;
        int cu=(*se.begin()).second;
        int cx=cu/m, cy=cu%m;
        an+=va*1.0/q;
        se.erase(se.begin()), us.insert(cu);
        for(int a=0; a<4; a++)
        {
            int x=cx+go[a][0], y=cy+go[a][1];
            if(x>=0 and x<n and y>=0 and y<m)
            {
                int ne=x*m+y;
                if(us.find(ne)==us.end()) se.insert(make_pair(f(x, y), ne));
            }
        }
        k--;
    }
    cout<<fixed<<setprecision(10)<<an;
}