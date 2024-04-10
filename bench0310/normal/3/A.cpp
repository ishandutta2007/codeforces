#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    string a,b;
    cin >> a >> b;
    int x1=a[0]-'a'+1;
    int y1=a[1]-'0';
    int x2=b[0]-'a'+1;
    int y2=b[1]-'0';
    cout << max(abs(x1-x2),abs(y1-y2)) << endl;
    while(x1!=x2||y1!=y2)
    {
        if(x1<x2)
        {
            cout << 'R';
            x1++;
        }
        if(x1>x2)
        {
            cout << 'L';
            x1--;
        }
        if(y1<y2)
        {
            cout << 'U';
            y1++;
        }
        if(y1>y2)
        {
            cout << 'D';
            y1--;
        }
        cout << endl;
    }
    return 0;
}