#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll c=0;
int ans=0;
int n;
priority_queue<int,vector<int>,greater<int> >pq;
int main(){
	cin>>n;
	while(n--){
		int x;cin>>x;
		pq.push(x),c+=x,ans++;
		if(c<0)c-=pq.top(),pq.pop(),ans--;
	}
	cout<<ans;
}