#include<bits/stdc++.h>
using namespace std;
const int MAX = 105;
int sum1[MAX],sum0[MAX];
int n;
vector<int> index;
int main(){
	scanf("%d",&n);
	for (int i=1;i<=n;i++){
		sum0[i]=sum0[i-1];
		sum1[i]=sum1[i-1];
		int temp;
		scanf("%d",&temp);
		if (temp){
			index.push_back(i);
			sum1[i]++;
		}else{
			sum0[i]++;
		}
	}
	if (sum1[n]==0){
		cout<<n<<endl;
		return 0;
	}
	int ans =sum1[n];
	for (auto x :index){
		ans = min(ans,sum1[x-1]+sum0[n]-sum0[x-1]);
	}
	cout<<n-ans<<endl;
}