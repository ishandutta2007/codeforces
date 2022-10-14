#include<bits/stdc++.h>
using namespace std;
typedef long long int lli;
typedef pair<int,int> pii;
typedef pair<lli,lli> pll;
template<typename T>
int sz(const T &a){return (int)a.size();}
double am[12];
double te[12];
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int n,t;
    cin>>n>>t;
    memset(am,0,sizeof(am));
    am[1]=t;
    int ans=0;
    for(int i=1;i<=n;i++){
        memset(te,0,sizeof(te));
        for(int j=1;j<=i;j++){
            if(am[j]>=1)ans++;
            am[j]-=1;
            if(am[j]>0) {
                te[j] += am[j] / 2;
                te[j + 1] += am[j] / 2;
            }
        }
        for(int j=1;j<=i+1;j++)am[j]=te[j];
    }
    printf("%d\n",ans);
    return 0;
}