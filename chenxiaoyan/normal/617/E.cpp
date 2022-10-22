/*




D P 




 l l
*/
#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=100000,QU=100000,XOR_I=1048576;
int n,qu,m;
int a[N+1];
int Xor[N+1];
int bsz;
struct query{
	int l,r,qid;
	friend bool operator<(query x,query y){
		int xlin=(x.l+bsz-1)/bsz,ylin=(y.l+bsz-1)/bsz;
		return xlin==ylin?xlin&1?x.r<y.r:x.r>y.r:xlin<ylin;
	}
}qry[QU+1];
int cnt[XOR_I];
int ans[QU+1];
signed main(){
	cin>>n>>qu>>m;
	for(int i=1;i<=n;i++)cin>>a[i],Xor[i]=Xor[i-1]^a[i];
	for(int i=1;i<=qu;i++)cin>>qry[i].l>>qry[i].r,qry[i].qid=i;
	bsz=max(1ll,min(n,(int)(n/sqrt(qu))));
	sort(qry+1,qry+qu+1);
	int nowl=1,nowr=0,nowans=0;
	for(int i=1;i<=qu;i++){
		int l=qry[i].l,r=qry[i].r,qid=qry[i].qid;
		while(nowl>l)cnt[Xor[--nowl]]++,nowans+=cnt[Xor[nowl-1]^m];
		while(nowr<r)cnt[Xor[++nowr]]++,nowans+=cnt[Xor[nowr]^m]-!m+((Xor[nowl-1]^Xor[nowr])==m);
		while(nowl<l)nowans-=cnt[Xor[nowl-1]^m],cnt[Xor[nowl++]]--;
		while(nowr>r)nowans-=cnt[Xor[nowr]^m]-!m+((Xor[nowl-1]^Xor[nowr])==m),cnt[Xor[nowr--]]--;
		ans[qid]=nowans;
	}
	for(int i=1;i<=qu;i++)cout<<ans[i]<<"\n";
	return 0;
}