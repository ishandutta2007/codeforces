#include <iostream>

using namespace std;
int w, h, k, s, x;

int main()
{
    cin >> w >> h >> k;
    x=(w+h)*2-4;
    s=x;
    for(int i=0;i<k-1;i++)
    {
        x-=16;
        s+=x;
    }
    cout << s;
    return 0;
}