#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <queue>
#include <cstring>
#include <cmath>
using namespace std;
struct node{
	int a,b,id;
}c[1000005],d[1000005];
bool cmp1(node x,node y){
	if (x.b!=y.b)return x.b>y.b;
	return x.a<y.a;
}
bool cmp2(node x,node y){
	if (x.b!=y.b)return x.b<y.b;
	return x.a<y.a;
}
int n,l1,l2;
int main(){
	cin>>n;
	for (int i=1;i<=n;i++){
		int x,y;
		scanf("%d%d",&x,&y);
		if (x<y)++l1,c[l1].a=x,c[l1].b=y,c[l1].id=i;
		else ++l2,d[l2].a=x,d[l2].b=y,d[l2].id=i;
	}
	if (l1<l2){
		cout<<l2<<endl;
		sort(d+1,d+1+l2,cmp2);
		for (int i=1;i<=l2;i++)printf("%d ",d[i].id);
		puts("");
	}
	else{
		cout<<l1<<endl;
		sort(c+1,c+1+l1,cmp1);
		for (int i=1;i<=l1;i++)printf("%d ",c[i].id);
		puts("");
	}
	return 0;
}