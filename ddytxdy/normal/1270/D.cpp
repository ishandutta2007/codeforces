	#include<bits/stdc++.h>
	#define LL long long
	using namespace std;
	const int N=2e5+50;
	int n,k;LL x,y,d1,d2,c1,c2;
	int query(int x){
		printf("? ");
		for(int i=1;i<=k+1;i++)
			if(i!=x)printf("%d ",i);
		puts("");cout.flush();
		int y;scanf("%d%d",&x,&y);return y;
	}
	int main(){
		scanf("%d%d",&n,&k);d1=d2=-1;
		for(int i=1;i<=k+1;i++){
			int dd=query(i);
			if(dd==d1)c1++;
			else if(dd==d2)c2++;
			else if(d1==-1)d1=dd,c1=1;
			else d2=dd,c2=1;
		}
		if(d1>d2)swap(d1,d2),swap(c1,c2);
		printf("! %d\n",c2);cout.flush();
		return 0;
	}