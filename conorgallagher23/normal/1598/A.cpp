#include<bits/stdc++.h>
#define ll long long
#define mp make_pair
#define fi first
#define se second
using namespace std;
const int N=105;
int n;
char s1[N],s2[N];
void solve(){
	scanf("%d",&n);
	scanf("%s",s1+1);scanf("%s",s2+1);
	for(int i=1;i<=n;i++)if(s1[i]=='1'&&s2[i]=='1'){
		cout<<"NO\n";
		return;
	}
	cout<<"YES\n";
}
int main(){
	int T;scanf("%d",&T);
	while(T--)solve();
	return 0;
}