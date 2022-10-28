#include<bits/stdc++.h>
using namespace std;
#define ll long int

int main()
{
    ios_base::sync_with_stdio(0);
    string s,t,temp;
    bool x,z;
    ll k,i,j;
    cin>>s>>t;
    temp=s;
        x=true;
        for(i=0;i<t.length();i++)
        {
            z=false;
            for(j=0;j<temp.length();j++)
            {
                if(t[i]==temp[j])
                {
                    z=true;temp[j]='0';break;
                }
            }
            x=x && z;
        }
        if(x && s.length()==t.length())
        cout<<"array";
        else if(x)
        {
            j=0;
            x=true;
            for(i=0;i<t.length();i++)
            {
                z=false;
                for(;j<s.length();j++)
                {
                    if(t[i]==s[j])
                    {
                        z=true;j++;
                        break;
                    }
                }
                x=x && z;
                
            }
            if(x)cout<<"automaton";
                else cout<<"both";
        }
        else cout<<"need tree";
    return 0;
}