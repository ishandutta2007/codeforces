#include<bits/stdc++.h>
using namespace std;
int T,n;
void solve(){
	priority_queue<int>pq;
	cin>>n;
	for(int i=0,x;i<n;scanf("%d",&x),pq.push(x),i++);
	int cur=0,now=-1;
	while(1){
		if(pq.empty()){
			if(cur>0)puts("T");
			else puts("HL");
			return;
		}
		int x=pq.top();pq.pop();
		if(now>0)pq.push(now);
		now=x-1;
		cur^=1;
	}
}
int main(){
	cin>>T;
	while(T--)solve();
}