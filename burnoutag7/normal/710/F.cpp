#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const int mod=998244353;

char s[300005];
int n,h[300005],pw[300005];
set<int> sh[205];
set<pair<int,int>> lo;

void add(){
    if(n<=130){
        sh[n].emplace(h[n]);
    }else{
        lo.emplace(n,h[n]);
    }
}

void del(){
    if(n<=130){
        sh[n].erase(h[n]);
    }else{
        lo.erase(make_pair(n,h[n]));
    }
}

int qry(){
    int ans=0;
    for(int len=1;len<=min(n,130);len++){
        for(int i=len;i<=n;i++){
            ans+=sh[len].find((h[i]-(ll)h[i-len]*pw[len]%mod+mod)%mod)!=sh[len].end();
        }
    }
    for(auto &[len,val]:lo){
        for(int i=len;i<=n;i++){
            ans+=val==(h[i]-(ll)h[i-len]*pw[len]%mod+mod)%mod;
        }
    }
    return ans;
}

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    pw[0]=1;
    for(int i=1;i<=3e5;i++){
        pw[i]=pw[i-1]*26ll%mod;
    }
    int q;
    cin>>q;
    while(q--){
        char typ;
        cin>>typ>>s+1;
        n=strlen(s+1);
        for(int i=1;i<=n;i++)h[i]=(h[i-1]*26ll+s[i]-'a')%mod;
        if(typ=='1'){
            add();
        }else if(typ=='2'){
            del();
        }else cout<<qry()<<endl;
    }

    return 0;
}