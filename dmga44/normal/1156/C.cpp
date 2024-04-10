#include <bits/stdc++.h>
#define db(x) cout << (x) << '\n';
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define MAXN 200005

bool mk[MAXN];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n,z,a;
    cin >> n >> z;
    vector<int> v;
    for(int i=0;i<n;i++)
    {
        cin >> a;
        v.push_back(a);
    }

    sort(v.begin(),v.end());

    int res=0,l=0,r=n/2;
    while(l<n/2 && r<n)
    {
        while(r<n && v[r]-v[l]<z)
            r++;
        if(r<n)
            res++;
        r++;
        l++;
    }
    db(res)

    return 0;
}