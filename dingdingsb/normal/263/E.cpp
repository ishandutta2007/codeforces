#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e3+10;
int n,m,k;int val[N][N];
template<class T>
void read(T&x){
	x=0;char c=getchar();
	for(;!isdigit(c);c=getchar());
	for(;isdigit(c);c=getchar())x=x*10+c-'0';
}
int sl[N][N],sr[N][N],su[N][N];
int l[N][N],r[N][N];
signed main(){
	read(n);read(m);read(k);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++){
			read(val[i][j]);
			sl[i][j]=sl[i-1][j-1]+val[i][j];
			sr[i][j]=sr[i-1][j+1]+val[i][j]; 
			su[i][j]=su[i-1][j]+val[i][j];
		}
	for(int a=k;a<=n-k+1;a++)
		for(int b=k;b<=m-k+1;b++){
			if(b==k){
				for(int i=0;i<k;i++){
					// b-i  [a-k+1+i,a+k-1-i]
					l[a][b]+=su[a+k-1-i][b-i]-su[a-k+i][b-i]; 
				}
			}else{
				l[a][b]=l[a][b-1]+su[a+k-1][b]-su[a-k][b]
				-sr[a][b-k]+sr[a-k][b]
				-sl[a+k-1][b-1]+sl[a][b-k];
			}
		}
	
	for(int a=k;a<=n-k+1;a++)
		for(int b=m-k+1;b>=k;b--){
			if(b==m-k+1){
				for(int i=0;i<k;i++){
					r[a][b]+=su[a+k-1-i][b+i]-su[a-k+i][b+i];
				}
			}else{
				r[a][b]=r[a][b+1]+su[a+k-1][b]-su[a-k][b]
				-sl[a][b+k]+sl[a-k][b]
				-sr[a+k-1][b+1]+sr[a][b+k];
			}
		}
	auto ans=make_tuple(0ll,0ll,0ll);
	for(int a=k;a<=n-k+1;a++){
		int sum=0;
		for(int b=k;b<=m-k+1;b++){
			if(b==k){
				sum=k*val[a][b];
				for(int i=1;i<k;i++){
					// k-i
					sum+=(k-i)*(sl[a+i][b]-sl[a-1][b-i-1]);
					sum+=(k-i)*(sr[a+i-1][b+1]-sr[a-1][b+i+1]);
					sum+=(k-i)*(sr[a-1][b-i+1]-sr[a-i-1][b+1]);
					sum+=(k-i)*(sl[a-1][b+i-1]-sl[a-i][b]);
				}
			}else{
				sum-=l[a][b-1];
				sum+=r[a][b];
			}
			ans=max(ans,make_tuple(sum,a,b));
		}
	}
	printf("%lld %lld",get<1>(ans),get<2>(ans));
}