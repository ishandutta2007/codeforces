#include<bits/stdc++.h>
using namespace std;
//dengyaotriangle!

const int maxn=5005;
const int mdn=1000000007;

int st2[maxn][maxn];

template<int mdn>inline int qpw(int bse,int ex){int ans=1;while(ex){if(ex&1)ans=ans*(long long)bse%mdn;ex>>=1;bse=bse*(long long)bse%mdn;}return ans;}

int main(){
    st2[0][0]=1;
    for(int i=1;i<maxn;i++){
        st2[i][0]=0;
        for(int j=1;j<=i;j++)st2[i][j]=(st2[i-1][j-1]+st2[i-1][j]*(long long)j)%mdn;
    }
    int n,k;cin>>n>>k;
    int ans=0,dw=1;
    for(int i=0;i<=min(n,k);i++){
        int cur=st2[k][i]*(long long)dw%mdn*qpw<mdn>(2,n-i)%mdn;
        ans=(ans+cur)%mdn;
        dw=dw*(long long)(n-i)%mdn;
    }
    cout<<ans;
    return 0;
}