#include <bits/stdc++.h>
using namespace std;
const int si=1e5+10;
int main()
{
    int n,m,cnt=0;
    cin >> n >> m;
    while(m>n){
        if(m%2==0) m/=2;
        else m++;
        ++cnt;
    }
    cout << cnt+n-m;
    return 0;
}