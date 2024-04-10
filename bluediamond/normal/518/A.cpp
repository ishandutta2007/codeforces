#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

string s;
string t;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin>>s>>t;
    if(s==t)
    {
        cout<<"No such string\n";
        return 0;
    }
    for(int i=s.size()-1;i>=0;i--)
    {
        if(s[i]=='z')
        {
            s[i]='a';
        }
        else
        {
            s[i]++;
            break;
        }
    }
    if(s==t)
    {
        cout<<"No such string\n";
        return 0;
    }
    cout<<s<<"\n";
    return 0;
}
/**


**/