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
        int n,l,r;
        cin >> n >> l >> r;
        vector<array<int,2>> v(n+1,{0,0});
        for(int i=1;i<=n;i++)
        {
            int c;
            cin >> c;
            v[c][i>l]++;
        }
        int res=0;
        int a=0,b=0;
        int pa=0,pb=0;
        for(int i=1;i<=n;i++)
        {
            auto [x,y]=v[i];
            int m=abs(x-y);
            if(x>=y) pa+=(m/2);
            else pb+=(m/2);
            if(x>=y) a+=m;
            else b+=m;
        }
        res+=min(a,b);
        res+=2*abs(a-b)/2;
        res-=min((a>=b?pa:pb),abs(a-b)/2);
        cout << res << "\n";
    }
    return 0;
}