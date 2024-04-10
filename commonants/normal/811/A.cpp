#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<algorithm>

using namespace std;
typedef long long LL;

LL So(LL x){
	if(x%2==0)--x;
	return (x+1)*(x+1)>>2;
}
LL Se(LL x){
	if(x%2==1)--x;
	return (x+2)*x>>2;
}
int main(){
	int a,b;scanf("%d%d",&a,&b);
	int l=1,r=100000;
	while(l<r){
		int mid=(l+r)>>1;
		if(So(mid)>a||Se(mid)>b)r=mid;else l=mid+1;
	}
	puts((l&1)?"Vladik":"Valera");
	return 0;
}