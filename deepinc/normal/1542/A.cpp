#include<bits/stdc++.h>
using namespace std;
int main(){
	int t; cin>>t; while(t--){
		int n,c=0,r; scanf("%d",&n);
		for(int i=1;i<=n+n;++i)scanf("%d",&r),c+=r&1;
		puts(c^n?"No":"Yes");
	}
}