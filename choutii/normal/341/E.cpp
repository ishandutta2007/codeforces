#include<bits/stdc++.h>
#define FO(x) {freopen(#x".in","r",stdin);\
				freopen(#x".out","w",stdout);}
#define fir first
#define sec second
using namespace std;
typedef long long ll;
template<typename T>inline bool cmin(T &a,const T &b){ return a>b?a=b,1:0;}
template<typename T>inline bool cmax(T &a,const T &b){ return a<b?a=b,1:0;}
#define N 1001234
int n,m,on;
pair<int,int> op[N],a[N];
int main(){
	int i,j,k;
	scanf("%d",&n);
	for(i=1;i<=n;i++){
		scanf("%d",&a[i].fir);
		if(a[i].fir)a[++m]=make_pair(a[i].fir,i);
	}
	if(m<2)return puts("-1"),0;
	for(i=1;i<=m-2;i++){
		sort(a+i,a+i+3);
		while(a[i].fir){
			for(k=a[i+1].fir/a[i].fir;k;a[i].fir<<=1,k>>=1)
				if(k&1){
					op[on++]=make_pair(a[i+1].sec,a[i].sec);
					a[i+1].fir-=a[i].fir;
				}
				else{
					op[on++]=make_pair(a[i+2].sec,a[i].sec);
					a[i+2].fir-=a[i].fir;
				 
				}
			sort(a+i,a+i+3);
		} 
	}
	printf("%d\n",on);
	for(i=0;i<on;i++)
		printf("%d %d\n",op[i].sec,op[i].fir);
	return 0;
}