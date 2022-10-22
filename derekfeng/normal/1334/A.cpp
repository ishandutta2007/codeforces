#include <bits/stdc++.h>
using namespace std;
int T,n;
pair<int,int>a[103];
void MAIN(){
	if (a[0].first<a[0].second){
		puts("NO");return;
	}
	for (int i=1;i<n;i++){
		if (a[i].first<a[i].second){
			puts("NO");return;
		}
		if (a[i].first==a[i-1].first && a[i].second!=a[i-1].second){
			puts("NO");return;
		}
		if (a[i].first<a[i-1].first){
			puts("NO");return;
		}
		if (a[i].first>a[i-1].first && (a[i].second<a[i-1].second || a[i].second-a[i-1].second>a[i].first-a[i-1].first)){
			puts("NO");return;
		}
	}
	puts("YES");
}
int main(){
	cin>>T;
	while (T--){
		cin>>n;
		for (int i=0;i<n;i++) cin>>a[i].first>>a[i].second;
		MAIN();
	}
}