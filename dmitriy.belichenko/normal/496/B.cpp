#include<iostream>
#include<math.h>
#include<algorithm>
using namespace std;
string ans;
int n;

int main()
{
    cin >> n;
    string s;
    cin >> s;
    ans = s;
    s += s;
    for(int i = 0; i < n; i++)
    {
        string t = s.substr(i , n);
        int k='9'- t[0] +1;
        for (int j = 0; j < n ;j++)
        {
            t[j] = '0' + ( t[j] -'0' + k) % 10;
        }
        ans = min(ans, t);
    }
    cout << ans << "\n";
}