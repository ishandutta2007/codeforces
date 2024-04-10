#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
    int n;
    cin >> n;
    char s[400];
    cin >> s;
    sort(s,s +n);
    sort(s + n, s + 2 * n);
    int i = 0, j = n;
    int b = 0;
    while(i < n && j < 2*n)
    {
        if(s[i] < s[j])
        {
            b++, i++;
        }
        else if(s[i] >= s[j])
        {
            b--, j++;
        }
        if(b < 0) break;
    }
    if(b >= 0)
    {
        cout << "YES" << endl;
        return 0;
    }
    i = n - 1, j = 2*n -1;
    b = 0;
    while(i >= 0 && j >= 0)
    {
        if(s[i] > s[j])
        {
            b++, i--;
        }
        else if(s[i] <= s[j])
        {
            b--, j--;
        }
        if(b < 0) break;
    }
    if(b >= 0)
    {
        cout << "YES" << endl;
    }
    else
    {
        cout << "NO" << endl;
    }
    return 0;
}