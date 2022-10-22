#include<bits/stdc++.h>
using namespace std;
int T;
string s,t;
void solve(){
	cin>>s>>t;
	for(int i=0;i<s.size();i++){
		for(int j=i;j<s.size()&&(j-i+1)<=t.size();j++){
			bool ok=1;
			int rem=t.size()-(j-i+1);
			for(int k=i;k<=j&&ok;k++)if(t[k-i]!=s[k])ok=0;
			if(!ok)continue;
			int cur=j-1,now=j-i+1;
			while(1){
				if(rem==0||cur<0)break;
				if(t[now]!=s[cur])break;
				rem--,now++,cur--;
			}
			if(rem==0){
				puts("YES");
				return;
			}
		}
	}
	puts("NO");
}
int main(){
	cin>>T;
	while(T--)solve();
}