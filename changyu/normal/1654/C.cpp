#include<bits/stdc++.h>
#define int long long
const int N=2e5+3;
int n,a[N],s;
std::map<int,int>t;
bool Check(int s){
	if(!s)return 0;
	if(t[s]){--t[s];return 1;}
	return Check(s/2)&&Check(s-s/2);
}
signed main(){
	int T;scanf("%lld",&T);for(;T--;){
	scanf("%lld",&n);
	s=0,t.clear();
	for(int i=1;i<=n;i++)scanf("%lld",a+i),++t[a[i]],s+=a[i];
	puts(Check(s)?"YES":"NO");
	}return 0;
}