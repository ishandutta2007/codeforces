/*




D P 




 l l
*/
#include<bits/stdc++.h>
using namespace std;
#define int long long
#define X first
#define Y second
#define mp make_pair
int gcd(int x,int y){return y?gcd(y,x%y):x;}
const int N=200000,QU=200000,A_I=1000000;
int n,qu;
int a[N+1];
int bsz;
struct query{
	int l,r,qid;
	friend bool operator<(query x,query y){
		int xlin=(x.l+bsz-1)/bsz,ylin=(y.l+bsz-1)/bsz;
		return xlin!=ylin?xlin<ylin:xlin&1?x.r<y.r:x.r>y.r;
	}
}qry[QU+1];
int cnt[A_I+1];
int ans[QU+1];
void add(int x,int &nowans){
	nowans-=cnt[a[x]]*cnt[a[x]]*a[x];
	cnt[a[x]]++;
	nowans+=cnt[a[x]]*cnt[a[x]]*a[x];
}
void del(int x,int &nowans){
	nowans-=cnt[a[x]]*cnt[a[x]]*a[x];
	cnt[a[x]]--;
	nowans+=cnt[a[x]]*cnt[a[x]]*a[x];
}
signed main(){
	cin>>n>>qu;
	for(int i=1;i<=n;i++)scanf("%lld",a+i);
	bsz=max(1ll,min(n,(int)(1.*n/sqrt(qu))));
	for(int i=1;i<=qu;i++)scanf("%lld%lld",&qry[i].l,&qry[i].r),qry[i].qid=i;
	sort(qry+1,qry+qu+1);
	int nowl=1,nowr=0,nowans=0;
	for(int i=1;i<=qu;i++){
		int l=qry[i].l,r=qry[i].r,qid=qry[i].qid;
		while(nowl>l)add(--nowl,nowans);
		while(nowr<r)add(++nowr,nowans);
		while(nowl<l)del(nowl++,nowans);
		while(nowr>r)del(nowr--,nowans);
		ans[qid]=nowans;
	}
	for(int i=1;i<=qu;i++)printf("%lld\n",ans[i]);
	return 0;
}
/*1
3 2
1 2 1
1 2
1 3
*/
/*2
8 3
1 1 2 2 1 3 1 1
2 7
1 6
2 7
*/