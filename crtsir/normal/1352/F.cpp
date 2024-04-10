#include<bits/stdc++.h>
using namespace std;
int n[3],T; 
int main(){
	cin>>T;
	while(T--){
		scanf("%d%d%d",&n[0],&n[1],&n[2]);
		if(n[0]||n[1])
			for(int i=0;i<=n[0];i++)
				cout<<0;
		if(n[1]||n[2])
			for(int i=0;i<=n[2];i++)
				cout<<1;
		n[1]--;
		for(int i=0;i<n[1];i++)
			cout<<i%2;cout<<endl;
	} 
}