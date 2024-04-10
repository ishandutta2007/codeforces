/*








 l l 
*/
#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=100000;
int n;
int a[N+1],Sum[N+1];
signed main(){
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		Sum[i]=Sum[i-1]+a[i];
	}
	if(Sum[n]&1)return puts("NO"),0;
	multiset<int> s1,s2(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		s1.insert(a[i]);s2.erase(s2.find(a[i]));
		int now=Sum[i],need=Sum[n]/2;
		int Delta=now-need;
		if(!Delta||s1.find(Delta)!=s1.end()||s2.find(-Delta)!=s2.end())return puts("YES"),0;
	}
	puts("NO");
	return 0;
}