#include <bits/stdc++.h>

using namespace std;

int main(){
	int t;
	cin>>t;
	while(t--){
		string s;
		cin>>s;
		int k;
		cin>>k;
		vector<int> ans(s.size() , -1);
		bool cc = 1;
		for(int i = 0 ; i < s.size() && cc ; i++){
			if(s[i] == '0') {
				if(i - k >= 0 && ans[i-k] == 1) cc = 0;
				if(i + k < s.size() && ans[i+k] == 1) cc = 0;
				if(i - k >= 0) ans[i-k] = 0;
				if(i+k<s.size()) ans[i+k] = 0;
			}
			else {
				if(i - k >= 0 && ans[i - k] != 0) ans[i - k] = 1;
				else{
					if(i + k < s.size()){
						if(ans[i + k] == 0) cc = 0;
						else ans[i + k] = 1;
					} else cc = 0;
				}
			}
		}
		if(cc) for(int i : ans) cout<<(i == -1 ? 0 : i);
		else cout<<-1;
		cout<<endl;
	}
}