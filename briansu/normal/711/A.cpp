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
    int n;
    cin>>n;
    bool b=true;
    stringstream ans;
    for(int i=0;i<n;i++)
    {
        string s;
        cin>>s;
        string tmp1,tmp2;
        tmp1=s.substr(0,2);
        tmp2=s.substr(3,2);
        if(b&&tmp1=="OO"){tmp1="++";b=false;}
        if(b&&tmp2=="OO"){tmp2="++";b=false;}
        ans<<tmp1<<"|"<<tmp2<<endl;
    }
    if(!b)cout<<"YES"<<endl<<ans.str();
    else cout<<"NO"<<endl;
}