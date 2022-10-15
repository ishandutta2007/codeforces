#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

int n;

struct info
{
    int x,i;
};

info v[15];

bool cmp(info a,info b)
{
    return a.x<b.x;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>v[i].x;
        v[i].i=i;
    }
    if(n==1)
    {
        cout<<"-1\n";
        return 0;
    }
    if(n==2 && v[1].x==v[2].x)
    {
        cout<<"-1\n";
        return 0;
    }
    sort(v+1,v+n+1,cmp);
    cout<<"1\n";
    cout<<v[1].i<<"\n";
    return 0;
}
/**

**/