/*




D P 




 l l
*/
#include<bits/stdc++.h>
using namespace std;
const int N=100000;
int n;
int a[N+1],b[N+1];
int main(){
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<=n;i++){
		int x;
		cin>>x;
		b[x]=i;
	}
	int now=0,ans=0;
	for(int i=1;i<=n;i++){
		if(b[a[i]]<now)/*cout<<a[i]<<"!\n",*/ans++;
		now=max(now,b[a[i]]);
	}
	cout<<ans;
	return 0;
}