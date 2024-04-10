#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define int long long
#define M 1000000007
#define MM 998244353
#define fr first
#define sc second
#define vc vector
#define pii pair<int,int>
#define msi map<string,int>
#define mii map<int,int>
#define psi pair<string,int>
#define pis pair<int,string>
#define piii pair<int,pii>
int gcd(int a,int b){
    if(b==0)return a;
    return gcd(b,a%b);
}

int fail=0;
vc<int> v[100005];
int s[100005],a[100005],b[100005],vis[100005],vis2[100005];
void dfs(int z,int sum){
    vis[z]=1;
    if(s[z]==-1)s[z]=sum;
    if(sum==s[z])b[z]=0;
    else if(sum>s[z]){
        fail=1;
        return;
    }
    else{
        b[z]=s[z]-sum;
    }
    for(int x:v[z]){
        if(!vis[x])dfs(x,s[z]);
        if(fail)return;
    }
}
void dfs2(int z,int h){
    vis2[z]=1;
    for(int x:v[z]){
        if(!vis2[x])dfs2(x,h+1);
    }
    if(h%2==0){
        int k=-1;
        for(int x:v[z]){
            if(k==-1||k>b[x])k=b[x];
        }
        if(k==-1)k=0;
        for(int x:v[z])b[x]-=k;
        b[z]+=k;
    }
}
void solve(){
    int n;
    cin>>n;
    for(int i=2;i<=n;i++){
        int t;
        cin>>t;
        //v[i].pb(t);
        v[t].pb(i);
    }
    for(int i=1;i<=n;i++)cin>>s[i];
    a[1]=s[1];b[1]=s[1];
    memset(b,-1,sizeof(b));
    dfs(1,0);
    if(fail){
        cout<<-1;
        return;
    }
    dfs2(1,1);
    int sum=0;
    for(int i=1;i<=n;i++){
        sum+=b[i];
    }
    cout<<sum;
}
signed main(){
    ios_base::sync_with_stdio(false);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int t=1;
    //cin>>t;
    while(t--) solve();
    return 0;
}