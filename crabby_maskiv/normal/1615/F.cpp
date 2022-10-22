#include<bits/stdc++.h>
#define fr first
#define sc second
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int N=4e3+5;
const int mod=1e9+7;
int n,m;
int f0[N],f1[N],g0[N],g1[N];
char a[N],b[N];
inline int f(int x){
	return (x>0)?x:-x;
}
int main(){
	int i,j;
	int _;cin>>_;
	while(_--){
		cin>>n;
		cin>>(a+1);
		cin>>(b+1);
		for(i=1;i<=n;i+=2){
			if(a[i]!='?') a[i]^=1;
			if(b[i]!='?') b[i]^=1;
		}
		memset(f0,0,sizeof(f0));
		memset(g0,0,sizeof(g0));
		f0[n]=1;
		for(i=1;i<=n;i++){
			memset(f1,0,sizeof(f1));
			memset(g1,0,sizeof(g1));
			for(j=0;j<=n*2;j++){
				if(a[i]!='1'&&b[i]!='1'){
					g1[j]=(g1[j]+1ll*f(n-j)*f0[j]+g0[j])%mod;
					f1[j]=(f1[j]+f0[j])%mod;
				}
				if(a[i]!='0'&&b[i]!='0'){
					g1[j]=(g1[j]+1ll*f(n-j)*f0[j]+g0[j])%mod;
					f1[j]=(f1[j]+f0[j])%mod;
				}
				if(a[i]!='0'&&b[i]!='1'&&j<2*n){
					g1[j+1]=(g1[j+1]+1ll*f(n-j)*f0[j]+g0[j])%mod;
					f1[j+1]=(f1[j+1]+f0[j])%mod;
				}
				if(a[i]!='1'&&b[i]!='0'&&j){
					g1[j-1]=(g1[j-1]+1ll*f(n-j)*f0[j]+g0[j])%mod;
					f1[j-1]=(f1[j-1]+f0[j])%mod;
				}
			}
			memcpy(f0,f1,sizeof(f1));
			memcpy(g0,g1,sizeof(g1));
		}
		cout<<g0[n]<<endl;
	}
	return 0;
}