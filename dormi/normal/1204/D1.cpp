#include<bits/stdc++.h>

using namespace std;
typedef long long int lli;
typedef pair<int, int> pii;
typedef pair<lli, lli> pll;

int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	string s;
	cin>>s;
	int zcnt=0;
	int ocnt=0;
	for(int i=s.size()-1;i>=0;i--){
		if(s[i]=='1'){
			ocnt++;
		}
		else{
			zcnt++;
		}
		if(s[i]=='1'&&ocnt>zcnt){
			zcnt++;
			s[i]='0';
		}
	}
	cout<<s<<"\n";
	return 0;
}