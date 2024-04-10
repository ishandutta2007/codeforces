#include <bits/stdc++.h>
#define db(x) cout << (x) << '\n';
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<pii,int> ppi;
#define MAXN 105

int f[MAXN];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n,x;
    cin >> n;
    int dif=0,mi=MAXN,ma=0;
    vector<int> v;
    for(int i=0;i<n;i++)
    {
        cin >> x;
        if(!f[x])
        {
            dif++;
            f[x]++;
            v.push_back(x);
        }
        ma=max(ma,x);
        mi=min(mi,x);
    }

    sort(v.begin(),v.end());

    if(dif>3)
        db(-1)
    else
    {
        if(dif==1)
            db(0)
        else if(dif==2)
        {
            if((v[1]-v[0])&1)
                db(v[1]-v[0])
            else
                db((v[1]-v[0])/2)
        }
        else
        {
            if((v[1]*2)==(v[0]+v[2]))
                db(v[1]-v[0])
            else
                db(-1)
        }
    }


    return 0;
}