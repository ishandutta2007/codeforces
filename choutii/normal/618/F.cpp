#include<bits/stdc++.h>
#define FO(x) {freopen(#x".in","r",stdin);\
				freopen(#x".out","w",stdout);}
using namespace std;
typedef long long ll;
template<typename T>inline bool cmin(T &a,const T &b){ return a>b?a=b,1:0;}
template<typename T>inline bool cmax(T &a,const T &b){ return a<b?a=b,1:0;}
#define N 1001234
#define fir first
#define sec second 	
int n,ed,a[N],b[N];ll pA[N],pB[N];pair<int,int>dif[N];
int main(){
	int i,j,k;
	scanf("%d",&n);	
	for(i=1;i<=n;i++)scanf("%d",a+i),pA[i]=pA[i-1]+a[i];
	for(i=1;i<=n;i++)scanf("%d",b+i),pB[i]=pB[i-1]+b[i];
	if(pA[n]<pB[n])for(i=ed=1;i<=n;i++)swap(pA[i],pB[i]);
	for(i=0,j=0;i<=n;i++){
		while(j+1<=n&&pB[j+1]<=pA[i])++j;
		if(dif[pA[i]-pB[j]]!=make_pair(0,0)){
			pair<int,int>o=dif[pA[i]-pB[j]];
			if(ed){ 
				printf("%d\n",j-o.sec+1);
				for(k=o.sec;k<=j;k++)printf("%d ",k);
				printf("\n%d\n",i-o.fir+1);
				for(k=o.fir;k<=i;k++)printf("%d ",k);
			}else{
				printf("%d\n",i-o.fir+1);
				for(k=o.fir;k<=i;k++)printf("%d ",k);
				printf("\n%d\n",j-o.sec+1);
				for(k=o.sec;k<=j;k++)printf("%d ",k);
			}
			return 0;
		}
		dif[pA[i]-pB[j]]=make_pair(i+1,j+1);
	}
	cout<<ed;
	return 0;
}