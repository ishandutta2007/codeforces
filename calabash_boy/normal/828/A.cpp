#include<bits/stdc++.h>
using namespace std;


int n,a,b,c;
int main(){
	cin>>n>>a>>b;
	int ans=0;
	c=0;
	for (int i=0;i<n;i++){
		int temp;
		cin>>temp;
		if (temp==1){
			if (a>0){
				a--;
			}else if (b>0){
				b--;
				c++;
			}else if (c>0){
				c--;
			}else{
				ans++;
			}
		}else{
			if (b>0){
				b--;
			}else{
				ans+=2;
			}
		}
	}
	cout<<ans<<endl;
	return 0;
}