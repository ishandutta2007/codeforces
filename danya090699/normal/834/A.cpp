//Come on, make Togliatti great again!
#include <bits/stdc++.h>
using namespace std;
int main()
{
    char x, y;
    cin>>x>>y;
    int s=0, e=0;
    if(x=='<') s=1;
    if(x=='^') s=2;
    if(x=='>') s=3;
    if(y=='<') e=1;
    if(y=='^') e=2;
    if(y=='>') e=3;
    int q;
    cin>>q;
    int s1=(s+q)%4, s2=s-(q%4);
    if(s2<0) s2+=4;
    if(s1==s2) cout<<"undefined";
    else if(e==s1) cout<<"cw";
    else cout<<"ccw";
}