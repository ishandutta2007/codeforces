#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    auto ord=[&](char c)->int{return (c-'a');};
    auto chr=[&](int x)->char{return ('a'+x);};
    vector<string> opt={"buffy","the","vampire","slayer"};
    string s;
    cin >> s;
    string res="none";
    for(string t:opt)
    {
        if(s.size()==t.size())
        {
            res="";
            for(int i=0;i<(int)s.size();i++) res+=chr((ord(s[i])+ord(t[i]))%26);
        }
    }
    cout << res << "\n";
    return 0;
}