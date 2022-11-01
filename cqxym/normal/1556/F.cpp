#include<iostream>
using namespace std;
#define R register int
#define L long long
#define P 1000000007
inline int Add(int x,const int y){
	x+=y;
	return x<P?x:x-P;
}
inline int GetInv(int x){
	int res=1,y=P-2;
	while(y!=0){
		if((y&1)==1){
			res=(L)res*x%P;
		}
		y>>=1;
		x=(L)x*x%P;
	}
	return res;
}
int a[14],p[14][14],f[16384];
int main(){
	int n,ans=0;
	cin>>n;
	for(R i=0;i!=n;i++){
		cin>>a[i];
	}
	for(R i=1;i!=n;i++){
		for(R j=0;j!=i;j++){
			int t=GetInv(a[i]+a[j]);
			p[i][j]=(L)t*a[i]%P;
			p[j][i]=Add(1,P-p[i][j]);
		}
	}
	for(R i=1;i!=1<<n;i++){
		for(R j=i-1&i;j!=0;j=j-1&i){
			int pie=1;
			for(R k=0;k!=n;k++){
				if((j>>k&1)==1){
					for(R l=0;l!=n;l++){
						if((i>>l&1)==1&&(j>>l&1)==0){
							pie=(L)pie*p[k][l]%P;
						}
					}
				}
			}
			f[i]=((1ll-f[j]+P)*pie+f[i])%P;
		}
		int pie=1,ct=0;
		for(R j=0;j!=n;j++){
			if((i>>j&1)==1){
				ct++;
				for(R k=0;k!=n;k++){
					if((i>>k&1)==0){
						pie=(L)pie*p[j][k]%P;
					}
				}
			}
		}
		ans=((1ll-f[i]+P)*pie%P*ct+ans)%P;
	}
	cout<<ans;
	return 0;
}