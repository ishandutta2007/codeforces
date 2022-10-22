#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=200005;
const ll inf=0x3f3f3f3fll;
const ll mod=998244353ll;
int n,m;
string s;
int ans[N];
int main(){
    int i,j;
    int T;cin>>T;
    while(T--){
    	cin>>n;
    	cin>>s;s=" "+s;
    	string s2=s;
    	sort(s2.begin(),s2.end());
    	int pos=1;
    	for(i=1;i<=n;i++) ans[i]=0;
    	for(i=1;i<=n;i++){
    		while(pos<=n&&s[pos]!=s2[i]) pos++;
    		if(pos>n) break;
    		ans[pos]=1;
    		pos++;
		}
		pos=1;
		for(;i<=n;i++){
    		while(pos<=n&&(ans[pos]==1||s[pos]!=s2[i])) pos++;
    		if(pos>n) break;
    		ans[pos]=2;
    		pos++;
		}
		if(i<=n){
			cout<<"-"<<endl;
			continue;
		}
		for(i=1;i<=n;i++) cout<<ans[i];
		cout<<endl;
	}
    return 0;
}