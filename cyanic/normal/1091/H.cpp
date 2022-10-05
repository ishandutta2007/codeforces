#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=a;i<=b;i++)
using namespace std;
 
const int N=200005,M=105;
int mn[N],p[N],sg[N],n,cnt,f,ans;
bitset<N> b[M],t;
 
void init(){
	rep(i,2,200000){
		if(!mn[i])p[++cnt]=i;
		if(!mn[i]||!mn[mn[i]])t[i]=1;
		for(int j=1;j<=cnt&&i*p[j]<=200000;j++){
			mn[i*p[j]]=i;
			if(i%p[j]==0)break;
		}
	}
}
 
int main(){
	cin>>n>>f;
	init(),t[f]=0;
	rep(i,0,200000){
		while(b[sg[i]][i])++sg[i];
		b[sg[i]]|=t<<i;
	}
	while(n--){
		int a,b,c;
		cin>>a>>b>>c;
		ans^=sg[b-a-1]^sg[c-b-1];
	}
	if(ans)puts("Alice"),puts("Bob");
	else puts("Bob"),puts("Alice");
	return 0;
}