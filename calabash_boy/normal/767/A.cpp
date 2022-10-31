#include<stdio.h>
#include<stdlib.h>
#include<algorithm>
#define max(a,b) (a)>(b)?a:b
using namespace std;
struct pairr{
	int length,loc;
	void read(int i){
		scanf("%d",&length);
		loc=i;
	}
}data[100005];
bool cmp(pairr a1,pairr a2){
	return a1.length>a2.length;
}
int main(){
	int n;
	scanf("%d",&n);
	for (int i=1;i<=n;i++){
//		scanf("%d",&length[i]);
//		loc[i]=i;
		data[i].read(i);
	}
	sort(data+1,data+n+1,cmp);
	int temp=1,now=1;
//	bool endofday=false;
//	for (int i=1;i<=n;i++){
//		printf("%d %d\n",data[i].length,data[i].loc);
//	}
	for(temp=1;temp<=n;temp++){
		for (int i=1;i<=data[temp].loc-now;i++){
			printf("\n");
		}
		//if (temp!=1&&data[temp].loc-now>=1) printf("\n");
		printf("%d ",data[temp].length);
		now=max(now,data[temp].loc);
	}
	return 0;
}