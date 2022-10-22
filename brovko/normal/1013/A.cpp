#include <iostream>

using namespace std;
int n, a[50], b[50], s1, s2;

int main()
{
    s1=0;
    s2=0;
    cin >> n;
    for(int i=0;i<n;i++)
        cin >> a[i];
    for(int i=0;i<n;i++)
        cin >> b[i];
    for(int i=0;i<n;i++)
    {
        s1=s1+a[i];
        s2=s2+b[i];
    }
    if(s1>=s2)
        cout << "Yes";
    else cout << "No";
    return 0;
}