#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
#define ff first
#define ss second
#define mp make_pair
#define pb push_back

inline int gt(int a,int b,int c)
{
    return min(a,min(b,c));
}

struct info
{
    int x,i;
};

bool operator < (info a,info b)
{
    return a.x<b.x;
}

map< pair<int,int>, vector<info> >sl;
int n;
int x[5];

int x1,x2,x3,id1,id2;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>x[1]>>x[2]>>x[3];
        sort(x+1,x+4);
        sl[mp(x[1],x[2])].pb({x[3],i});
        sl[mp(x[1],x[3])].pb({x[2],i});
        sl[mp(x[2],x[3])].pb({x[1],i});
        if(gt(x[1],x[2],x[3])>gt(x1,x2,x3))
        {
            x1=x[1];
            x2=x[2];
            x3=x[3];
            id1=i;
            id2=0;
        }
    }
    for(auto itr:sl)
    {
        if(itr.second.size()<2) continue;
        sort(itr.second.rbegin(),itr.second.rend());
        int a=itr.first.first;
        int b=itr.first.second;
        int c=itr.second[0].x+itr.second[1].x;
        if(gt(a,b,c)>gt(x1,x2,x3))
        {
            x1=a;
            x2=b;
            x3=c;
            id1=itr.second[0].i;
            id2=itr.second[1].i;
        }
      ///  cout<<a<<" "<<b<<" "<<c<<" : "<<gt(a,b,c)<<"\n";
    }
    if(id2==0) cout<<"1\n"; else cout<<"2\n";
    if(id2==0) cout<<id1<<"\n"; else cout<<id1<<" "<<id2<<"\n";
}