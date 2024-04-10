#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,m;
    cin >> n >> m;
    int on=n;
    int om=m;
    int mx=max(n,m);
    vector<bool> prime(mx+1,1);
    for(int i=2;i<=mx;i++) for(int j=2*i;j<=mx;j+=i) prime[j]=0;
    auto query=[&](int h,int w,int a,int b,int c,int d)->bool
    {
        cout << "? " << h << " " << w << " " << a << " " << b << " " << c << " " << d << "\n";
        cout.flush();
        int x;
        cin >> x;
        return x;
    };
    auto go_n=[&](int p)->bool
    {
        int now=p;
        while(2*now<n)
        {
            if(query(now,m,1,1,now+1,1)==0) return 0;
            now*=2;
        }
        int nxt=(n-now);
        return query(nxt,m,1,1,n-nxt+1,1);
    };
    for(int i=2;i<=n;i++) while(prime[i]&&(n%i)==0&&go_n(n/i)) n/=i;
    auto go_m=[&](int p)->bool
    {
        int now=p;
        while(2*now<m)
        {
            if(query(n,now,1,1,1,now+1)==0) return 0;
            now*=2;
        }
        int nxt=(m-now);
        return query(n,nxt,1,1,1,m-nxt+1);
    };
    for(int i=2;i<=m;i++) while(prime[i]&&(m%i)==0&&go_m(m/i)) m/=i;
    auto d=[&](int a)->int
    {
        int res=0;
        for(int i=1;i<=a;i++) res+=((a%i)==0);
        return res;
    };
    cout << "! " << d(on/n)*d(om/m) << "\n";
    cout.flush();
    return 0;
}