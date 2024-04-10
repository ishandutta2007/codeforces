#include <iostream>

using namespace std;
long long n, q, x, y;

int main()
{
    cin >> n >> q;
    for(int i=0;i<q;i++)
    {
        cin >> x >> y;
        if((x+y)%2==0)
            cout << (long long)(x/2*((n+1)/2)+(x-1)/2*(n/2))+((y+1)/2) << endl;
        else
        {
            int t=0;
            if(x%2==1)
                t=y/2;
            else t=(y+1)/2;
            cout << (long long)((long long)n*n+1)/2+((x-1)/2*((n+1)/2)+x/2*(n/2))+t<< endl;
        }
    }
    return 0;
}