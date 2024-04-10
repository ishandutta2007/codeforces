#include <bits/stdc++.h>
#define db(x) cout << (x) << '\n';
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef long double ld;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;
    while(t--)
    {
        int n;
        cin >> n;
        ll sum=0,a;
        for(int i=0;i<n;i++)
        {
            cin >> a;
            sum+=a;
        }

        int res=sum/n;
        if(res*n == sum)
            db(res)
        else
            db(res+1)
    }

    return 0;
}