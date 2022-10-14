#include<bits/stdc++.h>

using namespace std;
typedef long long int lli;
typedef pair<int, int> pii;
typedef pair<lli, lli> pll;
lli gcd(lli a, lli b){
	if(a==0)return b;
	return gcd(b%a,a);
}
int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	lli n,m;
	int q;
	cin>>n>>m>>q;
	lli every=gcd(n,m);
	lli rep1=n/every;
	lli rep2=m/every;
	lli s1,s2,e1,e2;
	for(int i=0;i<q;i++){
		cin>>s1>>e1>>s2>>e2;
		e1-=1;
		e2-=1;
		if(e1/(s1==1?rep1:rep2)==e2/(s2==1?rep1:rep2))printf("YES\n");
		else printf("NO\n");
	}
	return 0;
}