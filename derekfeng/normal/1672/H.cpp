#include<bits/stdc++.h>
using namespace std;
int n,q;
int N,pos[200004],s[200004];
char c[200004];
int main(){
	scanf("%d%d%s",&n,&q,c+1);
	pos[1]=N=1,s[1]=c[1]=='0'?-1:1;
	for(int i=2;i<=n;i++){
		pos[i]=pos[i-1];
		if(c[i]==c[i-1])
			s[++N]=c[i]=='0'?-1:1,pos[i]++;
	}
	for(int i=1;i<=N;i++)s[i]+=s[i-1];
	while(q--){
		int l,r;scanf("%d%d",&l,&r);
		l=pos[l],r=pos[r];
		printf("%d\n",1+(r-l+abs(s[r]-s[l]))/2);
	}
}