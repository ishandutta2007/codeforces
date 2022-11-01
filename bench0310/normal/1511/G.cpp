#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    const int k=8;
    const int M=200000;
    int n,m;
    cin >> n >> m;
    vector<int> cnt(m,0);
    for(int i=0;i<n;i++)
    {
        int a;
        cin >> a;
        cnt[a-1]^=1;
    }
    vector<int> sum(m,0);
    sum[0]=cnt[0];
    for(int i=1;i<m;i++) sum[i]=(sum[i-1]^cnt[i]);
    vector<bitset<M>> v[k+1];
    for(int a=0;a<=k;a++)
    {
        for(int s=0;s<min(m,(1<<(a+1)));s++)
        {
            //shift s
            bitset<M> b;
            bool now=0;
            for(int i=s;i<m;i++)
            {
                if(((i-s)/(1<<a))&1) now^=cnt[i];
                b[i]=now;
            }
            v[a].push_back(b);
        }
    }
    int q;
    cin >> q;
    while(q--)
    {
        int l,r;
        cin >> l >> r;
        l--;
        r--;
        bool ok=1;
        for(int a=0;a<=k;a++)
        {
            int s=(l%(1<<(a+1)));
            ok&=((v[a][s][l]^v[a][s][r])==0);
        }
        for(int a=k+1;(1<<a)<=m;a++)
        {
            int x=0;
            for(int i=l+(1<<a);i<=r;i+=(1<<(a+1))) x^=(sum[min(r,i+(1<<a)-1)]^sum[i-1]);
            ok&=(x==0);
        }
        cout << "AB"[ok];
    }
    cout << "\n";
    return 0;
}