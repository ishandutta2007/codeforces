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

    int t;
    cin >> t;
    while(t--)
    {
        int n,k;
        cin >> n >> k;
        for(int i=0;i<n;i++)
            cin >> a[i];
        int res=(1e9),sol=0;
        for(int i=0;i+k<n;i++)
        {
            int x=a[i];
            int y=a[i+k];
            if((y-x+1)/2<res)
            {
                res=(y-x+1)/2;
                sol=(x+y)/2;
            }
        }
        db(sol)
    }

    return 0;
}