#include <bits/stdc++.h>
#define db(x) cout << (x) << '\n';
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;

vector<int> v,dif;

int main()
{
    ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);

    int n,m,k,a;
    cin >> n >> m >> k;
    for(int i=0;i<n;i++)
    {
        cin >> a;
        v.push_back(a);
        if(i)
            dif.push_back(v[i]-v[i-1]-1);
    }

    sort(dif.rbegin(),dif.rend());

    k--;
    int res=v[n-1]-v[0]+1;
    for(int i=0;i<k;i++)
        res-=dif[i];
    db(res)

    return 0;
}