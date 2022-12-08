#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+10;
struct My{
	int x,id;
}a[maxn];
int n,Ans=maxn;
inline bool comp(const My &x,const My &y){
	return x.x==y.x?x.id<y.id:x.x<y.x;
}
int main(){
	scanf("%d",&n);
	for (int i=1;i<=n;++i) scanf("%d",&a[i].x),a[i].id=i;
	sort(a+1,a+1+n,comp);
	for (int i=2;i<=n;++i)
	if (a[i].x==a[i-1].x){
		Ans=min(Ans,a[i].id-a[i-1].id);
	} else break;
	printf("%d",Ans);
	return 0;
}