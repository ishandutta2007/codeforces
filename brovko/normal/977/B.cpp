#include <iostream>
#include <map>
#include <string>
using namespace std;
map < string, int > a;
int n;
string s, m;
int main()
{
    cin >> n;
    cin >> s;
    for (int i=0;i<n-1;i++)
    {
        a[s.substr(i,2)]++;
    }
    m=s.substr(0,2);
    for (int i=1;i<n-1;i++)
    {
        if(a[s.substr(i,2)]>a[m])
        {
            m=s.substr(i,2);
        }
    }
    cout << m;
    return 0;
}