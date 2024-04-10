#include<bits/stdc++.h>
using namespace std;
int s[2500002];
struct node{
	int val,id;
}a[200005],b[200005];
bool cmp(node x,node y){
	return x.val<y.val;
}
int t[5000001][2];
int main(){
	int n,i,m=0,j,flg=0,k;
	scanf("%d",&n);
	for(i=1;i<=n;++i){
		scanf("%d",&a[i].val);
		a[i].id=i;
	}
	sort(a+1,a+1+n,cmp);
	for(i=1;i<=n;++i){
		++s[a[i].val];
		if(s[a[i].val]==1)b[++m]=a[i];
		if(s[a[i].val]==2){
			if(!flg)flg=i;
			else{
				puts("YES");
				printf("%d %d %d %d\n",a[flg].id,a[i].id,a[i-1].id,a[flg-1].id);
				return 0;
			}
		}
		if(s[a[i].val]>=4){
			puts("YES");
			printf("%d %d %d %d\n",a[i].id,a[i-1].id,a[i-2].id,a[i-3].id);
			return 0;
		}
	}
	for(i=1;i<=m;++i){
		for(j=i+1;j<=m;++j){
			int ss=b[i].val+b[j].val;
			if(t[ss][0]){
				puts("YES");
				printf("%d %d %d %d\n",t[ss][0],t[ss][1],b[i].id,b[j].id);
				return 0;
			}
			t[ss][0]=b[i].id;
			t[ss][1]=b[j].id;
		}
	}
	for(i=1;i<=n;++i){
		if(s[a[i].val]>=2){
			for(j=1;j<i;++j){
				for(k=i+2;k<=n;++k){
					if(a[j].val+a[k].val==2*a[i].val){
						puts("YES");
						printf("%d %d %d %d\n",a[j].id,a[k].id,a[i].id,a[i+1].id);
						return 0;
					}
				}
			}
			break;
		}
	}
	puts("NO");
	return 0;
}