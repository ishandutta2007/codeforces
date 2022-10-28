#include<bits/stdc++.h>
using namespace std ;

#define ll long long

const int N = 500005;
int f[N];
string a;
ll sum = 0;

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n;
    cin>>n>>a;
    int cnt = 0;
    ll ans = 0;
    for(int i=0;i<n;++i)
    {
        if(a[i]=='1')
        {
            ++cnt;
            ans += (cnt+1)*1LL*cnt/2;
            sum += f[cnt-1];
            f[cnt] += f[cnt-1];
            f[cnt-1] = 0;
            ans += sum;
        }
        else
        {
            for(int j=0;j<=cnt;++j)
                ++f[j], sum += j;
            cnt = 0;
            ans += sum;
        }
    }
    cout<<ans<<"\n";
    return 0;
}