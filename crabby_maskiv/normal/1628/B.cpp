#include<bits/stdc++.h>
#define fr first
#define sc second
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int N=2e5+5;
int n,m;
string s[N];
inline void solve(){
	set<string> st;
	int i;
	for(i=1;i<=n;i++){
		if(s[i].length()==1){
			cout<<"YES"<<endl;
			return;
		}
		else if(s[i].length()==2){
			string t=s[i];swap(t[0],t[1]);
			if(t[0]==t[1]){
				cout<<"YES"<<endl;
				return;
			}
			if(st.find(t)!=st.end()){
				cout<<"YES"<<endl;
				return;
			}
		}
		else{
			string t=s[i];swap(t[0],t[2]);
			if(t[0]==t[2]){
				cout<<"YES"<<endl;
				return;
			}
			if(st.find(t)!=st.end()){
				cout<<"YES"<<endl;
				return;
			}
			t.pop_back();
			if(st.find(t)!=st.end()){
				cout<<"YES"<<endl;
				return;
			}
		}
		st.insert(s[i]);
	}
	st.clear();
	for(i=n;i;i--){
		if(s[i].length()==2) st.insert(s[i]);
		else{
			string t=s[i];t.pop_back();
			swap(t[0],t[1]);
			if(st.find(t)!=st.end()){
				cout<<"YES"<<endl;
				return;
			}
		}
	}
	cout<<"NO"<<endl;
}
int main(){
	int i,j;
	int _;cin>>_;
	while(_--){
		cin>>n;
		for(i=1;i<=n;i++) cin>>s[i];
		solve();
		for(i=1;i<=n;i++) s[i].clear();
	}
	return 0;
}