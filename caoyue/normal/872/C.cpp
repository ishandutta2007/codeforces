#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=1;i<=n;i++)
#define rep0(i,n) for(int i=0;i<n;i++)
#define REP(i,x,y) for(int i=x;i<=y;i++)
int q;
 
int main(){
	scanf("%d",&q);
	while(q--){
		int n;
		scanf("%d",&n);
		int ans=0;
		if(n%2==1)n-=9,ans++;
		if(n<0){
			cout<<-1<<endl;
			continue;
		}
		if(n%4==2)n-=6,ans++;
		if(n<0){
			cout<<-1<<endl;
			continue;
		}
		cout<<ans+n/4<<endl;
	}
	return 0;
}