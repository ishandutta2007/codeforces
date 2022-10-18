#include<bits/stdc++.h>
using namespace std;
//dengyaotriangle!

const int maxn=5005;
const int mdn=998244353;

int st2[maxn][maxn];

template<int mdn>inline int qpw(int bse,int ex){int ans=1;while(ex){if(ex&1)ans=ans*(long long)bse%mdn;ex>>=1;bse=bse*(long long)bse%mdn;}return ans;}

int main(){
    st2[0][0]=1;
    for(int i=1;i<maxn;i++){
        for(int j=1;j<=i;j++)st2[i][j]=(st2[i-1][j-1]+st2[i-1][j]*(long long)j)%mdn;
    }
    int n,m,k;cin>>n>>m>>k;
    int ans=0,p=qpw<mdn>(m,mdn-2);
    int dw=1;
    for(int i=0;i<=k;i++){
        int cur=st2[k][i]*(long long)dw%mdn*qpw<mdn>(p,i)%mdn;ans=(ans+cur)%mdn;
        dw=dw*(long long)(n-i)%mdn;
    }
    cout<<ans;
    return 0;
}