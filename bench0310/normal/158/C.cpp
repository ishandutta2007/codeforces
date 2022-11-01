#include <bits/stdc++.h>

using namespace std;

vector<string> split(string s)
{
    vector<string> v;
    s+='/';
    int a=0,b=0;
    while((b=s.find("/",a))!=-1)
    {
        v.push_back(s.substr(a,b-a));
        a=b+1;
    }
    return v;
}

string path(stack<string> s)
{
    vector<string> v;
    while(!s.empty())
    {
        v.push_back(s.top());
        s.pop();
    }
    reverse(v.begin(),v.end());
    string res;
    for(string t:v) res+=t+"/";
    return res;
}

int main()
{
    int t;
    cin >> t;
    stack<string> s;
    s.push("");
    while(t--)
    {
        string c;
        cin >> c;
        if(c=="cd")
        {
            string cd;
            cin >> cd;
            vector<string> v=split(cd);
            if(v[0]=="") while(!s.empty()) s.pop();
            for(string t:v)
            {
                if(t=="..") s.pop();
                else s.push(t);
            }
        }
        else cout << path(s) << endl;
    }
    return 0;
}