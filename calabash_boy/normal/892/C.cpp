#include<bits/stdc++.h>
using namespace std;
const int maxn = 2e3+100;
int a[maxn],n;
void input(){
	scanf("%d",&n);
	for (int i=0;i<n;i++){
		scanf("%d",a+i);
	}
}
void solve(){
	int minlen = n+1;
	int cnt =0;
	for (int i=0;i<n;i++){
		if(a[i]==1)cnt++;
	}
	if (cnt){
		cout<<n-cnt<<endl;
		return ;
	}
	for (int i=0;i<n;i++){
		int temp = a[i];
		for (int j=i+1;j<n;j++){
			temp = __gcd(temp,a[j]);
			if (temp==1){
				minlen = min(minlen,j-i+1);
			}
		}
	}
	if (minlen==n+1){
		cout<<-1<<endl;
	}else{
		cout<<minlen-1+n-1<<endl;
	}
}
int main(){
	input();
	solve();
	return 0;
}