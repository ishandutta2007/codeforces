#include<bits/stdc++.h>
#include<windows.h>
using namespace std;

int CodeforcesRandSeed(){
    int x = GetCurrentProcessId();
    x ^= (int64_t)GetProcessHeap();
    x ^= (int64_t)HeapAlloc(GetProcessHeap(), 0, 1);
    auto dummy = new char;
    x ^= (int64_t)dummy;
    return x;
}

template<typename T> struct BIT{
    int sz;
    vector<T> bit;

    BIT(int _sz){
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

mt19937 rng(CodeforcesRandSeed());

int n,m,a[1000005],b[1000005],tmp[1000005];
vector<int> app[1000005],vx;

void deal(int al,int ar,int bl,int br){
    if(al>ar){
        for(int i=bl;i<=br;i++)app[al-1].emplace_back(b[i]);
        return;
    }
    if(bl>br)return;
    int id=rng()%(br-bl+1)+bl,mn=1e9,ans=-1;
    tmp[ar]=0;
    for(int i=ar-1;i>=al-1;i--){
        tmp[i]=tmp[i+1]+(a[i+1]<b[id]);
    }
    int pg=0;
    for(int i=al-1;i<=ar;i++){
        if(i>=al)pg+=a[i]>b[id];
        if(pg+tmp[i]<mn){
            mn=pg+tmp[i];
            ans=i;
        }
    }
    app[ans].emplace_back(b[id]);
    deal(al,ans,bl,id-1);
    deal(ans,ar,id+1,br);
}

void mian(){
    cin>>n>>m;
    app[0].clear();
    vx.clear();
    for(int i=1;i<=n;i++){
        cin>>a[i];
        app[i].clear();
        vx.emplace_back(a[i]);
    }
    for(int i=1;i<=m;i++){
        cin>>b[i];
        vx.emplace_back(b[i]);
    }
    sort(b+1,b+1+m);
    sort(vx.begin(),vx.end());
    vx.erase(unique(vx.begin(),vx.end()),vx.end());
    for(int i=1;i<=n;i++){
        a[i]=upper_bound(vx.begin(),vx.end(),a[i])-vx.begin();
    }
    for(int i=1;i<=m;i++){
        b[i]=upper_bound(vx.begin(),vx.end(),b[i])-vx.begin();
    }
    deal(1,n,1,m);
    int p=0;
    typedef long long ll;
    BIT<int> bit(vx.size());
    ll ans=0;
    for(int i=0;i<=n;i++){
        if(i){
            ans+=p-bit.sum(a[i]);
            bit.add(a[i],1);
            p++;
        }
        sort(app[i].begin(),app[i].end());
        for(int x:app[i]){
            ans+=p-bit.sum(x);
            bit.add(x,1);
            p++;
        }
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