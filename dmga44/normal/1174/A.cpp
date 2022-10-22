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
    vector<int> v;
    for(int i=0;i<2*n;i++)
    {
        int x;
        cin >> x;
        v.push_back(x);
    }

    sort(v.begin(),v.end());

    int s1=0,s2=0;
    for(int i=0;i<n;i++)
    {
        s1+=v[i];
        s2+=v[i+n];
    }
    if(s1==s2)
        db(-1)
    else
        for(auto y : v)
            cout << y << ' ';

    return 0;
}