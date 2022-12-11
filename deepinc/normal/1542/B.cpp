#include<bits/stdc++.h>
using namespace std;
int main(){
	int t; cin>>t; while(t--){
		int n,a,b; scanf("%d%d%d",&n,&a,&b);
		if(b==1)puts("Yes");
		else if(a==1)puts(n%b^1?"No":"Yes");
		else{
			for(long long r=1;r<=n;r*=a)if((n-r)%b==0){puts("Yes");goto G;}
			puts("No");G:;
		}
	}
}