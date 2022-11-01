#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--)
    {
        ll d,k;
        cin >> d >> k;
        ll x=0;
        for(ll i=0;i<=d;i+=k) if(2*i*i<=d*d) x=i;
        if((x+k)*(x+k)+x*x<=d*d) cout << "Ashish\n";
        else cout << "Utkarsh\n";
    }
    return 0;
}