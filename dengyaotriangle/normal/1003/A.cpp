#include<bits/stdc++.h>

using namespace std;

const int maxn=105;

int c[maxn];
int n;
int tmp;
int ans;

int main(){
	cin>>n;
	while(n--){
		cin>>tmp;
		c[tmp]++;
		ans=max(ans,c[tmp]);
	}
	cout<<ans;
	return 0;
}