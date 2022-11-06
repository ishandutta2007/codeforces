#include<bits/stdc++.h>
#define ll long long
#define N 100005
using namespace std;
struct node{
	int id,x;
}a[N];
bool cmp(const node&A,const node&B){
	return A.x!=B.x?A.x<B.x:A.id<B.id;
}
int main(){
	int T,n,i,j,F,s=0;
	scanf("%d",&T);
	bool flg;
	while(T--){
		scanf("%d",&n);
		flg=1;
		for(i=1;i<=n;++i){
			scanf("%d",&a[i].x);
			a[i].id=i;
		}
		sort(a+1,a+1+n,cmp);
		for(i=1;i<=n;i=j){
			s=0;
			for(j=i;a[j].x==a[i].x&&j<=n;++j){
				if(a[j].id&1)++s;
				if(j&1)--s;
			}
			if(s){
				flg=0;
				break;
			}
		}
		if(flg)puts("YES");
		else puts("NO");
	}
	return 0;
}