#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e5+100;
int last[maxn*2];
int n;
char a[maxn];
int ans;
int main(){
	scanf("%d",&n);
	scanf("%s",a); 
	for (int i=0;i<=2*n;i++){
		last[i] = n;
	}
	int del =n;
	last[del]=-1;
	for (int i=0;i<n;i++){
		if (a[i]=='1'){
			del++;
		}else{
			del--;
		}
		ans = max(ans,i-last[del]);
//		cout<<i<<" "<<" "<<del<<" "<<last[del]<<endl;
		last[del] = min(last[del],i);
	}
	cout<<ans<<endl;
	return 0;
}