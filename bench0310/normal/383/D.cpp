#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    const int M=10000;
    const int mod=1000000007;
    int n;
    cin >> n;
    vector<int> now(2*M+1,0);
    auto add=[&](int &a,int b){a=(a+b)%mod;};
    int res=0;
    for(int i=1;i<=n;i++)
    {
        add(now[M],1);
        int a;
        cin >> a;
        vector<int> nxt(2*M+1,0);
        for(int j=-M+a;j<=M-a;j++)
        {
            add(nxt[j+a+M],now[j+M]);
            add(nxt[j-a+M],now[j+M]);
        }
        now=nxt;
        add(res,now[M]);
    }
    cout << res << "\n";
    return 0;
}