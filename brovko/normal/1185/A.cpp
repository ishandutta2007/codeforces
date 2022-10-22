#include <iostream>

using namespace std;
int a, b, c, d, ans;

int main()
{
    cin >> a >> b >> c >> d;
    if(a>b)
        swap(a, b);
    if(b>c)
        swap(b, c);
    if(a>b)
        swap(a, b);
    if(b-a<d)
        ans+=d-(b-a);
    if(c-b<d)
        ans+=d-(c-b);
    cout << ans;
    return 0;
}