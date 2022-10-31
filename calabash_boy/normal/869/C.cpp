#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int maxn = 5050;
const int MOD = 998244353;
LL ans;
LL C[maxn][maxn];
int a,b,c;
void init(){
	C[1][0]=C[1][1]=1;
	for (int i=2;i<maxn;i++){
		C[i][0]=C[i][i]=1;
		for (int j=1;j<i;j++){
			C[i][j]=C[i-1][j]+C[i-1][j-1];
			C[i][j]%=MOD;
		}
	}
}
LL calc(int x,int y){
	if (x>y){
		swap(x,y);
	}
	LL res =1;
	LL basx=1;
	LL basy=1;
	for (int i=1;i<=x;i++){
		basx = C[x][i];
		basy*=(y-i+1);
		basx%=MOD;
		basy%=MOD;
		res+=basx*basy%MOD;
		res%=MOD;
	}
	return res;
}
int main(){
	init();
	cin>>a>>b>>c;
	ans = calc(a,c)*calc(a,b)%MOD*calc(b,c)%MOD;
	cout<<ans<<endl;
	return 0;
}