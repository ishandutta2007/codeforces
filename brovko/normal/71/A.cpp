#include <bits/stdc++.h>

using namespace std;
string s;
int n;

int main()
{
    cin >> n;
    for(int i=0;i<n;i++)
        {
            cin >> s;
            if(s.size()<=10)
                cout << s << endl;
            else cout << s[0] << (int)s.size()-2 << s[(int)s.size()-1] << endl;
        }
}