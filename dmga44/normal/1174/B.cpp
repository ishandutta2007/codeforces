#include <bits/stdc++.h>
#define db(x) cout << (x) << '\n';
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    bool b0=0,b1=0;
    vector<int> v;
    for(int i=0;i<n;i++)
    {
        int x;
        cin >> x;
        v.push_back(x);
        if(x&1)
            b1=1;
        else
            b0=1;
    }
    if(b1 && b0)
        sort(v.begin(),v.end());

    for(auto y : v)
        cout << y << ' ';
    cout << '\n';

    return 0;
}