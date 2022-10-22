#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=2000005;
const ll mod=1000000007ll;
int n,m;
int tag[N];
string s[N];
int len[N];
string ans;
int main() {
	int i,j;
	cin>>n;
	for(i=1;i<=n;i++){
		cin>>s[i];len[i]=s[i].length();s[i]=" "+s[i];
		int T;cin>>T;
		while(T--){
			int k;cin>>k;
			if(len[i]<len[tag[k]]) continue;
			tag[k]=i;m=max(m,k+len[i]-1);
		}
	}
	int pos=0,p=0;
	for(i=1;i<=m;i++){
		if(tag[i]){
			if(pos==0||i+len[pos]-p<i+len[tag[i]]-1){
				pos=tag[i];
				p=1;	
			}
		}
		if(p>len[pos]) pos=0;
		if(!pos) ans+="a";
		else ans+=s[pos][p];
		p++;
	}
	cout<<ans;
    return 0;
}