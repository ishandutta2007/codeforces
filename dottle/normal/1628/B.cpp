#include<bits/stdc++.h>
#define int long long
const int N=1000005;
using namespace std;

map<string,int> a,b; 

int ins(string s){
	reverse(s.begin(),s.end());
	if(a[s]||b[s])return 1;
	reverse(s.begin(),s.end());
	a[s]=1;
	return 0;
}

void solve(){
	a.clear();
	b.clear();
	int n,fl=0;cin>>n;
	for(int i=1;i<=n;i++){
		string s;cin>>s;
		string t=s;reverse(t.begin(),t.end());
		if(s==t)fl=1;
		if(s.size()==1)
			fl|=1;
		if(s.size()==2){
			fl|=ins(s);
			s.erase(s.begin());
			if(a[s])fl=1;
		}
		if(s.size()==3){
			reverse(t.begin(),t.end());
			t.pop_back();
			fl|=ins(s);
			s.erase(s.begin());
			reverse(s.begin(),s.end());
			if(a[s])fl=1;
			reverse(s.begin(),s.end());
			s.erase(s.begin());
			if(a[s])fl=1;
			b[t]=1;
		}
	}
	cout<<(fl?"Yes":"No")<<endl;
}

main(){
	int _T=1;cin>>_T;
	while(_T--)solve();
}