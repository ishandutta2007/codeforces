#include<bits/stdc++.h>
//dengyaotriangle!
using namespace std;

const int maxn=1000006;
const int mdn=998244353;

typedef unsigned long long ull;

ull bse1=1283,mdn1=1000000009ull;
ull bse2=131,mdn2=1019260817ull;

int dp[maxn];
int sa,sl,sr;
char a[maxn],l[maxn],r[maxn];
ull ha1[maxn],hl1[maxn],hr1[maxn],pwr1[maxn];
ull ha2[maxn],hl2[maxn],hr2[maxn],pwr2[maxn];


bool cmp(ull* th1,ull* th2,int lp,int len){
    return ((th1[len]+ha1[lp]*pwr1[len])%mdn1==ha1[lp+len])&&((th2[len]+ha2[lp]*pwr2[len])%mdn2==ha2[lp+len]);
}
int main(){
    ios::sync_with_stdio(0);
    cin>>(a+1)>>(l+1)>>(r+1);
    sa=strlen(a+1);
    sl=strlen(l+1);
    sr=strlen(r+1);
    for(int i=1;i<=sa;i++) ha1[i]=(ha1[i-1]*bse1+a[i])%mdn1;
    for(int i=1;i<=sl;i++) hl1[i]=(hl1[i-1]*bse1+l[i])%mdn1;
    for(int i=1;i<=sr;i++) hr1[i]=(hr1[i-1]*bse1+r[i])%mdn1;
    pwr1[0]=1;
    for(int i=1;i<maxn;i++) pwr1[i]=(pwr1[i-1]*bse1)%mdn1;
    for(int i=1;i<=sa;i++) ha2[i]=(ha2[i-1]*bse2+a[i])%mdn2;
    for(int i=1;i<=sl;i++) hl2[i]=(hl2[i-1]*bse2+l[i])%mdn2;
    for(int i=1;i<=sr;i++) hr2[i]=(hr2[i-1]*bse2+r[i])%mdn2;
    pwr2[0]=1;
    for(int i=1;i<maxn;i++) pwr2[i]=(pwr2[i-1]*bse2)%mdn2;
    dp[0]=1;dp[1]=mdn-1;
    for(int i=0;i<=sa;i++){
        if(i)dp[i]=(dp[i]+dp[i-1])%mdn;
        if(i==sa){
            cout<<dp[i];
            return 0;
        }
        if(a[i+1]!='0'){
            int pl=i+sl,pr=i+sr,rpl,rpr;
            if(pl<=sa){
                if(pr>sa)rpr=sa;
                else{
                    int el=0,er=sr;
                    while(er-el>2){
                        int m=(el+er)>>1;
                        if(cmp(hr1,hr2,i,m)) el=m;
                        else er=m-1;
                    }
                    int ep;
                    for(int j=el;j<=er;j++)if(cmp(hr1,hr2,i,j)) ep=j;
                    if(ep!=sr&&a[i+ep+1]>r[ep+1]) rpr=pr-1;
                    else rpr=pr;
                }
                int el=0,er=sl;
                while(er-el>2){
                    int m=(el+er)>>1;
                    if(cmp(hl1,hl2,i,m)) el=m;
                    else er=m-1;
                }
                int ep;
                for(int j=el;j<=er;j++)if(cmp(hl1,hl2,i,j)) ep=j;
                if(ep!=sl&&a[i+ep+1]<l[ep+1]) rpl=pl+1;
                else rpl=pl;
                if(rpl<=rpr&&rpr<=sa){
                    dp[rpl]=(dp[rpl]+dp[i])%mdn;
                    dp[rpr+1]=(dp[rpr+1]-dp[i]+mdn)%mdn;
                }
                //cerr<<i<<','<<rpl<<','<<rpr<<endl;
            }
        }else if(sl==1&&l[1]=='0'){
            dp[i+1]=(dp[i+1]+dp[i])%mdn;
            dp[i+2]=(dp[i+2]-dp[i]+mdn)%mdn;
        }
        //cerr<<i<<':'<<dp[i]<<endl;
    }
    
    return 0;
}