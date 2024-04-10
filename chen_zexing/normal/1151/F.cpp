#include <stdio.h>
#include<iostream>
#include <string>
#include <string.h>
#include <vector>
#include <cmath>
#include <algorithm>
#include <queue>
#include <climits>
#include <set>
#include <unordered_map>
#include <map>
#include <stack>
using namespace std;
const int maxn=101,mod=1000000007;
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define MEM(x,v) memset(x,v,sizeof(x))
inline int read(){
    char ch=getchar();int x=0,f=0;
    while(ch<'0' || ch>'9') f|=ch=='-',ch=getchar();
    while(ch>='0' && ch<='9') x=x*10+ch-'0',ch=getchar();
    return f?-x:x;
}
int n,k,a[maxn],c,cnt;
inline int add(int a,int b){return a+b<mod?a+b:a+b-mod;}
inline int sub(int a,int b){return a<b?a-b+mod:a-b;}
inline int mul(int a,int b){return 1ll*a*b%mod;}
inline int qpow(int a,int b){
    int ans=1;
    for(;b;b>>=1,a=mul(a,a)) if(b&1) ans=mul(ans,a);
    return ans;
}
struct matrix{
    int a[maxn][maxn];
    matrix(){MEM(a,0);}
    matrix operator*(const matrix &t)const{
        matrix ans;
        FOR(i,0,c) FOR(k,0,c) FOR(j,0,c) ans.a[i][j]=add(ans.a[i][j],mul(a[i][k],t.a[k][j]));
        return ans;
    }
}beg,fac,ans;
matrix qpow(matrix a,int b){
    matrix ans;
    FOR(i,0,c) ans.a[i][i]=1;
    for(;b;b>>=1,a=a*a) if(b&1) ans=ans*a;
    return ans;
}
int main(){
    n=read();k=read();
    FOR(i,1,n) a[i]=read(),c+=!a[i];
    FOR(i,1,c) cnt+=!a[i];
    beg.a[cnt][0]=1;
    FOR(i,0,c){
        fac.a[i][i]=(1ll*c*(c-1)/2+1ll*(n-c)*(n-c-1)/2+1ll*i*(c-i))%mod;
        if(i>=2*c-n) fac.a[i][i]=add(fac.a[i][i],mul(c-i,n-2*c+i));
        if(i) fac.a[i][i-1]=mul(c-i+1,c-i+1);
        if(i!=c && i+1>=2*c-n) fac.a[i][i+1]=mul(i+1,n-2*c+i+1);
    }
    ans=qpow(fac,k)*beg;
    int s=0;
    FOR(i,0,c) s=add(s,ans.a[i][0]);
    s=mul(qpow(s,mod-2),ans.a[c][0]);
    printf("%d\n",s);
}