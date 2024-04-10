#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    int notused,a,b,c,d;
    cin >> notused >> notused >> a >> b >> c >> d;
    int am = min(fabs(a-c),fabs(b-d)),
        bm = max(fabs(a-c),fabs(b-d));
    if (am==0 && bm<=4 ||
        am==1 && bm<=4 ||
        am==2 && bm<=4 ||
        am==3 && bm==3)
            cout << "First" << endl;
    else
            cout << "Second" << endl;
    return 0;
}