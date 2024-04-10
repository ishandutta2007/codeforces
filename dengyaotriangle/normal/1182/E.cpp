#include<bits/stdc++.h>
//dengyaotriangle!
using namespace std;
    
const int maxn=100005;
const long long mdn=1000000007;
const long long mdphi=mdn-1;
    
struct mat{
    long long v[5][5];
};
    
const long long pg1[5][5]={{0},{0},{1}},pg2[5][5]={{0},{1},{0}},pg3[5][5]={{1},{0},{0}},pm1[5][5]={{1,1,1},{1,0,0},{0,1,0}};
const long long pm2[5][5]={{1,1,1,1,0},{1,0,0,0,0},{0,1,0,0,0},{0,0,0,1,2},{0,0,0,0,1}};
    
mat mul(mat a,mat b,int x,int y,int z){
    mat c;
    memset(c.v,0,sizeof(c.v));
    for(int i=0;i<z;i++){
        for(int j=0;j<x;j++){
            for(int k=0;k<y;k++){
                c.v[j][k]+=a.v[j][i]*b.v[i][k];
                c.v[j][k]%=mdphi;
            }
        }
    }
    return c;
}
    
mat ksm(mat x,long long ex,int d){
    if(ex==1) return x;
    mat ans=ksm(x,ex>>1,d);ans=mul(ans,ans,d,d,d);
    if(ex&1) ans=mul(ans,x,d,d,d);
    return ans;
}
    
long long ksm(long long x,long long ex){
    if(ex==0) return 1;
    if(ex==1) return x;
    long long ans=ksm(x,ex>>1);ans=(ans*ans)%mdn;
    if(ex&1) ans=(ans*x)%mdn;
    return ans;
}
int main(){
    ios::sync_with_stdio(0);
    long long n,f1,f2,f3,c;
    cin>>n>>f1>>f2>>f3>>c;
    mat m1,m2;
    mat g1,g2,g3;
    memcpy(g1.v,pg1,sizeof(pg1));
    memcpy(g2.v,pg2,sizeof(pg2));
    memcpy(g3.v,pg3,sizeof(pg3));
    memcpy(m1.v,pm1,sizeof(pm1));
    memcpy(m2.v,pm2,sizeof(pm2));
    m2=ksm(m2,n-3,5);
    m1=ksm(m1,n-3,3);
    long long a1=(m1.v[0][0])%mdphi,a2=(m1.v[0][1])%mdphi,a3=(m1.v[0][2])%mdphi;
    long long res=((ksm(f3,a1)*ksm(f2,a2))%mdn);
    res=(res*(ksm(f1,a3)))%mdn;
    long long r3=(m2.v[0][3]*2+m2.v[0][4])%mdphi;
    res=(res*ksm(c,r3))%mdn;
    cout<<res;
    return 0;
}