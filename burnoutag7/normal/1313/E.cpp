#include<bits/stdc++.h>
using namespace std;

void z_algorithm(char *s,int *z,int n){
    memset(z,0,n<<2);
    int c=0;
    for(int i=1;i<n;i++){
        if(i+z[i-c]<c+z[c]){
            z[i]=z[i-c];
        }else{
            z[i]=max(0,c+z[c]-i);
            while(i+z[i]<n&&s[z[i]]==s[i+z[i]])z[i]++;
            c=i;
        }
    }
    z[0]=n;
}

template<typename T> struct BIT{
    int sz;
    vector<T> bit;

    BIT(int _sz=0){
        sz=_sz;
        bit.resize(sz+1);
    }

    T sum(int pos){
        T res=0;
        while(pos>0){
            res+=bit[pos];
            pos-=pos&-pos;
        }
        return res;
    }

    void add(int pos,T val){
        while(pos<=sz){
            bit[pos]+=val;
            pos+=pos&-pos;
        }
    }

    void clear(){
        bit.assign(sz+1,0);
    }
};

typedef long long ll;

struct yabit{
    BIT<ll> rect,triv;
    int sz;
    yabit(int _sz=0){
        rect=triv=BIT<ll>((sz=_sz)+1);
    }
    void add(int pos,ll val){
        rect.add(pos,val);
        if(pos>1){
            triv.add(pos,-val*(pos-1));
        }
    }
    ll sum(int pos){
        return pos*rect.sum(pos)+triv.sum(pos);
    }
};

int n,m,fa[500005],fb[500005],z[1500005];
char a[500005],b[500005],s[1000005],t[1500005];

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin>>n>>m;
    cin>>a+1>>b+1>>s+1;
    {
        memcpy(t+1,s+1,m-1);
        t[m]='#';
        memcpy(t+m+1,a+1,n);
        z_algorithm(t+1,z+1,n+m);
        for(int i=1;i<=n;i++)fa[i]=z[i+m];
    }
    {
        memcpy(t+1,s+2,m-1);
        reverse(t+1,t+m);
        t[m]='#';
        memcpy(t+m+1,b+1,n);
        reverse(t+m+1,t+m+1+n);
        z_algorithm(t+1,z+1,n+m);
        for(int i=1;i<=n;i++)fb[i]=z[n+1-i+m];
    }
    ll ans=0;
    yabit ya(m);
    for(int l1=1,r2l=1,r2r=1;l1<=n;l1++){
        while(r2r<=min(l1+m-2,n))ya.add(m-fb[r2r++],1);
        while(r2l<l1)ya.add(m-fb[r2l++],-1);
        ans+=ya.sum(fa[l1]);
    }
    cout<<ans;

    return 0;
}