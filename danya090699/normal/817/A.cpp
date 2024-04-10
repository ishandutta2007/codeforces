#include <bits/stdc++.h>
using namespace std;
int main()
{
    int x1, y1, x2, y2, x, y;
    cin>>x1>>y1>>x2>>y2>>x>>y;
    int dx=x1-x2, dy=y1-y2;
    if(dx<0) dx=-dx;
    if(dy<0) dy=-dy;
    if(dx%x==0 and dy%y==0 and (dy/y+dx/x)%2==0) cout<<"YES";
    else cout<<"NO";
}