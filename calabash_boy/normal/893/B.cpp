#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e5+100;
bool bea[maxn];
int n;
void init(){
	for (int k=1;;k++){
		long long temp = 1LL*((1<<k)-1)*(1<<(k-1));
		if (temp>100000)break;
		bea[temp] =1;
	}
}
void solve(){
	int n;
	scanf("%d",&n);
	for (int i=n;i>=1;i--){
		if (n%i==0&&bea[i]){
			cout<<i<<endl;
			return ;
		}
	}
}
int main(){
	init();
	solve();
	return 0;
}