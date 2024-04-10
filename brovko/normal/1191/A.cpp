#include <bits/stdc++.h>
#define int long long
#define ld long double
#define y1 sdopgh

using namespace std;

int x;

char f(int n)
{
    if(n%4==1)
        return 'A';
    if(n%4==3)
        return 'B';
    if(n%4==2)
        return 'C';
    if(n%4==0)
        return 'D';
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    //freopen("name.in", "r", stdin);
    //freopen("name.out", "w", stdout);

    cin >> x;
    char Min=f(x);
    int ind=0;
    x++;
    if(f(x)<Min)
    {
        Min=f(x);
        ind=1;
    }
    x++;
    if(f(x)<Min)
    {
        Min=f(x);
        ind=2;
    }
    cout << ind << ' ' << Min;
}