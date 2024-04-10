#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    const ll mod=998244353;
    int t;
    cin >> t;
    while(t--)
    {
        int n,k;
        cin >> n >> k;
        vector<int> a(n+1,0);
        vector<int> pos(n+1,0);
        for(int i=1;i<=n;i++)
        {
            cin >> a[i];
            pos[a[i]]=i;
        }
        vector<int> b(k);
        for(int i=0;i<k;i++) cin >> b[i];
        vector<int> l(n+2,0);
        vector<int> r(n+2,0);
        for(int i=1;i<=n;i++) l[i]=r[i]=i;
        vector<bool> rm(n+1,1);
        for(int x:b) rm[x]=0;
        vector<bool> rmpos(n+1,0);
        ll res=1;
        auto ext=[&](int p)
        {
            rmpos[p]=1;
            int one=p,two=p;
            if(p>=2&&rmpos[p-1]==1) one=l[p-1];
            if(p<=n-1&&rmpos[p+1]==1) two=r[p+1];
            r[one]=two;
            l[two]=one;
        };
        for(int x:b)
        {
//            cout << "in " << x << endl;
//            cout << "rm: ";
//            for(int i=1;i<=n;i++) if(rm[i]) cout << i << " ";
//            cout << endl;
            int one=l[pos[x]-1];
            if(rmpos[pos[x]-1]==0) one=pos[x];
            int two=r[pos[x]+1];
            if(rmpos[pos[x]+1]==0) two=pos[x];
            array<bool,2> val={0,0};
            if(pos[x]>1&&one-1>=1&&rm[a[one-1]]==1) val[0]=1;
            if(pos[x]<n&&two+1<=n&&rm[a[two+1]]==1) val[1]=1;
            int c=val[0]+val[1];
//            cout << "l: " << val[0] << endl;
//            cout << "r: " << val[1] << endl;
            if(c==0)
            {
                res=0;
                break;
            }
            else
            {
                if(c==2) res=(res*2)%mod;
                if(val[0]) ext(one-1);
                else ext(two+1);
            }
            rm[x]=1;
        }
        cout << res << "\n";
    }
    return 0;
}