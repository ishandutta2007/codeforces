/*





D P 




 l l
*/
#include<bits/stdc++.h>
using namespace std;
void mian(){
	int n,k;
	cin>>n>>k;
	vector<int> a(n+1);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	a[0]=a[1];
	int cnt=0;
	for(int i=1;i<=n;i++)cnt+=a[i-1]!=a[i];
	if(cnt==0)cout<<(a[0]==0?0:1)<<"\n";
	else{
		if(k==1)puts("-1");
		else cout<<(cnt+k-2)/(k-1)<<"\n";
	}
}
int main(){
	int testnum;
	cin>>testnum;
	while(testnum--)mian();
	return 0;
}