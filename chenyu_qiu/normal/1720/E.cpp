#include <bits/stdc++.h>
#define fi first    
#define se second    
#define endl '\n'
#define ios ios::sync_with_stdio(false); cin.tie(0), cout.tie(0)
typedef long long LL;
using namespace std;
const int N = 1e5 + 10,M = N*2,INF = 0x3f3f3f3f;
 
struct Node
{
    int mix,mxx,miy,mxy;
    Node():mix(INF),mxx(-INF),miy(INF),mxy(-INF){};
};
 
void solve() {
    int n,k;cin>>n>>k;
    vector<Node> b(n*n);
    vector<int> c(n*n);
    int cnt = 0;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            int x;cin>>x;--x;
            if(!c[x]++) ++cnt;
            b[x].mix = min(b[x].mix,i);b[x].mxx = max(b[x].mxx,i);
            b[x].miy = min(b[x].miy,j);b[x].mxy = max(b[x].mxy,j);
        }
    }
    if(k>=cnt)
    {
        cout<<k-cnt<<'\n';
        return ;
    }
    vector<vector<int>> s(n+2,vector<int>(n+2));
    for(int len=0;len<n;len++)
    {
        for(int i=1;i<=n-len;i++) fill(s[i].begin(),s[i].end(),0);
        for(int i=0;i<n*n;i++)
        {
            if(!c[i]||b[i].mxx-b[i].mix>len||b[i].mxy-b[i].miy>len) continue;
            int mxx = b[i].mix,mix = max(b[i].mxx-len,1);
            int mxy = b[i].miy,miy = max(b[i].mxy-len,1);
            ++s[mix][miy];--s[mix][mxy+1];
            --s[mxx+1][miy];++s[mxx+1][mxy+1];
        }
        for(int i=1;i<=n-len;i++)
            for(int j=1;j<=n-len;j++)
                s[i][j] += s[i][j-1] + s[i-1][j] - s[i-1][j-1];
        for(int i=1;i<=n-len;i++)
            for(int j=1;j<=n-len;j++)
                if(cnt-s[i][j]==k||cnt-s[i][j]==k-1)
                {
                    cout<<"1\n";
                    return ;
                }
    }
    cout<<"2\n";
}
 
int main() 
{
    ios;
    int T=1;
    // cin>>T;
 
    while(T -- ) {
        solve();
    }
 
    return 0;
}