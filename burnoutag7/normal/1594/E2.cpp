#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const int mod=1e9+7;

int stage(ll n){
    return 64-__builtin_clzll(n);
}

string rubik[]={"white","yellow","green","blue","red","orange"};

int getcolor(const string &s){
    for(int i=0;;i++){
        if(s==rubik[i])return i;
    }
    return -1;
}

struct node{
    int val[6];
    node(int c=-1){
        if(c!=-1){
            fill(val,val+6,0);
            val[c]=1;
        }else{
            fill(val,val+6,1);
        }
    }
    void merge(const node &a,const node &b,int c=-1){
        for(int i=0;i<6;i++)if(val[i]){
            val[i]=0;
            for(int j=0;j<6;j++)if(i!=j&&(i^1)!=j){
                for(int k=0;k<6;k++)if(i!=k&&(i^1)!=k){
                    val[i]=(val[i]+(ll)a.val[j]*b.val[k])%mod;
                }
            }
        }
    }
    int get(){
        return accumulate(val,val+6,0ll)%mod;
    }
};

int n,k;
node a[65];
map<ll,node> b;

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin>>k>>n;
    for(int i=k-1;i>=1;i--)a[i].merge(a[i+1],a[i+1]);
    for(int i=1;i<=n;i++){
        ll v;
        string s;
        cin>>v>>s;
        b[v]=node(getcolor(s));
        while(v>1){
            v>>=1;
            if(b.count(v))break;
            b[v]=node();
        }
    }
    for(auto it=b.end();it!=b.begin();){
        --it;
        if(stage(it->first)<k){
            it->second.merge(b.count(it->first<<1)?b[it->first<<1]:a[stage(it->first)+1],b.count(it->first<<1|1)?b[it->first<<1|1]:a[stage(it->first)+1]);
        }
    }
    cout<<(b.count(1)?b[1].get():a[1].get())<<'\n';

    return 0;
}