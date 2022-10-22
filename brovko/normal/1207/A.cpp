#include <iostream>

using namespace std;
int t, b, p, f, h, c, x, y, k, z;

int main()
{
    cin >> t;
    for(int i=0;i<t;i++)
    {
        cin >> b >> p >> f >> h >> c;
        if(h>c)
            {
                x=p;
                y=h;
                z=f;
            }
        else
        {
            x=f;
            y=c;
            z=p;
        }
        k=min(x, b/2);
        b-=2*k;
        cout << k*y+min(b/2, z)*min(h, c) << endl;
    }
    return 0;
}