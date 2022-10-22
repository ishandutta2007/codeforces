#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=100005;
int n,m;
int cnt[30];
string s;
int main(){
	int i,j;
	cin>>n;
	cin>>s;
	s=" "+s;
	for(i=1;i<=n;i++){
		for(j=26;j>s[i]-'a';j--){
			if(cnt[j]!=0){
				cout<<"YES"<<endl;
				cout<<cnt[j]<<" "<<i;
				return 0;
			}
		}
		cnt[s[i]-'a']=i;
	}
	cout<<"NO";
	return 0;
}