#include<bits/stdc++.h>
#define mid ((l+r)>>1) 
const int N=500050;
using namespace std;

int s[N],n,t,q,sn[]={-1,1};
char S[N];

int sum(int l,int r,int p){
	return (((l^p)&1)?1:-1)*(s[r]-s[l-1]);
}

int chk(int l,int r,int m){
	return sum(l,m-1,0)-sum(m+1,r,m-l+1);
} 

int calc(int l,int r){
	if(l==r)return l;
	int L=l,R=r;
	while(l<=r){
		if(!chk(L,R,mid))return mid;
		if(!chk(L,R,l))return l;
		if(!chk(L,R,r))return r;
		else if((chk(L,R,mid)>0)^(chk(L,R,l)<0)) l=mid+1;
		else r=mid-1;
	}
}

main(){
	scanf("%d",&t);
	while(t--){
		scanf("%d%d%s",&n,&q,S+1);
		for(int i=1;i<=n;i++)if((S[i]=='+')^(i&1))
			s[i]=s[i-1]+1;
		else s[i]=s[i-1]-1;
		for(int i=1;i<=q;i++){
			int l,r,fl=0;
			scanf("%d%d",&l,&r);
			if((r-l+1)&1)printf("1\n");
			else if(s[r]-s[l-1])printf("2\n%d ",l),l++;
			else printf("0\n"),fl=1;
			if(!fl)printf("%d\n",calc(l,r));
		} 
	}
}