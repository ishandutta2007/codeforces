#include <bits/stdc++.h>
using namespace std;
#pragma optimize("-O3")
#define int long long int
#define f first
#define s second
#define pb push_back
#define endl '\n'
int po[26];


main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n;
	int t;
	po[0]=1;
	for(int i=1; i<26; i++){
		po[i]=2*po[i-1];
	}
	cin>>n>>t;
	string st;
	cin>>st;
	if(n==2){
	
		if(t==po[st[1]-'a']-po[st[0]-'a']){
			cout<<"Yes";
			return 0;
		}
		cout<<"No";
		return 0;
	}
	t-=po[st[st.size()-1]-'a'];
	t+=po[st[st.size()-2]-'a'];
	vector<int>v;
	for(int i=0; i<st.size()-2; i++){
		v.pb(po[st[i]-'a']);
	}
	sort(v.begin(), v.end());
	reverse(v.begin(), v.end());
	for(int i=0; i<v.size(); i++){
		if(t>=0){
			t-=v[i];
		}
		else{
			t+=v[i];
		}
	}
	if(t==0){
		cout<<"Yes";
	}
	else{
		cout<<"No";
	}
	return 0;
}