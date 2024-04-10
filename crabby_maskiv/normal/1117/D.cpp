#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=100005;
const ll mod=1000000007;
ll n,m;
struct mat{
    int n,m;
    ll x[105][105];
};
mat mul(const mat &a,const mat &b){
    mat ret;ret.n=a.n;ret.m=b.m;
    memset(ret.x,0,sizeof(ret.x));
    int i,j,k;
    for(i=1;i<=ret.n;i++)
        for(j=1;j<=ret.m;j++)
            for(k=1;k<=a.m;k++){
                ret.x[i][j]+=a.x[i][k]*b.x[k][j];
                ret.x[i][j]%=mod;
            }
    return ret;
}
mat po(const mat &a,ll k){
    if(k==1) return a;
    mat s=po(a,k>>1);
    s=mul(s,s);
    if(k&1) return mul(s,a);
    else return s;
}
mat base,a;
int main(){
    int i,j;
    cin>>n>>m;
    if(n<m){
    	cout<<1;
    	return 0;
	}
    base.n=base.m=m;
    a.n=m;a.m=1;
    base.x[1][1]=base.x[1][m]=1;
    for(i=2;i<=m;i++) base.x[i][i-1]=1;
    for(i=1;i<=m;i++) a.x[i][1]=1;
    //for(i=1;i<=n-m+1;i++) 
		//a=mul(a,base);
    cout<<mul(po(base,n-m+1),a).x[1][1];
    return 0;
}