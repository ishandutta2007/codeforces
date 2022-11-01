#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    vector<int> res;
    for(int i=1;i<n;i++) if(gcd(i,n)==1) res.push_back(i);
    ll p=1;
    for(int a:res) p=(p*a)%n;
    if(n>2&&p==n-1) res.pop_back();
    cout << res.size() << "\n";
    for(int a:res) cout << a << " ";
    cout << "\n";
    return 0;
}