#include <bits/stdc++.h>
#define db(x) cout << (x) << '\n';
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define MAXN 200005

int a[MAXN];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;
    for(int i=0;i<n;i++)
        cin >> a[i];

    int o0=0,o1=0,res=n;
    for(int i=n-1;i>=0;i--)
    {
        if(!a[i] && !o0)
            res=i+1,o0=1;
        else if(a[i] && !o1)
            res=i+1,o1=1;
    }

    db(res)

    return 0;
}