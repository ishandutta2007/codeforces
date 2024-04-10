#include <bits/stdc++.h>
#define db(x) cout << (x) << '\n';
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int x1,x2,x,y1,y2,y;
    cin >> x1 >> y1 >> x2 >> y2 >> x >> y;
    if(abs(x1-x2)%x==0 && abs(y1-y2)%y==0 && ((abs(y1-y2)/y)%2)==((abs(x1-x2)/x)%2))
        db("YES")
    else
        db("NO")

    return 0;
}