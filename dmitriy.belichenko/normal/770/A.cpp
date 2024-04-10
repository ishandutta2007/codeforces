#include <iostream>
#include <string>
using namespace std;

int main()
{
    int n,k;
    string s = "";
    cin >> n >> k;
    char c[26];
    for(int i = 0; i < 26; i++)
        c[i] = 'a'+i;
    for(int i = 0; i < n; i++)
    {
        s += c[i % k];
    }
    cout << s;
    return 0;
}