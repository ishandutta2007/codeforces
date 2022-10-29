// wish to get better qwq
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=2e5+5;
ll n,t,lqaq[N],nxt[N],vqaq[N];
string s;
template <typename T> void rd(T &x){
	ll fl=1;x=0;char c=getchar();
	for(;!isdigit(c);c=getchar()) if(c=='-') fl=-fl;
	for(;isdigit(c);c=getchar()) x=(x<<3)+(x<<1)+c-'0';
	x*=fl;
}
void wr(ll x){
	if(x<0) x=-x,putchar('-');
	if(x<10) putchar(x+'0');
	if(x>9) wr(x/10),putchar(x%10+'0');
}
int main(){
//	freopen(".in","r",qaqdin);
//	freopen(".out","w",qaqdout);
	rd(t);
	while(t--){
 		ll ans=0;
 		string s;cin>>s;
 		stack<char> qaq;
 		while(!qaq.empty()) qaq.pop();
 		for(int i=0;i<s.size();i++){
 			if(s[i]=='B'){
 				if(qaq.empty()||qaq.top()!='A') qaq.push(s[i]);
				else qaq.pop(),ans+=2;
			}
			else qaq.push(s[i]);
		}
		while(!qaq.empty()&&qaq.top() =='A') qaq.pop();
		ans+=qaq.size()-(qaq.size() & 1);
		wr(s.size()-ans);puts("");
	}
	return 0;
}