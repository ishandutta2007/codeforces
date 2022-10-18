#include<bits/stdc++.h>
using namespace std;
//dengyaotriangle!

const int maxm=1000006;
const int maxn=505;
const int mdn=998244353;

int n,m,l;
int c[maxm];
int a[maxm];
long long dp[maxn<<1][maxn<<1];
vector<int> oc[maxn];

int main(){
    ios::sync_with_stdio(0);
    cin>>n>>m;    
    for(int i=1;i<=m;i++){cin>>c[i];}
    for(int i=1;i<=m;i++){
        if(i==1||c[i]!=c[i-1])a[++l]=c[i];
    }
    for(int i=1;i<=l;i++){
        oc[a[i]].push_back(i);
    }
    if(l>n+n){
        cout<<0;return 0;
    }
    for(int i=0;i<=l+1;i++){for(int j=0;j<=l+1;j++){dp[i][j]=1;}}
    for(int i=l;i>=1;i--){
        for(int j=i;j<=l;j++){
            int mi=a[i];
            for(int k=i;k<=j;k++){
                if(a[k]<mi)mi=a[k];
            }
            int fv=*oc[mi].begin(),ev=*(oc[mi].end()-1);
            if(fv<i||ev>j)dp[i][j]=0;
            else{
                long long mul=1;
                for(int i=1;i<oc[mi].size();i++){
                    mul=(mul*(dp[oc[mi][i-1]+1][oc[mi][i]-1]))%mdn;
                }
                long long sm0=0,sm1=0;
                for(int k=i;k<=fv;k++){sm0+=dp[k][fv-1]*dp[i][k-1];sm0%=mdn;}
                for(int k=j;k>=ev;k--){sm1+=dp[ev+1][k]*dp[k+1][j];sm1%=mdn;}
                cerr<<fv<<','<<ev<<endl;
                dp[i][j]=mul*sm0%mdn*sm1%mdn;
            }
        }
    }
    cout<<dp[1][l];
    return 0;
}