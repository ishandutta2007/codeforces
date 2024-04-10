#include<bits/stdc++.h>
#define rep(i,a,b) for(ll i=(a);i<=(b);i++)
#define per(i,a,b) for(ll i=(a);i>=(b);i--)
#define next Cry_For_theMoon
typedef long long ll;
using namespace std;
const int MAXN=2e5+10;
int n;
int main(){
	scanf("%d",&n);
	int l=1,r=n;
	printf("? %d %d\n",1,n);fflush(stdout);
	int bs=0;scanf("%d",&bs);
	int tmp=0,flag=1;
	if(bs!=1){
		printf("? %d %d\n",1,bs);fflush(stdout);
		scanf("%d",&tmp);
		if(tmp==bs)r=bs-1,l=1,flag=0;
		else r=(n-bs),l=1;
	}else{
		l=1,r=n-1;
	}
	if(flag){
		int ans=0;
		while(l<=r){
			int mid=(l+r)>>1;
			int now2=0;
			printf("? %d %d\n",bs,bs+mid);fflush(stdout);
			scanf("%d",&now2);
			if(now2==bs){
				ans=bs+mid;
				r=mid-1;
			}else{
				l=mid+1;
			}
		}
		printf("! %d\n",ans);fflush(stdout);
	}else{
		int ans=0;
		while(l<=r){
			int mid=(l+r)>>1;
			int now2=0;
			printf("? %d %d\n",bs-mid,bs);fflush(stdout);scanf("%d",&now2);
			if(now2==bs){
				ans=bs-mid;
				r=mid-1;
			}else{
				l=mid+1;
			}
		}
		printf("! %d\n",ans);fflush(stdout);
	}
	return 0;
}