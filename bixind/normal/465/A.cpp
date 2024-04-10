#include <iostream>
#include <stdio.h>

using namespace std;

int main()
{
    string s;
    int n;
    scanf("%i/n", &n);
    cin >> s;
    s = s + '0';
    int i = 0;
    while (s[i] != '0')
    {
        i++;
    }
    i++;
    if (i > n)
        i--;
    cout << i;
    return 0;
}