#include<bits/stdc++.h>
const int M=998244353;
int n,m,a,lst,s;long long mx;
int main(){
	scanf("%d%d",&n,&m);
	s=1;
	for(int i=1;i<=n;i++){
	  scanf("%d",&a);
	  if(a>n-m){
		mx+=a;
		if(lst)s=(long long)s*(i-lst)%M;
		lst=i;
	  }
	}printf("%lld %d\n",mx,s);
	return 0;
}