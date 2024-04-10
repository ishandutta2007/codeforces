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

void Z(char *s,int *z,int n){
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

typedef long long ll;

struct Hash{
    int mod,len;
    vector<ll> h,pw;
    Hash(){

    }
    Hash(char *s,int _len,int _mod){
        len=_len;
        mod=_mod;
        h.resize(len+1);
        pw.resize(len+1);
        pw[0]=1;
        for(int i=1;i<=len;i++){
            pw[i]=pw[i-1]*10%mod;
            h[i]=(h[i-1]*10+s[i]-'0')%mod;
        }
    }
    ll get(int l,int r){
        static ll res;
        res=(h[r]-h[l-1]*pw[r-l+1])%mod;
        return res<0?res+mod:res;
    }
};

mt19937 rng(CodeforcesRandSeed());

bool isprime(int x){
    for(int i=2;i*i<=x;i++)if(x%i==0)return 0;
    return 1;
}

int randomprime(){
    int res=4;
    while(!isprime(res))res=1e9+rng()%5000;
    return res;
}

ll mods[]={(ll)1e9+7,998244353,19260817,randomprime(),randomprime()};

struct hashval5{
    ll h[5];
    hashval5(){

    }
    hashval5(Hash *s,int l,int r){
        for(int i=0;i<5;i++)h[i]=s[i].get(l,r);
    }
    hashval5& operator+=(const hashval5 &a){
        for(int i=0;i<5;i++)h[i]=(h[i]+a.h[i])%mods[i];
        return *this;
    }
    hashval5 operator+(const hashval5 &a){
        hashval5 res=*this;
        res+=a;
        return res;
    }
    bool operator==(const hashval5 &a){
        return !memcmp(h,a.h,sizeof(h));
    }
};

struct hash5{
    Hash h[5];
    hash5(){

    }
    hash5(char *s,int len){
        for(int i=0;i<5;i++)h[i]=Hash(s,len,mods[i]);
    }
    hashval5 get(int l,int r){
        return hashval5(h,l,r);
    }
    hashval5 get(int l1,int r1,int l2,int r2){
        return hashval5(h,l1,r1)+hashval5(h,l2,r2);
    }
};

int n,m,lcp[500005],zbox[700005];
char s[500005],t[200005],zstr[700005];
hash5 hs,ht;
hashval5 want;

void cmp(int l1,int r1,int l2,int r2){
    int carry=0;
    for(int i=0;i<m;i++){
        if(r1-i>=l1)carry+=s[r1-i]-'0';
        if(r2-i>=l2)carry+=s[r2-i]-'0';
        if(carry%10!=t[m-i]-'0')return;
        carry/=10;
    }
    if(!carry){
        cout<<l1<<' '<<r1<<'\n'<<l2<<' '<<r2;
        exit(0);
    }
}

void test(int l1,int r1,int l2,int r2){
    if(hs.get(l1,r1,l2,r2)==want){
        cmp(l1,r1,l2,r2);
    }
}

void check(int l,int r,int k){
    if(k>0){
        if(r+k<=n)test(l,r,r+1,r+k);
        if(l-k>=1)test(l-k,l-1,l,r);
    }
}

void deal(int l,int r){
    if(r-l+1<m){
        check(l,r,m);
        check(l,r,m-1);
    }else{
        int ps=l+lcp[l];
        check(l,r,r-ps+1);
        check(l,r,r-ps);
    }
}

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin>>s+1>>t+1;
    n=strlen(s+1);
    m=strlen(t+1);
    hs=hash5(s,n);
    ht=hash5(t,m);
    want=ht.get(1,m);
    memcpy(zstr+1,t+1,m);
    memcpy(zstr+m+1,s+1,n);
    Z(zstr+1,zbox+1,m+n);
    for(int i=1;i<=n;i++){
        lcp[i]=min(zbox[i+m],m);
    }
    for(int i=1;i+m-1<=n;i++)deal(i,i+m-1);
    if(m>1)for(int i=1;i+m-2<=n;i++)deal(i,i+m-2);

    return 0;
}