#include<bits/stdc++.h>
using namespace std;
//dengyaotriangle!

const int maxn=4005;
const int mdn=1000000007;

int n;
int st2[maxn][maxn];
int inv[maxn];

int main(){
    cin>>n;
    inv[1]=1;for(int i=2;i<=n;i++)inv[i]=inv[mdn%i]*(long long)(mdn-mdn/i)%mdn;
    st2[0][0]=1;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=i;j++){
            st2[i][j]=(st2[i-1][j-1]+st2[i-1][j]*(long long)j)%mdn;
        }
    }
    int ans=0,w=1;
    for(int i=0;i<n;i++){
        int s=0;
        for(int j=0;j<=i;j++){
            s=(s+st2[i][j])%mdn;
        }
        ans=(ans+s*(long long)w)%mdn;
        w=w*(long long)inv[i+1]%mdn*(n-i)%mdn;
    }
    cout<<ans;
    return 0;
}