#include<bits/stdc++.h>
#define int long long
const int N=100005;
using namespace std;

int n,a[N],c[2],ans;
queue<int> q[2];

int calc(int k){
	ans=0;
	for(int i=1;i<=n;i++)q[a[i]&1].push(i);
	for(int i=1;i<=n;i++){
		ans+=abs(q[k].front()-i);
		q[k].pop();
		k^=1;
	}
	return ans/2;
}

int solve(){
	cin>>n;
	c[0]=c[1]=0;
	for(int i=1;i<=n;i++)cin>>a[i],c[a[i]&1]++;
	if(abs(c[0]-c[1])>1){
		return -1;
	}
	if(c[0]==c[1])return min(calc(0),calc(1));
	else if(c[0]>c[1])return calc(0);
	else return calc(1);
}

int t;

main(){
	ios::sync_with_stdio(false);
	cin>>t;
	while(t--)
		cout<<solve()<<endl;
}