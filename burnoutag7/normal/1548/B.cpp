#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

ll gcd(ll a,ll b){
    while(b){
        a%=b;
        swap(a,b);
    }
    return a;
}

struct SparseTable{
    vector<vector<ll>> st;
    int n,m;
    SparseTable(ll *a,int sz){
        n=sz;m=0;
        while(1<<m<n)m++;
        st.resize(n+1,vector<ll>(m+1));
        for(int i=1;i<=n;i++)st[i][0]=a[i];
        for(int j=1;j<=m;j++)for(int i=1;i+(1<<j)-1<=n;i++)st[i][j]=gcd(st[i][j-1],st[i+(1<<j-1)][j-1]);
    }
    ll qry(int l,int r){
        static int s;
        s=31-__builtin_clz(r-l+1);
        return gcd(st[l][s],st[r-(1<<s)+1][s]);
    }
};

int n;
ll a[200005],g[200005][18];

void mian(){
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    if(n==1){
        cout<<"1\n";
        return;
    }
    for(int i=n-2;i>=0;i--){
        a[i+1]=abs(a[i+1]-a[i]);
    }
    n--;
    SparseTable st(a,n);
    int ans=1;
    for(int i=1;i<=n;i++){
        int l=i,r=n,m,res=i-1;
        while(l<=r){
            m=(l+r)/2;
            if(st.qry(i,m)==1){
                r=m-1;
            }else{
                l=m+1;
                res=m;
            }
        }
        ans=max(ans,res-i+2);
    }
    cout<<ans<<'\n';
}

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int T;
    cin>>T;
    while(T--)mian();

    return 0;
}