#include<bits/stdc++.h>
#define fr first
#define sc second
#define mkp make_pair
#define pb push_back
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int N=1e5+5;
int n,m;
bool ok[N];
int ans;

char a[N];
void check(int x){
	if(x<=0||x+2>n) return;
	ans-=ok[x];
	ok[x]=((a[x]=='a')&&(a[x+1]=='b')&&(a[x+2]=='c'));
	ans+=ok[x];
}
int main(){
	int i,j;
	cin>>n>>m;
	cin>>(a+1);
	for(i=1;i<=n;i++) check(i);
	while(m--){
		int pos;char c;cin>>pos>>c;
		a[pos]=c;
		check(pos-2);
		check(pos-1);
		check(pos);
		cout<<ans<<endl;
	}
	return 0;
}