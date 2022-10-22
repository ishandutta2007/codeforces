#include <bits/stdc++.h>
#define int long long
#define y1 dwihweoighweoi
#define ld long double

using namespace std;

int n, s[200005], a[200005], t[200005];

int sum(int r)
{
    int ans=0;
    for(;r>=0;r=(r & r+1)-1)
        ans+=t[r];
    return ans;
}

void inc(int i, int d)
{
    for(;i<=n;i=(i | i+1))
        t[i]+=d;
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for(int i=0;i<n;i++)
        cin >> s[i];
    for(int i=1;i<=n;i++)
        inc(i, i);

    for(int i=n-1;i>=0;i--)
    {
        int L=0;
        int R=n;
        while(R-L>1)
        {
            int M=(L+R)/2;
            if(sum(M)<=s[i])
                L=M;
            else R=M;
        }

        a[i]=R;
        inc(R, -R);
    }

    for(int i=0;i<n;i++)
        cout << a[i] << ' ';
}