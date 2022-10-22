#include<cstdio>
int n,a,m;
int main(){
	int T;scanf("%d",&T);for(;T--;){
	scanf("%d%d",&n,&m);
	for(;n--;)scanf("%d",&a),m-=a;
	puts(m?"NO":"YES");
	}return 0;
}