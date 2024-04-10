#include <iostream>
using namespace std;

int main()
{
    int n,m,first,now,d,v,cnt = 0;
    cin >> n >> m;
    now = first = (1 + m) / 2;
    d = (m % 2 == 0) ? 1 : -1;
    v = 1;
    while(n--)
    {
        cout << now << endl;
        cnt++;
        now = first +  d * v;
        d = -d;
        //cout << "move to " << now << endl;
        if(cnt % 2 == 0) v++;
        if(now < 1 || now > m)
        {
            cnt = 0;
            now = first;
            d = (m % 2 == 0) ? 1 : -1;
            v = 1;
        }
    }
    return 0;
}