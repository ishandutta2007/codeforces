#include <bits/stdc++.h>
using namespace std;
#define pb                push_back
#define all(x)                   (x).begin(),(x).end()
#define int               long long
#define M                 1000000007
#define MM                998244353
#define fr                first
#define sc                second
#define vc                vector
#define pii               pair<int,int>
#define msi               map<string,int>
#define mii               map<int,int>
#define psi               pair<string,int>
#define pis               pair<int,string>
#define piii              pair<int,pii>
int gcd(int a,int b){
    if(b==0)return a;
    return gcd(b,a%b);
}
int pw(int a,int b,int p){
    if(b==0)return 1;
    int t=pw(a,b/2,p);
    if(b%2)return ((a*t*t)%p);
    else return ((t*t)%p);
}

int n,m,x,y,cost[2][1005],val[1005][2][1005];
int dp(int pos,int c,int s){
    if(pos==m){
        return 0;
    }
    int &ans=val[pos][c][s];
    if(ans!=-1)return ans;ans=M;
    if(s<y)ans=min(ans,dp(pos+1,c,s+1)+cost[c][pos]);
    if(s>=x&&(m-pos>=x))ans=min(ans,dp(pos+1,1-c,1)+cost[1-c][pos]);
    return ans;
}
void solve(){
    memset(val,-1,sizeof(val));
    cin>>n>>m>>x>>y;
    string s;
    for(int i=0;i<n;i++){
        cin>>s;
        for(int j=0;j<m;j++){
            if(s[j]=='.')cost[0][j]++;
            else cost[1][j]++;
        }
    }
    //for(int i=0;i<m;i++)cout<<cost[0][i]<<" "<<cost[1][i]<<"\n";
    int a,b;
    a=dp(0,0,0);
    b=dp(0,1,0);
    cout<<min(a,b);
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