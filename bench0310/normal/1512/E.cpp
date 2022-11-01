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
        auto ok=[&](int n,int cnt,int s)->bool
        {
            int mn=(cnt*(cnt+1)/2);
            int mx=((n+(n-cnt+1))*cnt/2);
            return (mn<=s&&s<=mx);
        };
        int n,l,r,s;
        cin >> n >> l >> r >> s;
        if(ok(n,r-l+1,s))
        {
            vector<bool> used(n+1,0);
            int idx=l;
            int cnt=r-l+1;
            vector<int> res(n+1,0);
            for(int i=n;i>=1;i--)
            {
                if(ok(i-1,cnt-1,s-i))
                {
                    res[idx++]=i;
                    cnt--;
                    s-=i;
                    used[i]=1;
                }
            }
            int now=1;
            for(int i=1;i<=n;i++)
            {
                if(res[i]==0)
                {
                    while(used[now]) now++;
                    res[i]=now;
                    used[now]=1;
                }
            }
            for(int i=1;i<=n;i++) cout << res[i] << " \n"[i==n];
        }
        else cout << "-1\n";
    }
    return 0;
}