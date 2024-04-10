#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N=100005;

int phi[N],root[N];
ll pp[N],S1[N][320],S2[N][320];

void init(){
    iota(phi,phi+N,0);
    pp[1]=1;
    for(int i=2;i<N;i++){
        if(phi[i]==i){
            for(int j=i;j<N;j+=i)phi[j]-=phi[j]/i;
        }
        pp[i]=pp[i-1]+phi[i];
    }
    for(int i=1;i<N;i++){
        for(int j=1;j*j<=i;j++){
            S1[i][j]=S1[i][j-1]+pp[j]*(i/j-i/(j+1));
            root[i]=j;
        }
        S2[i][i/(root[i]+1)+1]=S1[i][root[i]];
        for(int j=i/(root[i]+1);j>=1;j--){
            S2[i][j]=S2[i][j+1]+pp[i/j];
        }
    }
}

ll c(int l,int r){
    if(l>r)return 1e12;
    if(r/l<=root[r]){
        return S1[r][r/l]-pp[r/l]*(l-1-r/(r/l+1));
    }else{
        return S2[r][l];
    }
}

ll f[N][17];

void sol(int l,int r,int optl,int optr,int k){
    if(l>r)return;
    int mid=l+r>>1,opt=optl;
    for(int i=optl+1;i<=min(optr,mid);i++){
        if(f[i-1][k-1]+c(i,mid)<f[opt-1][k-1]+c(opt,mid))opt=i;
    }
    f[mid][k]=f[opt-1][k-1]+c(opt,mid);
    sol(l,mid-1,optl,opt,k);
    sol(mid+1,r,opt,optr,k);
}

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    init();
    int n=1e5;
    for(int i=1;i<=n;i++){
        f[i][1]=c(1,i);
    }
    for(int i=2;i<=16;i++){
        sol(1,n,1,n,i);
    }
    int T;
    cin>>T;
    while(T--){
        int k;
        cin>>n>>k;
        if(k>=17||1<<k>n)cout<<n<<'\n';
        else cout<<f[n][k]<<'\n';
    }

    return 0;
}