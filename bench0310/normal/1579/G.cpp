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
        cin >> n;
        const int N=2000;
        vector<int> opt(N+1,N);
        opt[0]=0;
        auto chmin=[&](int &a,int b){a=min(a,b);};
        for(int i=1;i<=n;i++)
        {
            int a;
            cin >> a;
            vector<int> nopt(N+1,N);
            for(int j=0;j<=N;j++)
            {
                if(j+a<=N) chmin(nopt[j+a],max(opt[j],j+a));
                if(j-a>=0) chmin(nopt[j-a],opt[j]);
                else if(-(j-a)+opt[j]<=N) chmin(nopt[0],-(j-a)+opt[j]);
            }
            opt=nopt;
        }
        int res=N;
        for(int j=0;j<=N;j++) chmin(res,opt[j]);
        cout << res << "\n";
    }
    return 0;
}