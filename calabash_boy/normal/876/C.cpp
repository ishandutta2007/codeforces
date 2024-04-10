#include<bits/stdc++.h>
using namespace std;
int n,k;
vector<int> ans;
int main(){
	cin>>n;
	for (int i=0;i<min(100,n);i++){
		int temp = n-i;
		if (temp<=0)break;
		int tt = temp;
		int cnt =0;
		while (tt){
			cnt+=tt%10;
			tt/=10;
		}
		if (cnt==i){
			ans.push_back(temp);
		}
	}
	cout<<(int)ans.size()<<endl;
	reverse(ans.begin(),ans.end());
	for (auto x:ans){
		cout<<x<<endl;
	}
	return 0;
}