#include<bits/stdc++.h>
using namespace std;
const int maxn=2e5+100;
multiset <int >q;
long long sum,sum2,cnt;
int a[maxn];
/*
void dfs(){

}
*/
int main(){
	int n,m; int masxn=0;
	scanf("%d%d",&n,&m);
	for (int i=1;i<=n;++i) scanf("%d",&a[i]);
	for (int i=1;i<=n;++i){
		sum2=sum; cnt=0;
		if (!q.empty()){
			
			for (set<int>::iterator cmzz =--q.end();;cmzz--){
				if (m-a[i]<sum2){
					sum2-=*cmzz;++cnt;
				}
				if (cmzz==q.begin()) break;
			}
		}
		int mas2xn=0;
		printf("%d ",i-1-q.size()+cnt);
		if (sum+a[i]<=m){
			sum+=a[i]; 
			q.insert(a[i]); 
			continue;
		}
		if (a[i]<*(--q.end())){
			q.insert(a[i]);
			sum-=*(--q.end())-a[i];
			q.erase(--q.end());
		}		
	}
}