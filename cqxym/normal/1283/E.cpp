#include<stdio.h>
#include<algorithm>
#define R register int
int pos[200000];
int main(){
	int n,m,l=0,ans=0;
	scanf("%d",&n);
	for(R i=0;i!=n;i++){
		scanf("%d",pos+i);
	}
	std::sort(pos,pos+n);
	for(R i=0;i!=n;i++){
		if(pos[i]>l){
			ans++;
			l=pos[i]+2;
		}
	}
	pos[0]--;
	for(R i=1;i!=n;i++){
		if(pos[i-1]<pos[i]-1){
			pos[i]--;
		}else if(pos[i-1]>=pos[i]){
			pos[i]++;
		}
	}
	printf("%d %d",ans,std::unique(pos,pos+n)-pos);
	return 0;
}