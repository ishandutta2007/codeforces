/*









 l l
*/
#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=1000000;
int n;
int a[N+1];
int lft[N+1],rit[N+1];
int stk[N],top;
int ans;
signed main(){
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i];
	top=0;
	for(int i=1;i<=n;i++){
		int fd=-1;
		for(int j=30;~j;j--)if(fd+(1<<j)<top&&a[stk[fd+(1<<j)]]>=a[i])fd+=1<<j;
		lft[i]=~fd?stk[fd]+1:1;
		while(top&&a[stk[top-1]]<=a[i])top--;
		stk[top++]=i;
	}
	top=0;
	for(int i=n;i;i--){
		int fd=-1;
		for(int j=30;~j;j--)if(fd+(1<<j)<top&&a[stk[fd+(1<<j)]]>a[i])fd+=1<<j;
		rit[i]=~fd?stk[fd]-1:n;
		while(top&&a[stk[top-1]]<=a[i])top--;
		stk[top++]=i;
	}
//	for(int i=1;i<=n;i++)printf("[%lld,%lld]\n",lft[i],rit[i]);puts("");
	for(int i=1;i<=n;i++)ans+=a[i]*(i-lft[i]+1)*(rit[i]-i+1);
	top=0;
	for(int i=1;i<=n;i++){
		int fd=-1;
		for(int j=30;~j;j--)if(fd+(1<<j)<top&&a[stk[fd+(1<<j)]]<=a[i])fd+=1<<j;
		lft[i]=~fd?stk[fd]+1:1;
		while(top&&a[stk[top-1]]>=a[i])top--;
		stk[top++]=i;
	}
	top=0;
	for(int i=n;i;i--){
		int fd=-1;
		for(int j=30;~j;j--)if(fd+(1<<j)<top&&a[stk[fd+(1<<j)]]<a[i])fd+=1<<j;
		rit[i]=~fd?stk[fd]-1:n;
		while(top&&a[stk[top-1]]>=a[i])top--;
		stk[top++]=i;
	}
//	for(int i=1;i<=n;i++)printf("[%lld,%lld]\n",lft[i],rit[i]);
	for(int i=1;i<=n;i++)ans-=a[i]*(i-lft[i]+1)*(rit[i]-i+1);
	cout<<ans<<"\n";
	return 0;
}
/*1
3
1 4 1
*/