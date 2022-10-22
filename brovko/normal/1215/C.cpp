#include <bits/stdc++.h>
#define int long long

using namespace std;

int n, k;
string a, b;
vector <int> ab, ba;

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> a >> b;
    for(int i=0;i<n;i++)
    {
        k+=(a[i]=='a');
        k+=(b[i]=='a');
        if(a[i]=='a' && b[i]=='b')
            ab.push_back(i+1);
        if(a[i]=='b' && b[i]=='a')
            ba.push_back(i+1);
    }
    if(k%2)
    {
        cout << -1;
        return 0;
    }
    
    cout << (ab.size()+1)/2+(ba.size()+1)/2 << "\n";
    for(int i=1;i<ab.size();i+=2)
        cout << ab[i] << ' ' << ab[i-1] << "\n";
    for(int i=1;i<ba.size();i+=2)
        cout << ba[i] << ' ' << ba[i-1] << "\n";
    if(ab.size()%2)
    {
        int x=ab[ab.size()-1];
        int y=ba[ba.size()-1];
        cout << x << ' ' << x << "\n";
        cout << y << ' ' << x << "\n";
    }
}