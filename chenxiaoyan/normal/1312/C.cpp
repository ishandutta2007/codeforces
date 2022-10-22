/*




D P 




 l l
*/
#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=30;
int n,m;
int a[N+1];
int cnt[100];
void mian(){
	cin>>n>>m;
	memset(cnt,0,sizeof(cnt));
	for(int i=1;i<=n;i++)scanf("%lld",a+i);
	for(int i=1;i<=n;i++){
		int now=0;
		while(a[i]){
			if(a[i]%m>1){puts("NO");return;}
			if(a[i]%m==1)cnt[now]++;
			now++;
			a[i]/=m;
		}
	}
	for(int i=0;i<100;i++)if(cnt[i]>1){puts("NO");return;}
	puts("YES");
}
signed main(){
	int testnum;
	cin>>testnum;
	while(testnum--)mian();
	return 0;
}