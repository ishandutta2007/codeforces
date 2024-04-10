#include<bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define SZ(x) ((int)x.size())
#define FOR(i,a,b) for (int i=a;i<=b;++i)
#define FORD(i,a,b) for (int i=a;i>=b;--i)
using namespace std;
typedef long long LL;
typedef pair<int,int> pa;
typedef vector<int> vec;
void getint(int &v){
    char ch,fu=0;
    for(ch='*'; (ch<'0'||ch>'9')&&ch!='-'; ch=getchar());
    if(ch=='-') fu=1, ch=getchar();
    for(v=0; ch>='0'&&ch<='9'; ch=getchar()) v=v*10+ch-'0';
    if(fu) v=-v;
}

LL gcd(LL x,LL y){
    return (x%y==0?y:gcd(y,x%y));
}
LL f[300010][20],a[500010],b[500010];
int n,T,ans;

void doit(){
    scanf("%d",&n);
    FOR(i,1,n) scanf("%lld",&a[i]);
    if (n==1){
        puts("1");
        return;
    }
    FOR(i,1,n-1) b[i]=abs(a[i+1]-a[i]);
    --n;
    FOR(i,1,n) f[i][0]=b[i];
    FOR(j,1,17)
        FOR(i,1,n)
            if (i+(1<<j)-1<=n){
                f[i][j]=gcd(f[i][j-1],f[i+(1<<(j-1))][j-1]);
            }
    ans=0;
    FOR(l,1,n){
        if (b[l]==1) continue;
        int r=l;
        LL now=b[l];
        FORD(j,17,0)
            if (r+(1<<j)<=n){
                LL t = gcd(now,f[r+1][j]);
                if (t!=1) r+=1<<j,now=t;
            }
        ans=max(ans,r-l+1);
    }
    cout<<ans+1<<endl;
}
int main(){
    cin>>T;
    while (T--) doit();
	return 0;
}