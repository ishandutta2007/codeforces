#include <iostream>
using namespace std;
int main()
{
    int a,b; //gup , kid
    cin >> a >> b;
    if(a==0 && b>0)
    {
        cout << "Impossible" << endl;
    }
    else if(b==0)
    {
        cout << a << ' ' << a << endl;
    }
    else if(a>=b)
    {
        cout << a << ' ' << a+b-1 << endl;
    }
    else if(a<b)
    {
        cout << a+(b-a) << ' ' << a+b-1 << endl;
    }
    return 0;
}