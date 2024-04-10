#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,k;
    cin >> n >> k;
    string s;
    cin >> s;
    vector<int> ones;
    for(int i=0;i<n;i++) if(s[i]=='1') ones.push_back(i);
    const int mod=998244353;
    auto add=[&](int a,int b){return a+b-(a+b>=mod?mod:0);};
    auto sub=[&](int a,int b){return a-b+(a-b<0?mod:0);};
    vector c(n+1,vector(n+1,int(0)));
    for(int i=0;i<=n;i++) c[i][0]=1;
    for(int i=1;i<=n;i++) for(int j=1;j<=i;j++) c[i][j]=add(c[i-1][j],c[i-1][j-1]);
    int res=0;
    int cnt=ones.size();
    if(cnt<k||k==0) res=1;
    else
    {
        ones.push_back(n);
        res=c[ones[k]][k];
        for(int i=1;i+k-1<cnt;i++)
        {
            res=add(res,c[ones[i+k]-1-(ones[i-1]+1)+1][k]);
            res=sub(res,c[ones[i+k-1]-1-(ones[i-1]+1)+1][k-1]);
        }
    }
    cout << res << "\n";
    return 0;
}