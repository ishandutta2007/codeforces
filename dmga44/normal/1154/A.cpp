#include <bits/stdc++.h>
#define db(x) cout << (x) << '\n';
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<pii,int> ppi;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int a,b,c,d;
    cin >> a >> b >> c >> d;
    vector<int> v;
    v.push_back(a);
    v.push_back(b);
    v.push_back(c);
    v.push_back(d);

    sort(v.rbegin(),v.rend());

    for(int i=1;i<4;i++)
        cout << v[0]-v[i] << ' ';
    cout << '\n';

    return 0;
}