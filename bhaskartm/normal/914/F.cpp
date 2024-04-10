#include <bits/stdc++.h>
using namespace std;
#pragma optimize("-O3")

#define f first
#define s second
#define pb push_back
#define endl '\n'

bitset<100005>vals[26];
bitset<100005>cons;
bitset<100005>ans;

 
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n, m;
	string st;
	cin>>st;
	n=st.size();

	cin>>m;
	for(int i=0; i<st.size(); i++){
		vals[st[i]-'a'][i]=1;
	}
	for(int i=0; i<100005; i++){
		cons[i]=1;
	}
	while(m--){
		int ty;
		cin>>ty;
		if(ty==1){
			int pos;
			cin>>pos;
			char c;
			cin>>c;
			pos--;
			vals[st[pos]-'a'][pos]=0;
			st[pos]=c;
			vals[st[pos]-'a'][pos]=1;
		}
		else{
			int l, r;
			string stt;
			cin>>l>>r>>stt;
			int nn=stt.size();
			l--;
			r--;
			if(r-l+1<stt.size()){
				cout<<0<<endl;
				continue;
			}
			ans=cons;
			for(int i=0; i<stt.size(); i++){
				ans &= (vals[stt[i]-'a']>>i);
			}
			cout<<(((ans>>l).count())-((ans>>(r-nn+2)).count()))<<endl;
		}
	}
	
	
	return 0;
}