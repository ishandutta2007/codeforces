#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=100005;
int n,m;
string s;
int dis(char x,char y){
	if(x>y) return min(x-y,y+26-x);
	else return min(y-x,x+26-y);
}
int main(){
	int i,j;
	cin>>n;
	cin>>s;s=" "+s;
	int ans=1000000;
	for(i=1;i<=n-3;i++){
		ans=min(ans,dis(s[i],'A')+dis(s[i+1],'C')+dis(s[i+2],'T')+dis(s[i+3],'G'));
	}
	cout<<ans;
	return 0;
}