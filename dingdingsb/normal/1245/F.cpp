#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=35;
int T,l,r;
ll f[N+1][2][2];
long long calc(ll a,ll b){
	if(a<0||b<0)return 0;
	memset(f,0,sizeof f);
	f[N][1][1]=1;
	for(int i=N-1;i>=0;i--)
		for(int j=0;j<2;j++)
			for(int k=0;k<2;k++){
				bool nj=j&&!((a>>i)&1),nk=k&&!((b>>i)&1);
				f[i][nj][nk]+=f[i+1][j][k];
				if(((a>>i)&1)||!j)f[i][j][nk]+=f[i+1][j][k];
				if(((b>>i)&1)||!k)f[i][nj][k]+=f[i+1][j][k];
			}
	return f[0][0][0]+f[0][1][0]+f[0][0][1]+f[0][1][1];
} 
signed main(){
	cin>>T;
	while(T--){
		cin>>l>>r;
		cout<<calc(r,r)-calc(l-1,r)*2ll+calc(l-1,l-1)<<endl;
	}
	return 0;
}