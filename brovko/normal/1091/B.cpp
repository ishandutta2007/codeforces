#include <iostream>

using namespace std;
int n, x, y, a, b, x1, y1, minx, miny, maxa, maxb;

int main()
{
    cin >> n;
    minx=1000000000;
    miny=1000000000;
    maxa=-1000000000;
    maxb=-1000000000;
    for(int i=0;i<n;i++)
    {
        cin >> x >> y;
        minx=min(minx, x);
        miny=min(miny, y);
    }
    for(int i=0;i<n;i++)
    {
        cin >> a >> b;
        maxa=max(maxa, a);
        maxb=max(maxb, b);
    }
    cout << minx+maxa << ' ' << miny+maxb;
    return 0;
}