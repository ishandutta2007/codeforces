#include <bits/stdc++.h>
#define db(x) cout << (x) << '\n';
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define MAXN 100005

bool mk[MAXN];
map<pii,bool> m;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n,k;
    cin >> n >> k;
    for(int i=0;i<k;i++)
    {
        int x;
        cin >> x;
        mk[x]=1;
        m[pii(x,x)]=1;
        if(x>1)
        {
            if(mk[x-1])
                m[pii(x-1,x)]=1;
        }
        if(x<n)
        {
            if(mk[x+1])
                m[pii(x+1,x)]=1;
        }
    }

    db(3*n-2-m.size())

    return 0;
}