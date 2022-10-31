#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int maxn = 505;
int a[maxn*2];
int n;
LL k;
queue<int> Q;
int main(){
	cin>>n>>k;
	if (k>n-2){
		cout<<n<<endl;
		return 0;
	}
	for (int i=1;i<=n;i++){
		cin>>a[i];
		Q.push(a[i]);
	}
	bool first = true;
	while (true){
		int now = Q.front();Q.pop();
		int cnt =0;
		if (!first){
			cnt =1;
		}else{
			first = false;
		}
		while (now>Q.front()&&cnt<k)cnt++,Q.push(Q.front()),Q.pop();
		if (cnt>=k){
			cout<<now<<endl;
			return 0;
		}
		Q.push(now);
	}
	return 0;
}