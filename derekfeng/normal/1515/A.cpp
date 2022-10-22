#include<bits/stdc++.h>
using namespace std;
int t,n,x,w[103],ans;
int main(){
	cin>>t;
	while(t--){
		ans=0;
		cin>>n>>x;
		for(int i=1;i<=n;i++)cin>>w[i],ans+=w[i];
		if(ans==x){
			puts("NO");
			continue;
		}
		puts("YES");
		sort(w+1,w+n+1);
		reverse(w+1,w+n+1);
		bool ok=1;
		for(int i=1;i<=n&&ok;i++){
			if(x==w[i]){ok=0;break; }
			if(x<w[i])break;
			x-=w[i];
		}
		if(!ok){
			int tmp=w[n];
			for(int i=n;i>1;i--)w[i]=w[i-1];
			w[1]=tmp;
		}
		for(int i=1;i<=n;i++)cout<<w[i]<<" ";puts(""); 
	}
}