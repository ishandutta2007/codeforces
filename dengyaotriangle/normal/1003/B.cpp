#include<bits/stdc++.h>

using namespace std;

const int maxn=205;

int a,b,x,n,t;
int ans[maxn];

int main(){
	n=2;
	cin>>a>>b>>x;
	t=x;
	ans[0]=a;
	ans[1]=b;
	x--;
	bool gt=0;
	while(x!=0){
		gt=0;
		for(int i=n%2;i<n;i+=2){
			if(ans[i]>1){
				ans[i]--;
				ans[n++]=1;
				gt=1;
				x--;
				break;
			}
		}
		if(gt==0) break;	
	}
	if(!gt){
		n=2;
		x=t-1;
		ans[0]=b;
		ans[1]=a;
		while(x!=0){
			for(int i=n%2;i<n;i+=2){
				if(ans[i]>1){
					ans[i]--;
					ans[n++]=1;
					x--;
					break;
				}
			}
		}
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<ans[i];j++){
			cout<<!gt;
		}
		gt=!gt;
	}
	return 0;
}