#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=100005;
const ll inf=0x3f3f3f3fll;
const ll mod=1000000007ll;
int n,m;
int a[N];
int main(){
    ios::sync_with_stdio(0);
	int i,j;
	int T;cin>>T;
	while(T--){
		cin>>n>>m;
		for(i=1;i<=n;i++) cin>>a[i];
		sort(a+1,a+n+1);
		int p=0,ans=0;
		for(i=n;i;){
			if(a[i]>p) ans++;
			else break;
			p+=m;
			int pos=i;
			while(a[pos]==a[i]) pos--;
			i=pos;
		}
		cout<<ans<<endl;
	}
    return 0;
}