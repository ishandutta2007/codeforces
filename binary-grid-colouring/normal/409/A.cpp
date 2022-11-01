#include <bits/stdc++.h>
using namespace std;
string a,b;
int now;
int main()
{
    cin>>a;
    cin>>b;
    now=0;
    for (int i=0;i<a.length();i+=2)
    {
        if (a[i]=='8'&&b[i]=='[') ++now;
        if (a[i]=='['&&b[i]=='(') ++now;
        if (a[i]=='('&&b[i]=='8') ++now;
        if (b[i]=='8'&&a[i]=='[') --now;
        if (b[i]=='['&&a[i]=='(') --now;
        if (b[i]=='('&&a[i]=='8') --now;
    }
    if (now>0) cout <<"TEAM 1 WINS"<<endl;
    if (now==0) cout <<"TIE"<<endl;
    if (now<0) cout<<"TEAM 2 WINS"<<endl;
    return 0;
}