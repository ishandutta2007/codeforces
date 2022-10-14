#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
typedef pair<int,int> pii;
typedef pair<lli,lli> pll;
template<typename T>
int sz(const T &a){return (int)a.size();}
int arr[41];
lli dp[50][50][2];
int needed;
lli go(int loc, int am, bool top){
    if(loc==-1){
        if(am==needed)return 1;
        return 0;
    }
    if(dp[loc][am][top]!=-1)return dp[loc][am][top];
    lli ans=0;
    for(int i=0;i<=(top?arr[loc]:1);i++){
        ans+=go(loc-1,am+(i==1),top&&(i==arr[loc]));
    }
    return dp[loc][am][top]=ans;
}
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    lli n,t;
    cin>>n>>t;
    if(__builtin_popcountll(t)!=1){
        printf("0\n");
        return 0;
    }
    needed=64-__builtin_clzll(t);
    n++;
    for(lli i=0;i<=40;i++)arr[i]=(n&(((lli)1)<<i)?1:0);
    for(int i=0;i<50;i++)for(int j=0;j<50;j++)for(int l=0;l<2;l++)dp[i][j][l]=-1;
    printf("%lli\n",go(40,0,1)-(t==1?1:0));
    return 0;
}