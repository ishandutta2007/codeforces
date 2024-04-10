/*




D P 




 l l
*/
#include<bits/stdc++.h>
using namespace std;
const int N=3500;
int n,m,s;
int a[N+1];
int mx[N+1];
int q[N],head,tail;
void mian(){
	cin>>n>>m>>s;
	for(int i=1;i<=n;i++)cin>>a[i];
	if(s>=m-1){cout<<max(*max_element(a+1,a+m+1),*max_element(a+n-m+1,a+n+1))<<"\n";return;}
	for(int i=1;i<=m;i++)mx[i]=max(a[i],a[i+n-m]);
	head=tail=0;
	int ans=0;
	for(int i=1;i<m-s;i++){
		while(head<tail&&mx[q[tail-1]]>=mx[i])tail--;
		q[tail++]=i;
	}
	for(int i=m-s;i<=m;i++){
		while(head<tail&&q[head]<i-(m-s)+1)head++;
		while(head<tail&&mx[q[tail-1]]>=mx[i])tail--;
		q[tail++]=i;
		ans=max(ans,mx[q[head]]);
	}
	cout<<ans<<"\n";
}
int main(){
	int testnum;
	cin>>testnum;
	while(testnum--)mian();
	return 0;
}