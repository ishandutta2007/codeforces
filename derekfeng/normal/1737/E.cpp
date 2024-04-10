#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int M=1e9+7,N=1e6+4;
int n,f[N],s[N],ans[N],pw[N];
int myp(int x,int t){
    int a=1;
    for(;t;t>>=1,x=(ll)x*x%M)if(t&1)a=(ll)a*x%M;
    return a;
}
void sol(){
    scanf("%d",&n);
    if(n==1){puts("1");return;}
    f[n]=s[n]=1,s[n+1]=0;
    for(int i=n-1;i>1;i--){
        int p=min(i+i-1,n);
        f[i]=(s[i+1]-s[p+1]+M)%M;
        s[i]=(s[i+1]+f[i])%M;
    }
    for(int i=1;i<n;i++)ans[i]=(ll)pw[i>>1]*f[i]%M*2%M;
    ans[n]=pw[(n>>1)+1];
    int iv=myp(pw[n],M-2);
    for(int i=1;i<=n;i++)printf("%d\n",(ll)ans[i]*iv%M);
}
int main(){
    pw[0]=1;for(int i=1;i<N;i++)pw[i]=(pw[i-1]+pw[i-1])%M;
    int tc;scanf("%d",&tc);
    while(tc--)sol();
}