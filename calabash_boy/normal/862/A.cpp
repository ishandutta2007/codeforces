#include<bits/stdc++.h>
using namespace std;
const int maxn = 105;
int used[maxn];
int n;
int x;
int main(){
	cin>>n>>x;
	for (int i=0;i<n;i++){
		int temp;
		cin>>temp;
		used[temp]++;
	}
	int ans =0;
	for (int i=0;i<x;i++){
		if (!used[i]){
			ans++;
		}
	}
	ans+=used[x];
	cout<<ans<<endl;
	return 0;
}