#include<iostream>
#include<algorithm>
using namespace std;
#define R register int
#define I inline
I int Get(int a,int b,int c,int d){
	if(b<c||d<a){
		return 0;
	}
	int l=a<c?a:c,r=b>d?b:d;
	return b+d-a-c+l-r+1;
}
struct Segment{
	int lf,rt;
	I friend bool operator<(Segment A,Segment B){
		return A.lf+A.rt<B.lf+B.rt;
	}
}s[2001];
int suf[2002];
I void Max(int&x,int y){
	x=x>y?x:y;
}
int main(){
	int n,m,k,ans,cur;
	cin>>n>>m>>k;
	for(R i=1;i<=m;i++){
		cin>>s[i].lf>>s[i].rt;
	}
	sort(s+1,s+1+m);
	for(R i=1;i+k!=n+2;i++){
		cur=0;
		for(R j=m;j!=0;j--){
			cur+=Get(s[j].lf,s[j].rt,i,i+k-1);
			Max(suf[j],cur);
		}
	}
	ans=suf[1];
	for(R i=1;i+k!=n+2;i++){
		cur=0;
		for(R j=1;j<=m;j++){
			cur+=Get(s[j].lf,s[j].rt,i,i+k-1);
			Max(ans,cur+suf[j+1]);
		}
	}
	printf("%d",ans);
	return 0;
}