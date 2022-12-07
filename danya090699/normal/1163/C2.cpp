#include <bits/stdc++.h>
using namespace std;
int main()
{
    //freopen("input.txt", "r", stdin);
    int n;
    cin>>n;
    int ar[n][2];
    for(int a=0; a<n; a++) cin>>ar[a][0]>>ar[a][1];
    map <pair <int, int>, set <int> > ma;
    for(int a=0; a<n; a++)
    {
        for(int b=a+1; b<n; b++)
        {
            int x1=ar[a][0], y1=ar[a][1], x2=ar[b][0], y2=ar[b][1];
            int vx=x1-x2, vy=y1-y2;
            if(vx<0 or(vx==0 and vy<0)) vx=-vx, vy=-vy;
            int d=__gcd(vx, abs(vy));
            vx/=d, vy/=d;
            int c=x1*vy-y1*vx;
            ma[{vx, vy}].insert(c);
        }
    }
    int su=0;
    long long an=0;
    for(auto it=ma.begin(); it!=ma.end(); it++)
    {
        an+=1ll*(*it).second.size()*su;
        su+=(*it).second.size();
    }
    cout<<an;
}