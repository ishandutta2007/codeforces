#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--)
    {
        int n;
        double l;
        cin >> n >> l;
        vector<double> a(n+1,0);
        for(int i=1;i<=n;i++) cin >> a[i];
        int one=1,two=n;
        double va=1;
        double vb=1;
        double xa=0;
        double xb=l;
        double res=0;
        while(one<=two)
        {
            double ta=(a[one]-xa)/va;
            double tb=(xb-a[two])/vb;
            if(ta<=tb)
            {
                xa+=ta*va;
                va+=1;
                xb-=ta*vb;
                one++;
                res+=ta;
            }
            else
            {
                xb-=tb*vb;
                vb+=1;
                xa+=tb*va;
                two--;
                res+=tb;
            }
        }
        res+=(xb-xa)/(va+vb);
        cout << fixed << setprecision(15) << res << "\n";
    }
    return 0;
}