#include <bits/stdc++.h>

using namespace std;

bool num(string s)
{
    if(s.empty()) return 0;
    for(char c:s) if(!isdigit(c)) return 0;
    if(s!="0"&&s[0]=='0') return 0;
    return 1;
}

string build(vector<string> v)
{
    if(v.empty()) return "-";
    string s;
    s+="\"";
    for(string a:v) s+=(a+",");
    s.back()='"';
    return s;
}

int main()
{
    string s;
    cin >> s;
    s+=";";
    vector<string> c,d;
    string t;
    for(int i=0;i<(int)s.size();i++)
    {
        if(s[i]==','||s[i]==';')
        {
            if(num(t)) c.push_back(t);
            else d.push_back(t);
            t.clear();
        }
        else t+=s[i];
    }
    cout << build(c) << endl;
    cout << build(d) << endl;
    return 0;
}