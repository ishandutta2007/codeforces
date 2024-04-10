/*




D P 




 l l
*/
#include<bits/stdc++.h>
using namespace std;
const int N=100000,LOG_N=20;
int n;
int a[N+1];
int main(){
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i];
	int now=0;
	bool mk=true;
	for(int i=1;i<=n;i++){if(2*a[i]<now)mk=false;now=max(now,a[i]);}
	for(int i=1;i<=n;i++){if(2*a[i]<now)mk=false;now=max(now,a[i]);}
	if(mk){
		for(int i=1;i<=n;i++)cout<<"-1 ";
		return 0;
	}
	now=0;
	int ans=0;
	multiset<int> s;
	s.insert(0);
	for(int i=1;i<=n;i++){
		if(i>1)s.erase(s.find(a[i-1])),ans--;
		while(2*a[now%n+1]>=*--s.end())ans++,now=now%n+1,s.insert(a[now]);
		cout<<ans<<" ";
	}
	return 0;
}