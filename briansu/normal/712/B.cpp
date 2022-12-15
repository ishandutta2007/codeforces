#include <cmath>
#include <iostream>
#include <string.h>
#include <sstream>
#include <stdio.h>
#include <vector>
#include <set>
#include <algorithm>
#include <stack>
#include <map>
#include <iomanip>
using namespace std;
int main()
{
    string s;
    cin>>s;
    int x=0,y=0,l=s.length();
    int m[4];//U0 D1 R2 L3
    memset(m,0,sizeof(m));
    for(int i=0;i<l;i++)
    {
        if(s[i]=='U')m[0]++;
        else if(s[i]=='D')m[1]++;
        else if(s[i]=='R')m[2]++;
        else if(s[i]=='L')m[3]++;
    }
    y=m[0]-m[1];
    x=m[2]-m[3];
    if((y+x)%2)cout<<-1<<endl;
    else cout<<(abs(x)+abs(y))/2<<endl;

}