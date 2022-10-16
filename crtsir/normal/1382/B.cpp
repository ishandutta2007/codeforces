#include<bits/stdc++.h>
using namespace std;
int T,n,a;
int main(){
	cin>>T;
	while(T--){
		cin>>n;int cnt=0,ok=1;
		for(int i=0;i<n;i++){
			scanf("%d",&a);
			if(a==1&&ok)
				cnt++;
			else
				ok=0;
		}
		cnt+=ok;
		if(cnt%2==0)
			cout<<"First\n";
		else
			cout<<"Second\n";
	}
}