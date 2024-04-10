#include <iostream>
#include <string>

using namespace std;
string s, gl;
bool glas(char c)
{
    bool ans=false;
    for(int i=0;i<5;i++)
        if(c==gl[i])
        ans=true;
    return ans;
}

int main()
{
    bool ans=true;
    cin >> s;
    s=s+'b';
    gl="aeuio";
    for(int i=0;i<s.length()-1;i++)
    {
        if(s[i]!='n' && !glas(s[i]) && !glas(s[i+1]))
            ans=false;
    }
    if(ans)
        cout << "YES";
    else cout << "NO";
    return 0;
}