#include <iostream>
#include <string>

using namespace std;
string s;
int n, k, s1;

int main()
{
    cin >> n >> k;
    cin >> s;
    s1=0;
    int i=0;
    while(s1<k/2)
    {
        if(s[i]=='(')
            s1++;
        cout << s[i];
        i++;
    }
    while(i<k)
    {
        cout << ')';
        i++;
    }
    return 0;
}