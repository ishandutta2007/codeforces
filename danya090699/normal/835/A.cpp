//Come on, make Togliatti great again!
#include <bits/stdc++.h>
using namespace std;
int main()
{
    int s, v1, v2, t1, t2;
    cin>>s>>v1>>v2>>t1>>t2;
    int an1=t1*2+v1*s, an2=t2*2+v2*s;
    if(an1==an2) cout<<"Friendship";
    else if(an1<an2) cout<<"First";
    else cout<<"Second";
}