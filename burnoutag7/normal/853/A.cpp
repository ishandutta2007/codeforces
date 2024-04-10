#include<algorithm>
#include<cstdio>
#include<iostream>
#include<cstring>
#include<cmath>
#include<map>
#include<queue>
#include<set>
#include<sstream>
#include<stack>
#include<string>
#include<vector>
using namespace std;
typedef long long LL;
#define MP make_pair
LL n,k,a[300005],take[300005],ans,cost,num;
priority_queue<pair<LL,LL> > q;
int main(){
	int pv=1;
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=k+1;i<=k+n;i++){
		while(pv<=n&&pv<=i){
			q.push(MP(a[pv],pv));
			pv++;
		}
		cost=q.top().first;
		num=q.top().second;
		q.pop();
		take[num]=i;
		ans+=cost*(i-num);
	}
	cout<<ans<<endl;
	for(int i=1;i<=n;i++){
		cout<<take[i]<<' ';
	}
	return 0;
}