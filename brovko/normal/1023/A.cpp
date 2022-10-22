#include <iostream>
#include <string>

using namespace std;
string s, t;
int n, m, pos;

int main()
{
    cin >> n >> m;
    cin >> s;
    cin >> t;
    pos=0;
    for(int i=0;i<n;i++)
        if(s[i]=='*')
        pos=i;
    if(s[pos]!='*')
    {
        if(s==t)
            cout << "YES";
        else cout << "NO";
        return 0;
    }
    if(n<=m+1 && s.substr(0, pos)==t.substr(0, pos) && s.substr(pos+1, n-pos-1)==t.substr(m-(n-pos-1), n-pos-1))
        cout << "YES";
    else cout << "NO";
    return 0;
}