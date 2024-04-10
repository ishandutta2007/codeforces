#include <iostream>
#include <string>

using namespace std;
string s;
int i, k0, k1, pos2, n;

int main()
{
    cin >> s;
    i=0;
    n=s.length();
    while(i<n && s[i]!='2')
    {
        if(s[i]=='0')
            k0++;
        i++;
    }
    pos2=i;
    for(int i=0;i<n;i++)
        if(s[i]=='1')
        k1++;
    for(int i=0;i<k0;i++)
        cout << 0;
    for(int i=0;i<k1;i++)
        cout << 1;
    for(int i=pos2;i<n;i++)
        if(s[i]!='1')
        cout << s[i];
    return 0;
}