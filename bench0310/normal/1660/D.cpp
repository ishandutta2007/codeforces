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
        vector<int> a(n+1,0);
        for(int i=1;i<=n;i++) cin >> a[i];
        array<int,3> res={0,1,0};
        int l=1;
        while(l<=n)
        {
            if(a[l]==0)
            {
                l++;
                continue;
            }
            int r=l;
            while(r+1<=n&&a[r+1]!=0) r++;
            int c=0;
            int s=0;
            for(int i=l;i<=r;i++)
            {
                c+=(abs(a[i])==2);
                s^=(a[i]<0);
            }
            if(s==0) res=max(res,{c,l,r});
            else
            {
                int x=l;
                int d=c;
                while(a[x]>0) d-=(abs(a[x++])==2);
                d-=(abs(a[x++])==2);
                res=max(res,{d,x,r});
                x=r;
                d=c;
                while(a[x]>0) d-=(abs(a[x--])==2);
                d-=(abs(a[x--])==2);
                res=max(res,{d,l,x});
            }
            l=r+1;
        }
        cout << res[1]-1 << " " << n-res[2] << "\n";
    }
    return 0;
}