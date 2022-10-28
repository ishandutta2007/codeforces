#include<bits/stdc++.h>
using namespace std;
int main()
{
    string s;
    cin>>s;
    string k=s;
    string l=s.substr(3,2);
    string m=s.substr(0,2);
    string h=s.substr(0,2);
    reverse(m.begin(),m.end());
    int a=stoi(m);
    int b=stoi(l);
    int c=stoi(h);
    if(b<a&&a<=59&&(c<6||c>=10))
    cout<<h<<":"<<m;
    else if((c!=23||a==59)&&(c<6||c>=10)&&c<15&&c>0)
    {
        string d=to_string(c+1);
        reverse(d.begin(),d.end());
        if(c/10==0)cout<<0;
        cout<<c+1<<":"<<d;
        if(c/10==0)cout<<0;
    }
    else if(c>=6&&c<10)
    cout<<10<<":"<<0<<1;
    else if(c==15&&b<51)
    cout<<15<<":"<<51;
    else if(c>=15&&c<=20)
    cout<<20<<":"<<0<<2;
    else if(c==23)
    cout<<0<<0<<":"<<0<<0;
    else if(c==0)
    cout<<0<<1<<":"<<1<<0;
    
    
    
    return 0;
}