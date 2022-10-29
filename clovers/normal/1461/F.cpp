/*
the vast starry sky,
bright for those who chase the light.
*/
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define mk make_pair
void checkmin(int &x,int y){if(x>y) x=y;}
void checkmax(int &x,int y){if(x<y) x=y;}
#define out(x) cerr<<#x<<'='<<x<<' '
#define outln(x) cerr<<#x<<'='<<x<<endl
#define sz(x) (int)(x).size()
inline int read(){
    int x=0,f=1; char c=getchar();
    while(c>'9'||c<'0'){if(c=='-') f=-1; c=getchar();}
    while(c>='0'&&c<='9') x=(x<<1)+(x<<3)+(c^48),c=getchar();
    return x*f;
}
const int N=100005;
int n,a[N],dp[21],pre[21],sum[N],mul[N],pos[N];
char s[10];
int bl[3];//+ - *
int ans[N];
void solve(int l,int r){
    if(l>=r) return;
    if(!bl[0]){
        for(int i=l;i<r;i++) ans[i]=2;
        return;
    }
    int cnt=0;
    int tmp=1;
    for(int i=l;i<=r;i++){
        if(a[i]!=1){
            pos[++cnt]=i;
            if(tmp<=n) tmp*=a[i];
        }
    }
    if(cnt) for(int i=l;i<pos[1];i++) ans[i]=0;
    if(cnt) for(int i=pos[cnt];i<r;i++) ans[i]=0;
    if(tmp>n){
        for(int i=pos[1];i<pos[cnt];i++) ans[i]=2;
        return;
    }
    if(!cnt){
        for(int i=l;i<r;i++) ans[i]=0;
        return;
    }
    memset(dp,0,sizeof(dp));
    mul[l-1]=1;
    for(int i=l;i<=r;i++) mul[i]=mul[i-1]*a[i];
    dp[0]=pos[1]-l; pos[0]=pos[1]-1;
    dp[1]=dp[0]+a[pos[1]];
    for(int i=2;i<=cnt;i++){
        for(int j=0;j<i;j++){
            int tmp=dp[j]+pos[j+1]-1-pos[j]+mul[pos[i]]/mul[pos[j]];
            if(dp[i]<tmp){
                dp[i]=tmp;
                pre[i]=j;
            }
        }
    }
    int now=cnt;
    while(now){
        int p=pre[now];
        if(p) for(int i=pos[p];i<pos[p+1];i++) ans[i]=0;
        for(int i=pos[p+1];i<pos[now];i++) ans[i]=2;
        now=p;
    }
}

int main()
{
    n=read();
    for(int i=1;i<=n;i++) a[i]=read();
    scanf("%s",s+1);
    int len=strlen(s+1);
    for(int i=1;i<=len;i++){
        if(s[i]=='+') bl[0]=1;
        else if(s[i]=='-') bl[1]=1;
        else bl[2]=1;
    }
    if(len==1){
        for(int i=1;i<n;i++){
            printf("%d%c",a[i],s[1]);
        }
        printf("%d\n",a[n]);
        return 0;
    }
    if(!bl[2]){
        for(int i=1;i<n;i++){
            printf("%d+",a[i]);
        }
        printf("%d\n",a[n]);
        return 0;
    }
    a[n+1]=0; int pre=1;
    for(int i=1;i<=n+1;i++){
        if(!a[i]){
            if(bl[0]) ans[i-1]=ans[i]=0;
            else ans[i-1]=1,ans[i]=2;
            solve(pre,i-1);
            pre=i+1;
        }
    }
    for(int i=1;i<n;i++){
        printf("%d",a[i]);
        if(ans[i]==0) printf("+");
        else if(ans[i]==1) printf("-");
        else printf("*");
    }
    printf("%d\n",a[n]);
    return 0;
}