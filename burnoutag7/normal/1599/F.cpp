#include<bits/stdc++.h>
using namespace std;

struct mint{
    int val;
    static int mod;
    typedef long long ll;
    mint(int v=0){
        val=v%mod;
    }
    mint operator+(mint a){
        return mint(val+a.val);
    }
    mint operator-(mint a){
        return mint(val-a.val+mod);
    }
    mint operator*(mint a){
        return mint((ll)val*a.val%mod);
    }
    mint qpow(int n){
        mint res(1),a(*this);
        while(n){
            if(n&1)res=res*a;
            a=a*a;
            n>>=1;
        }
        return res;
    }
    mint operator/(mint a){
        return mint((ll)val*a.qpow(mod-2).val%mod);
    }
    bool operator==(mint a){
        return val==a.val;
    }
};

istream& operator>>(istream& in,mint& a){
    in>>a.val;
    return in;
}

ostream& operator<<(ostream& out,mint a){
    out<<a.val;
    return out;
}

int mint::mod=1e9+7;

int n,q;
mint a[200005],ps[200005],pps[200005],seq[200005];

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin>>n>>q;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        ps[i]=ps[i-1]+a[i];
        pps[i]=pps[i-1]+a[i]*a[i];
        seq[i]=seq[i-1]+mint(i)*i;
    }
    while(q--){
        int l,r,d;
        cin>>l>>r>>d;
        int len=r-l+1;
        mint cur=pps[r]-pps[l-1];
        mint mn=((ps[r]-ps[l-1])*2/len-mint(len-1)*d)/2;
        mint dsr=mn*mn*len+mn*(len-1)*len*d+seq[r-l]*d*d;
        cout<<(cur==dsr?"Yes\n":"No\n");
    }

    return 0;
}