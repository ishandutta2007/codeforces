#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
typedef pair<int,int> pii;
typedef pair<lli,lli> pll;
template<typename T>
int sz(const T &a){return (int)a.size();}
map<int,int> dp;
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int n;
    cin>>n;
    int a;
    int ans=1;
    for(int i=0;i<n;i++){
        cin>>a;
        set<int> prime;
        for(int j=2;j<=sqrt(a);j++){
            while(a%j==0){
                a/=j;
                prime.insert(j);
            }
        }
        if(a>1)prime.insert(a);
        int best=0;
        for(int x:prime){
            best=max(best,dp[x]);
        }
        ans=max(ans,best+1);
        for(int x:prime)dp[x]=best+1;
    }
    printf("%d\n",ans);
    return 0;
}