#include <iostream>
#include <set>

using namespace std;

int s[1 << 17];

int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> s[i];
        
    int a = 0;
    int b = 0;
    int i = 0;
    int j = n - 1;
    
    int sa = 0;
    int sb = 0;
    while (i <= j)
    {
        if (sa <= sb)
        {
            sb -= sa;
            sa = s[i++];
            a++;
        }
        else
        {
            sa -= sb;
            sb = s[j--];
            b++;
        }
    }
    
    cout << a << ' ' << b << endl;
    
    return 0;
}