#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    const int mod=1000000007;
    auto add=[&](int a,int b)->int{return a+b-(a+b>=mod?mod:0);};
    auto sub=[&](int a,int b)->int{return a-b+(a-b<0?mod:0);};
    auto mul=[&](int a,int b)->int{return (ll(a)*b)%mod;};
    vector<int> p(n+1,1);
    for(int i=1;i<=n;i++) p[i]=add(p[i-1],p[i-1]);
    vector<int> c(30,0);
    for(int i=1;i<=n;i++)
    {
        int a;
        cin >> a;
        int b=0;
        while((a%2)==0)
        {
            b++;
            a/=2;
        }
        c[b]++;
    }
    int s=n-c[0];
    int res=sub(p[n],p[s]);
    for(int i=1;i<30;i++)
    {
        s-=c[i];
        if(c[i]>=2) res=add(res,mul(sub(p[c[i]-1],1),p[s]));
    }
    cout << res << "\n";
    return 0;
}