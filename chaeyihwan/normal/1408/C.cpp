#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

double a[100002];

int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin >> t;
    while(t--){
        int n, l; cin >> n >> l;
        double ans = 0;

        a[0] = 0, a[n+1] = l;
        for(int i=1;i<=n;i++) cin >> a[i];
        int i, j;
        double ta = 0, tb = 0;

        for(i=0,j=n+1;i<j-1;)
        {
            double na = ta + (a[i+1] - a[i])/(i+1);
            double nb = tb + (a[j] - a[j-1])/(n+2-j);

            if(na < nb)
            {
                i++; ta = na;
            }
            else
            {
                j--; tb = nb;
            }
        }

        double rem = a[j] - a[i] - (ta<tb?(tb-ta)*(i+1):(ta-tb)*(n+2-j));

        cout.precision(20);
        cout << max(ta, tb) + rem/(n+2) << "\n";
    }
}