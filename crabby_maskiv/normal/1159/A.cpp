#include<bits/stdc++.h>
//#define TIME
using namespace std;
typedef long long ll;
const int N=100005;
const ll inf=0x3f3f3f3f;
const ll mod=19260817;
int n,m;
string s; 
int main(){
	ios::sync_with_stdio(0);
	int i,j;
	cin>>n;
	cin>>s;
	s=" "+s;
	int cnt=0,mn=0;
	for(i=1;i<=n;i++){
		if(s[i]=='-') cnt--;
		else cnt++;
		mn=min(cnt,mn);
	}
	cout<<-mn+cnt;
	return 0;
}