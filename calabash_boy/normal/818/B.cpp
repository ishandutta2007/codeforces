#include<bits/stdc++.h>
using namespace std;
#define MAXN 105
bool use [MAXN];
int ans [MAXN];
int m,n;
int main(){
	int now;
	cin>>n>>m;
	cin>>now;
	for (int i=1;i<m;i++){
		int temp;
		cin>>temp;
		int a = temp - now;
		if (a<=0){
			a+=n;
		}
		if (ans[now]==0&&use[a]||ans[now]!=0&&ans[now]!=a){
			cout<<"-1"<<endl;
			return 0;
		}
		use[a]=true;
		ans[now]=a;
		now= temp;
	}
int as=1;
	for (int i=1;i<=n;i++){
if(ans[i]==0){
while(use[as])as++;
cout<<as<<" ";
as++;
}else
		cout<<ans[i]<<" ";
	}
	return 0;
}