#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e6+100;
int prime[maxn],cnt;
bool used[maxn];
bool isprime[maxn];
void init(){
	for (int i=2;i<maxn;i++){
		if (!used[i]){
			prime[cnt++] =i;
			isprime[i] =true;
			int j =i;
			while (j<maxn){
				used[j] =true;
				j+=i;
			}
		}
	}
}
void work(){
	int x;
	cin>>x;
	int t=0;
	for (int i=0;i<cnt;i++){
		if (x%prime[i]==0)t=i;
	}
	int xmin = x-prime[t]+1;
	int ans =x;
	for (int i=xmin;i<=x;i++){
		int tt =-1;
		for (int j=2;j*j<=i;j++){
			if (i%j==0){
				if (isprime[j]){
					tt = max(tt,j);
				}
				if (isprime[i/j]){
					tt= max(tt,i/j);
				}
			}
		}
		ans = min(ans,i-tt+1);
	}
	cout<<ans<<endl;
}
int main(){
	init();
	work();
	return 0;
}