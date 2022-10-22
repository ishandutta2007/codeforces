#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=200005;
const ll inf=0x3f3f3f3f;
const ll mod=998244353;
int n,m;
stack<ll> s;
string a[N];
ll st[N],top,len;
ll num[N];
int main(){
	ios::sync_with_stdio(0);
	int i,j;
	cin>>n;
	ll mul=1;
	ll ans=0;
	for(i=1;i<=n;i++){
		string tmp;ll x;
		cin>>tmp;
		if(tmp=="for"){
			cin>>x;
			st[++top]=x;
		}
		else if(tmp=="end"){
			if(top) top--;
			else a[++len]="end";
		}
		else{
			for(j=1;j<=top;j++){
				a[++len]="for";
				num[len]=st[j];
			}
			top=0;
			a[++len]="add";
		}
	}
	for(i=1;i<=len;i++){
		string op=a[i];
		//cout<<op<<endl;
		if(op=="for"){
			mul*=num[i];
			if(mul>(1ll<<32ll)-1){
				cout<<"OVERFLOW!!!";
				return 0;
			}
			s.push(num[i]);
		}
		else if(op=="end"){
			mul/=s.top();
			s.pop();
		}
		else{
			ans+=mul;
			if(ans>(1ll<<32ll)-1){
				cout<<"OVERFLOW!!!";
				return 0;
			}
		}
	}
	cout<<ans;
	return 0;
}