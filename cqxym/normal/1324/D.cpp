#include<stdio.h>
#include<set>
#include<map>
#include<algorithm>
using namespace std;
#define R register int
int a[200001],b[200001],c[400001],tot;
set<int>Q;
map<int,int>P;
inline void Add(int x){
	for(R i=x;i<=tot;i+=i&-i){
		c[i]++;
	}
}
inline int Get(int x){
	int s=0;
	for(R i=x;i!=0;i-=i&-i){
		s+=c[i];
	}
	return s;
}
int main(){
	int n,x;
	scanf("%d",&n);
	for(R i=0;i!=n;i++){
		scanf("%d",a+i);
	}
	for(R i=0;i!=n;i++){
		scanf("%d",b+i);
		Q.insert(b[i]-a[i]);
		Q.insert(a[i]-b[i]);
	}
	for(set<int>::iterator T=Q.begin();T!=Q.end();T++){
		tot++;
		P[*T]=tot;
	}
	long long ans=0;
	for(R i=0;i!=n;i++){
		x=P[a[i]-b[i]];
		ans+=Get(x-1);
		Add(P[b[i]-a[i]]);
	}
	printf("%lld",ans);
	return 0;
}