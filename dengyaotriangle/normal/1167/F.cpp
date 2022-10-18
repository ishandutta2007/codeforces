#include<bits/stdc++.h>

using namespace std;

const int maxn=500006;
const long long mdn=1000000007;
struct poi{
    int i,v;
};

poi sx[maxn];
long long ans[maxn];
int n;
int a[maxn];
long long bit[2][maxn];

bool cmp(poi a,poi b){
    return a.v<b.v;
}

int lbt(int n){
    return n&(-n);
}
void add(long long x,int i,int id){
    while(i<=n){
        bit[id][i]=(bit[id][i]+x)%mdn;
        i+=lbt(i);
    }
}
long long qry(int i,int id){
    long long ans=0;
    while(i>0){
        ans=(ans+bit[id][i])%mdn;
        i-=lbt(i);
    }
    return ans;
}
int main(){
    cin>>n;
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
        sx[i].i=i;sx[i].v=a[i];
    }
    sort(sx+1,sx+1+n,cmp);
    long long an=0;
    for(int i=1;i<=n;i++) ans[i]=(mdn-((long long)(sx[i].i)*(long long)(n-sx[i].i+1))%mdn)%mdn;
    for(int i=1;i<=n;i++){
        add(sx[i].i,sx[i].i,0);
        add(n-sx[i].i+1,sx[i].i,1);
        ans[i]+=(n-sx[i].i+1)*qry(sx[i].i,0);
        ans[i]+=sx[i].i*(qry(n,1)-qry(sx[i].i-1,1)+mdn)%mdn;
        ans[i]%=mdn;
    }
    long long cnt=0;
    for(int i=1;i<=n;i++){
        cnt+=ans[i]*sx[i].v;
        cnt%=mdn;
    }
    cout<<cnt;
    return 0;
}//qwq