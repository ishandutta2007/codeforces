/*




D P 




 l l
*/
#pragma GCC optimize(3)
#include<bits/stdc++.h>
using namespace std;
#define int long long
#define pb push_back
#define mp make_pair
const int N=7000;
int n;
int a[N+1],b[N+1];
int ideg[N+1];
bool del[N+1];
signed main(){
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<=n;i++)cin>>b[i];
	for(int i=1;i<=n;i++)for(int j=1;j<=n;j++)if(i!=j&&(a[i]&a[j])==a[i])ideg[i]++;
	queue<int> q;
	for(int i=1;i<=n;i++)if(!ideg[i])q.push(i);
	while(q.size()){
		int x=q.front();
		q.pop();
		del[x]=true;
		for(int i=1;i<=n;i++)if(i!=x&&(a[i]&a[x])==a[i]){
			ideg[i]--;
			if(!ideg[i])q.push(i);
		}
	}
	int ans=0;
	for(int i=1;i<=n;i++)if(!del[i])ans+=b[i];
	cout<<ans;
	return 0;
}