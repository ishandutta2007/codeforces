#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll inf=1e18;

ll add(ll a,ll b){
    return min(a+b,inf);
}

int match(const string &s,const string &p,int cover){
    string t=p+s;
    int n=t.size(),m=p.size();
    static vector<int> z;
    z.assign(n,0);
    int c=0;
    for(int i=1;i<n;i++){
        if(i+z[i-c]<c+z[c]){
            z[i]=z[i-c];
        }else{
            z[i]=max(0,c+z[c]-i);
            while(i+z[i]<n&&t[z[i]]==t[i+z[i]])z[i]++;
            c=i;
        }
    }
    z[0]=n;
    int res=0;
    for(int i=m;i+m-1<n;i++)if(cover==-1||i-m<cover&&i>cover){
        res+=z[i]>=m;
    }
    return res;
}

struct node{
    string pre,suf;
    ll cnt;
    node(){
        cnt=0;
    }
    node(const string &s,const string &pat){
        pre=suf=s;
        cnt=match(s,pat,-1);
    }
    node(const node &a,const node &b,const string &pat){
        cnt=add(a.cnt,b.cnt+match(a.suf+b.pre,pat,a.suf.size()));
        pre=a.pre+b.pre;
        pre=pre.substr(0,pat.size());
        suf=a.suf+b.suf;
        if(suf.size()>pat.size())suf=suf.substr(suf.size()-pat.size(),pat.size());
    }
};

ll startwith(int n,const string &pat){
    vector<node> f(n+1);
    f[0]=node("0",pat);
    f[1]=node("1",pat);
    for(int i=2;i<=n;i++)f[i]=node(f[i-2],f[i-1],pat);
    return f[n].cnt;
}

ll exact(int n,const string &pat){
    vector<node> f(n+1);
    f[0]=node("0",pat);
    f[1]=node("1",pat);
    for(int i=2;i<=n;i++)f[i]=node(f[i-2],f[i-1],pat);
    return f[n].suf==pat;
}

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n,m;
    ll k;
    cin>>n>>k>>m;
    string ans;
    while(k&&m){
        if(startwith(n,ans+'0')>=k){
            ans+='0';
            m--;
        }else{
            k-=startwith(n,ans+'0');
            m--;
            ans+='1';
        }
        k-=exact(n,ans);
    }
    cout<<ans;

    return 0;
}