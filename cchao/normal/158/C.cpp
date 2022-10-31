#include <iostream>
#include <vector>
#include <sstream>
using namespace std;
int main()
{
    vector<string> v;
    string cmd,s,t;
    int n;
    cin >> n;
    while(n--)
    {
        cin >> cmd;
        if(cmd[0] == 'c')
        {
            cin >> s;
            if(s[0] == '/') v.clear();
            for(int k = 0; k < s.length(); k++)
                if(s[k] == '/') s[k] = ' ';
            stringstream ss;
            ss << s;
            while(ss >> t)
            {
                if(t[0] == '.')
                    v.pop_back();
                else
                    v.push_back(t);
            }
        }
        else
        {
            cout << '/';
            for(int k = 0; k < v.size(); k++)
            {
                cout << v[k] << '/';
            }
            cout << endl;
        }
    }
    return 0;
}