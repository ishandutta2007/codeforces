#include <bits/stdc++.h>
#define db(x) cout << (x) << '\n';
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define MAXN 105

int l[MAXN],r[MAXN];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;
    vector<int> v;
    for(int i=0;i<n;i++)
    {
        cin >> l[i] >> r[i];
        v.push_back(r[i]);
    }
    int k;
    cin >> k;
    int res=n;
    for(int i=0;i<n;i++)
        if(v[i]<k)
            res--;
    db(res)

    return 0;
}