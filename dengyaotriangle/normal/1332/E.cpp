#include<bits/stdc++.h>
using namespace std;
//dengyaotriangle!
 
const int mdn=998244353;
 
inline int qpw(int bse,long long ex){int ans=1;while(ex){if(ex&1)ans=ans*(long long)bse%mdn;ex>>=1;bse=bse*(long long)bse%mdn;}return ans;}
 
int main(){
    int n,m,l,r;
    cin>>n>>m>>l>>r;
    if(((long long)n*m)&1){cout<<qpw((r-l+1)%mdn,n*(long long)m);}
    else{
        cout<<((mdn+1)/2)*(long long)(qpw((r-l+1)%mdn,n*(long long)m)+((r-l+1)&1))%mdn;
    }
    return 0;
}