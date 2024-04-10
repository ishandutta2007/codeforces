#include <bits/stdc++.h>
using namespace std;
#pragma optimize("-O3")
#define f first
#define s second
#define pb push_back
#define endl '\n'
 
 
 
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		map<string, bool>che;
		bool pre=0;
		for(int i=0; i<n; i++){
			string st;
			cin>>st;
			if(pre){
				continue;
			}
			string str=st;
			reverse(str.begin(), str.end());
			che[st]=1;
			if(che[str]){
				pre=1;
				continue;
			}
			int sz=st.size();
			if(sz==3){
				string stn="";
				stn+=st[2];
				stn+=+st[1];
				if(che[stn]){
					pre=1;
				}
			}
			if(sz==2){
				for(int i=0; i<26; i++){
					string stn="";
					stn+=st[1];
					stn+=st[0];
					stn+=char('a'+i);
					if(che[stn]){
						pre=1;
						break;
					}
				}
			}
		}
		if(pre){
			cout<<"YES"<<endl;
		}
		else{
			cout<<"NO"<<endl;
		}
	}
	return 0;
}