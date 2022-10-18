#include<bits/stdc++.h>
using namespace std;
int T,n,cnt[1003],x;
int main(){
	cin>>T;while(T--){
		cin>>n>>x;memset(cnt,0,sizeof(cnt));
		for(int i=1;i<n;i++){
			int a,b;cin>>a>>b;
			cnt[a]++;cnt[b]++;
		}
		if(cnt[x]<=1)cout<<"Ayush\n";
		else if(n%2==1)cout<<"Ashish\n";
		else cout<<"Ayush\n";
	}
}