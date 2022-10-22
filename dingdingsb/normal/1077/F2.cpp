#include<bits/stdc++.h>
using namespace std;
#define int long long
inline int read(){
    char c=getchar();int x=0;bool f=0;
    for(;!isdigit(c);c=getchar())f^=!(c^45);
    for(;isdigit(c);c=getchar())x=(x<<1)+(x<<3)+(c^48);
    if(f)x=-x;return x;
}
deque<int>q[6000];
int f[6000][6000];
int n,k,x;
//xk
int a[6000];
signed main(){
    n=read();k=read();x=read();
    for(int i=1;i<=n;i++)a[i]=read();
    memset(f,-0x3f,sizeof f);
    f[0][0]=0;q[0].push_back(0);
    for(int i=1;i<=n;i++)
        for(int j=x;j>0;j--){
            //f[i][j]=max(f[k][j-1])+a[i]
            while(q[j-1].size()&&q[j-1].front()<i-k)q[j-1].pop_front();
            if(q[j-1].size()){
                f[i][j]=f[q[j-1].front()][j-1]+a[i];
                while(q[j].size()&&f[q[j].back()][j]<=f[i][j])q[j].pop_back();
                q[j].push_back(i);
            }
        }
    int ans=-0x3f3f3f3f;
    for(int i=n-k+1;i<=n;i++)ans=max(ans,f[i][x]);
    printf("%lld",ans>=0?ans:-1);
}