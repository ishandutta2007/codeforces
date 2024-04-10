#include<cstdio>
#include<cmath>
using namespace std;
int T,n,f[110][110][2],c[2];
int main(){
	for(int i=0,res;i<=100;++i) for(int j=0;j<=100;++j)
		if(i+j<2) f[i][j][j]=1;
		else{
			if(i){
				res=1;
				if(j) res&=f[i-1][j-1][0];
				if(i>1) res&=f[i-2][j][0];
				f[i][j][0]|=res;
				res=1;
				if(j) res&=f[i-1][j-1][1];
				if(i>1) res&=f[i-2][j][1];
				f[i][j][1]|=res;
			}
			if(j){
				res=1;
				if(i) res&=f[i-1][j-1][1];
				if(j>1) res&=f[i][j-2][1];
				f[i][j][0]|=res;
				res=1;
				if(i) res&=f[i-1][j-1][0];
				if(j>1) res&=f[i][j-2][0];
				f[i][j][1]|=res;
			}
	}
	for(scanf("%d",&T);T--;printf(f[c[0]][c[1]][0]?"Alice\n":"Bob\n")){
		scanf("%d",&n);c[0]=c[1]=0;
		for(int a;n--;) scanf("%d",&a),++c[abs(a)&1];
	}
	return 0;
}