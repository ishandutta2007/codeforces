#include<bits/stdc++.h>
using namespace std;

int q,n,k,ans;
char s[200005],pat[4]={'R','G','B'};
int f[3][200005];

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    scanf("%d",&q);
    while(q--){
        scanf("%d %d",&n,&k);
        scanf("%s",s);
        ans=1e9;
        f[0][0]=0;
        f[1][0]=0;
        f[2][0]=0;
        for(int i=0;i<n;i++){
            f[0][i+1]=f[0][i];
            f[0][i+1]+=s[i]!=pat[i%3];
            f[1][i+1]=f[1][i];
            f[1][i+1]+=s[i]!=pat[(i+1)%3];
            f[2][i+1]=f[2][i];
            f[2][i+1]+=s[i]!=pat[(i+2)%3];
        }
        for(int i=1;i+k-1<=n;i++){
            ans=min(ans,f[0][i+k-1]-f[0][i-1]);
            ans=min(ans,f[1][i+k-1]-f[1][i-1]);
            ans=min(ans,f[2][i+k-1]-f[2][i-1]);
        }
        printf("%d\n",ans);
    }

    return 0;
}