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

    int n,x;
    cin >> n;
    for(int i=0;i<n;i++)
    {
        cin >> x;
        mk[x+100000]=1;
    }

    int res=0;
    for(int i=0;i<=200000;i++)
        if(i!=100000)
            res+=mk[i];

    db(res)

    return 0;
}