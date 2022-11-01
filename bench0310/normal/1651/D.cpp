#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    const int N=200000;
    vector<array<int,2>> p(n);
    vector<array<int,2>> one[2*N+1];
    vector<array<int,2>> two[2*N+1];
    vector<array<int,2>> tmpx[N+1];
    vector<array<int,2>> tmpy[N+1];
    auto op=[&](int x,int y)->int{return (x+y);};
    auto tp=[&](int x,int y)->int{return (x-y+N);};
    for(int i=0;i<n;i++)
    {
        auto &[x,y]=p[i];
        cin >> x >> y;
        one[op(x,y)].push_back({x,i});
        two[tp(x,y)].push_back({x,i});
        tmpx[x].push_back({y,i});
        tmpy[y].push_back({x,i});
    }
    vector<int> pos_one(n,-1);
    vector<int> pos_two(n,-1);
    vector<int> pos_tmpx(n,-1);
    vector<int> pos_tmpy(n,-1);
    auto ini=[&](vector<array<int,2>> &v,vector<int> &pos)
    {
        ranges::sort(v);
        for(int i=0;i<(int)v.size();i++) pos[v[i][1]]=i;
    };
    for(int i=0;i<=2*N;i++)
    {
        ini(one[i],pos_one);
        ini(two[i],pos_two);
        if(i<=N)
        {
            ini(tmpx[i],pos_tmpx);
            ini(tmpy[i],pos_tmpy);
        }
    }
    vector<array<int,2>> z={{1,0},{-1,0},{0,-1},{0,1}};
    for(int o=0;o<n;o++)
    {
        auto [x,y]=p[o];
//        cout << "in [" << x << "," << y << "]" << endl;
        auto [resx,resy]=[&]()->array<int,2>
        {
            for(int d=1;;d++)
            {
//                cout << "d=" << d << endl;
                auto mv=[&](int id)->array<int,2>{return {x+d*z[id][0],y+d*z[id][1]};};
                for(int k=-1;k<=1;k+=2)
                {
                    //x
                    int pos=pos_tmpx[o];
                    if(!(0<=pos+k*d&&pos+k*d<(int)tmpx[x].size()&&tmpx[x][pos+k*d][0]==y+k*d)) return {x,y+k*d};
                    //y
                    pos=pos_tmpy[o];
                    if(!(0<=pos+k*d&&pos+k*d<(int)tmpy[y].size()&&tmpy[y][pos+k*d][0]==x+k*d)) return {x+k*d,y};
                }
                vector<int> id={tmpy[y][pos_tmpy[o]+d][1],tmpy[y][pos_tmpy[o]-d][1],tmpx[x][pos_tmpx[o]-d][1],tmpx[x][pos_tmpx[o]+d][1]};
                vector<array<int,3>> opt={{1,3,2},{3,0,1},{1,2,1},{2,0,2}};
                for(auto [l,r,t]:opt)
                {
                    auto [lx,ly]=mv(l);
                    vector<array<int,2>> &v=(t==1?one[op(lx,ly)]:two[tp(lx,ly)]);
                    vector<int> &pos=(t==1?pos_one:pos_two);
//                    cout << "l,r,t [" << l << "," << r << "," << t << "]" << endl;
//                    cout << "id[l]=" << id[l] << ", id[r]=" << id[r] << endl;
                    if(pos[id[l]]+d!=pos[id[r]])
                    {
//                        cout << "found" << endl;
                        for(int i=pos[id[l]];;i++)
                        {
                            if(v[i][0]+1!=v[i+1][0])
                            {
                                int tx=v[i][0]+1;
                                int ty=(t==1?(lx+ly)-tx:tx-(lx-ly));
                                return {tx,ty};
                            }
                        }
                    }
                }
            }
        }();
        cout << resx << " " << resy << "\n";
    }
    return 0;
}