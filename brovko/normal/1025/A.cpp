#include <iostream>
#include <string>

using namespace std;
int n, b[130];
string s;

int main()
{
    cin >> n;
    cin >> s;
    if(n==1)
    {
        cout << "Yes";
        return 0;
    }
    for(int i=0;i<n;i++)
    {
        b[(int)s[i]]++;
        if(b[(int)s[i]]==2)
        {
            cout << "Yes";
            return 0;
        }
    }
    cout << "No";
    return 0;
}