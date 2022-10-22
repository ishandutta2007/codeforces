#include <iostream>
#include <math.h>

using namespace std;

int main()
{
    string s;
    cin >> s;
    int n = s.size();

    for(int i = 0; i <= n; i++)
        for(int j = 0; i + j <= n; j++)
            if(s.substr(0, i) + s.substr(i + j, n - i - j) == "CODEFORCES")
            {
                cout << "YES";
                return 0;
            }

    cout << "NO";
}