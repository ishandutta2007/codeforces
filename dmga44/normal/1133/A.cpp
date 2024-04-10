#include <bits/stdc++.h>
#define db(x) cout << (x) << '\n';
using namespace std;
typedef long long ll;

int main()
{
    ios_base::sync_with_stdio(0);
    cout.tie();

    int h1,m1,h2,m2;
    char c;
    cin >> h1 >> c >> m1;
    cin >> h2 >> c >> m2;
    int sh=h1+h2;
    int sm=m1+m2;
    if(sm>59)
    {
        sm-=60;
        sh++;
    }
    int rh=sh/2;
    int rm=sm/2;
    if(sh&1)
        rm+=30;
    if(rh<10)
        cout << '0';
    cout << rh << ':';
    if(rm<10)
        cout << '0';
    cout << rm << '\n';

    return 0;
}