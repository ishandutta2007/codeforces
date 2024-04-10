#include <iostream>
#include <string>

using namespace std;
string s, t;
int i;

int main()
{
    cin >> s;
    cin >> t;
    s="#"+s;
    t="*"+t;
    int i=1;
    while(s[s.length()-i]==t[t.length()-i])
        i++;
    cout << s.length()+t.length()-2*i;
    return 0;
}