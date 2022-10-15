#include <iostream>
using namespace std;
int main()
{
    int s,x1,x2,y1,y2,s1,s2;
    cin>>s>>x1>>x2>>y1>>y2;
    s1=s*x1+2*y1;
    s2=s*x2+2*y2;
    if(s1>s2)
        cout<<"Second";
    if(s1<s2)
        cout<<"First";
    if(s1==s2)
        cout<<"Friendship";
    return 0;
}