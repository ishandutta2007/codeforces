#include<bits/stdc++.h>
using namespace std;
//dengyaotriangle!

const int mdn=998244353;
const int maxn=100005;

int n;
char s[maxn];
int fac[maxn],ifac[maxn];

inline int qpw(int bse,int ex){int ans=1;while(ex){if(ex&1)ans=ans*(long long)bse%mdn;ex>>=1;bse=bse*(long long)bse%mdn;}return ans;}

int main(){
    fac[0]=1;for(int i=1;i<maxn;i++)fac[i]=fac[i-1]*(long long)i%mdn;
    ifac[maxn-1]=qpw(fac[maxn-1],mdn-2);
    for(int i=maxn-1;i>0;i--)ifac[i-1]=ifac[i]*(long long)i%mdn;

    ios::sync_with_stdio(0);cin.tie(0);
    int wt;
    cin>>wt;
    while(wt--){
        cin>>n>>(s+1);
        int ans=1,l=0,w=0,t=-1;
        for(int i=1;i<=n+1;i++){
            if(i==n+1||s[i]=='0'){
                w+=l/2;
                t++;l=0;
            }else l++;
        }
        cout<<fac[w+t]*(long long)ifac[w]%mdn*ifac[t]%mdn<<'\n';
    }
    return 0;
}