#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int bs,n,m,q;
ll a[100005],b[100005],c[100005];
vector<int> s[100005],ps[100005],bigs;
int g[100005][350];

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin>>n>>m>>q;
    bs=sqrt(n);
    for(int i=1;i<=n;i++)cin>>a[i];
    for(int i=1;i<=m;i++){
        static int sz;
        cin>>sz;
        while(sz--){
            s[i].emplace_back();
            cin>>s[i].back();
            ps[s[i].back()].emplace_back(i);
        }
        if(s[i].size()>bs){
            bigs.emplace_back(i);
        }
    }
    for(int i=1;i<=n;i++){
        for(int &x:ps[i])b[x]+=a[i];
    }
    for(int i=0;i<bigs.size();i++){
        for(int &x:s[bigs[i]]){
            for(int &j:ps[x]){
                g[j][i]++;
            }
        }
    }
    while(q--){
        char typ;
        cin>>typ;
        int k,x;
        if(typ=='+'){
            cin>>k>>x;
            if(s[k].size()>bs){
                c[k]+=x;
            }else{
                for(int &i:s[k])a[i]+=x;
            }
            for(int i=0;i<bigs.size();i++){
                b[bigs[i]]+=g[k][i]*(ll)x;
            }
        }else{
            cin>>k;
            if(s[k].size()>bs){
                cout<<b[k]<<'\n';
            }else{
                ll ans=0;
                for(int &i:s[k])ans+=a[i];
                for(int i=0;i<bigs.size();i++){
                    ans+=g[k][i]*(ll)c[bigs[i]];
                }
                cout<<ans<<'\n';
            }
        }
    }

    return 0;
}