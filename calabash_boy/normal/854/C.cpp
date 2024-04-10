#include<bits/stdc++.h>
using namespace std;
const int MAX = 3e5+100;
int n,k;
bool used[MAX];
int ans[MAX];
struct Flight{
	int cost,index;
	bool operator < (const Flight a)const{
		return a.cost<cost;
	}
	Flight(int cost_=0,int index_=0):cost(cost_),index(index_){}
};
priority_queue<Flight> pq;
inline void input(){
	scanf("%d%d",&n,&k);
	for (int i=1;i<=n;i++){
		int c;
		scanf("%d",&c);
		pq.push(Flight(c,i));
	} 
}
void solve(){
	memset(used,0,sizeof used);
	long long res =0;
	for(int i=n+k;i>k;i--){
		if (i<=n&&!used[i]){
			used[i] = true;
			ans[i] =i;

		}else{
			while (used[pq.top().index])pq.pop();
			used[pq.top().index] = true;
			ans[pq.top().index] = i;
			res +=1LL*(i-pq.top().index)*pq.top().cost;
			pq.pop();
		} 
	}
	printf("%I64d\n",res);
	for (int i=1;i<=n;i++){
		printf("%d ",ans[i]);
	} 
} 
int main(){
	input();
	solve();
	return 0;
}