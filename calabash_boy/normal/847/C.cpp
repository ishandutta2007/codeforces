#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
LL n,nn,k;
vector<char> ans;
int main(){
	cin>>nn>>k;
	n=nn;
	int now=0;
	while (k>0){
		if (k>=now){
			k-=now;
			ans.push_back('(');
			now++;
			n--;
		}else{
			ans.push_back(')');
			now--;
		}
		if (n<0){
			return 0*puts("Impossible");
		}
	}
	while (now--){
		ans.push_back(')');
	}
	for (int i=0;i<n;i++){
		ans.push_back('(');
		ans.push_back(')');
	}
	for (char c:ans){
		printf("%c",c);
	}
	return 0;
}