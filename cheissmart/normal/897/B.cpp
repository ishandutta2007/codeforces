#include <bits/stdc++.h>

typedef long long ll;

using namespace std;

int main()
{
	ll k, p, sum = 0;
    cin >> k >> p;
    for(ll i=1;i<=k;i++)
    {
        string s1=to_string(i);
        string s2=s1;
        reverse(s2.begin(),s2.end());
        string s=s1+s2;
        ll x=stoll(s);
        x%=p;
        sum+=x;
        sum%=p;
    }
    cout << sum;
}