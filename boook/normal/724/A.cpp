#include<bits/stdc++.h>
using namespace std;
#define MAX 100050
#define REP(x,y) for(int x=0;x<y;x++)
#define REP(x,y,z) for(int x=y;x<z;x++)
#define MEM(x,y) memset(x,y,sizeof x)
int F(string s)
{
    if(s=="monday")return 1;
    if(s=="tuesday")return 2;
    if(s=="wednesday")return 3;
    if(s=="thursday")return 4;
    if(s=="friday")return 5;
    if(s=="saturday")return 6;
    if(s=="sunday")return 7;
}
int main()
{
    string a,b;
    while(cin>>a>>b)
    {
        int x=(F(b)-F(a)+7)%7;
        if(x==0 || x==3 || x==2)puts("YES");
        else puts("NO");
//        2 5  5  1  3   6 1 4 7 2 5 7
//        3 0 3 2 3 2 3 3 3 3 2
//        if()
    }
    return 0;
}