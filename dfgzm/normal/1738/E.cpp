#include<bits/stdc++.h>
#define ll long long
#define outY puts("YES")
#define outN puts("NO")
using namespace std;
const int maxn=100010,mod=998244353;
int i,j,k,n,m,T,a[maxn],num[maxn],num2[maxn];
ll Sum[maxn],Sum2[maxn],dp[maxn],jc[maxn],ny[maxn];
map<ll,int>is;
ll ksm(ll sum,int num){
    ll ans=1;
    while(num){
        if(num&1)ans=ans*sum%mod;
        sum=sum*sum%mod;
        num>>=1;
    }return ans;
}
ll C(int x,int y){
    if(y>x || y<0)return 0;
    return jc[x]*ny[y]%mod*ny[x-y]%mod;
}
int main(){
    jc[0]=1;for(i=1;i<maxn;i++)jc[i]=jc[i-1]*i%mod;
    ny[maxn-1]=ksm(jc[maxn-1],mod-2);for(i=maxn-2;i>=0;i--)ny[i]=ny[i+1]*(i+1)%mod;
    cin>>T;
    while(T--){
        is.clear();
        cin>>n;
        for(i=1;i<=n;i++)scanf("%d",&a[i]),Sum[i]=Sum[i-1]+a[i];
        for(i=n;i>=1;i--){
            Sum2[i]=Sum[n]-Sum[i-1];
            if(a[i])is[Sum2[i]]=i;
        }
        if(Sum[n]==0){printf("%lld\n",ksm(2,n-1));continue;}
        ll All=0,Ans=0;
        int lst1=0,lst2=n+1;
        while(!a[lst1+1])lst1++;
        while(!a[lst2-1])lst2--;
        for(i=1;i<=n;i++)All+=(lst1==0 && i==1?1:C(lst1,i-1))*(lst2==n+1 && i==1?1:C(n-lst2+1,i-1)),All%=mod;
        Ans=All;
        // cerr<<"All="<<All<<endl;
        for(i=1;i<=n;i++)if(is[Sum[i]] && a[i]){
            if(2*Sum[i]>Sum[n])break;
            lst1=i;lst2=is[Sum[i]];
            int cnt1=0,cnt2=0;
            while(!a[lst1+1] && lst1<n)lst1++,cnt1++;
            while(!a[lst2-1] && lst2>1)lst2--,cnt2++;
            // cerr<<"i="<<i<<' '<<lst1<<' '<<lst2<<' '<<cnt1<<' '<<cnt2<<endl;
            if(lst1<lst2){
                ll Sum=0;
                for(j=1;j<=min(cnt1,cnt2)+1;j++)
                    Sum+=C(cnt1+1,j)*C(cnt2+1,j),Sum%=mod;
                Ans+=Sum*All;Ans%=mod;
                All+=Sum*All;All%=mod;
                // cerr<<"All="<<All<<' '<<Sum<<endl;
            }else{
                Ans+=All*(ksm(2,cnt1+1)-1)%mod;Ans%=mod;
            }
        }
        cout<<Ans<<endl;
    }
}