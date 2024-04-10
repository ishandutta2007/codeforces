#include <bits/stdc++.h>
#define db(x) cout << (x) << '\n';
using namespace std;
#define MAXN 1005

double arr[MAXN];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    double n,h;
    cin >> n >> h;
    double hh=h;
    cout.precision(10);
    cout<<fixed;
    for(int i=0;i<n-1;i++)
    {
        arr[i+1]=arr[i]+h-sqrt(h*h-((h*h)/(n-i)));
        h=hh-arr[i+1];
    }
    for(int i=n-1;i>0;i--)
        cout << hh-arr[i] << ' ';

    return 0;
}