/*
***


***
*/
#include<bits/stdc++.h>
#define re register int
using namespace std;
typedef long long ll;
const int N=2e5+5;
int n,m,ans[N],a[N],l=1,r,len,cnt[N],nw,qaq,qwq,lsh[N],cntcnt[N];
struct Question{int id,l,r,pl,pr,t;}q[N];
struct change{int x,to,pre;}mo[N];
template <typename T> inline void rd(T &x){
	int fl=1;x=0;char c=getchar();
	for(;!isdigit(c);c=getchar()) if(c=='-') fl=-fl;
	for(;isdigit(c);c=getchar()) x=(x<<3)+(x<<1)+c-'0';
	x*=fl;
}
void wr(int x){
	if(x<0) x=-x,putchar('-');
	if(x<10) putchar(x+'0');
	if(x>9) wr(x/10),putchar(x%10+'0');
}
inline bool cmp(Question x,Question y){
	if(x.pl^y.pl) return x.pl<y.pl;
	if(x.pr^y.pr) return x.pr<y.pr;
	return x.t<y.t; 
}
inline void update(int x,int op){
	cntcnt[cnt[a[x]]]--,cnt[a[x]]+=op,cntcnt[cnt[a[x]]]++;
}
inline void modify(int x,int op){
	if(mo[x].x>=l&&mo[x].x<=r){
		if(op==1){
			cntcnt[cnt[a[mo[x].x]]]--;
			cnt[a[mo[x].x]]--;
			cntcnt[cnt[a[mo[x].x]]]++;
			mo[x].pre=a[mo[x].x];a[mo[x].x]=mo[x].to;
			cntcnt[cnt[a[mo[x].x]]]--;
			cnt[a[mo[x].x]]++;
			cntcnt[cnt[a[mo[x].x]]]++;
		}
		else{
			cntcnt[cnt[a[mo[x].x]]]--;
			cnt[a[mo[x].x]]--;
			cntcnt[cnt[a[mo[x].x]]]++;
			a[mo[x].x]=mo[x].pre;
			cntcnt[cnt[a[mo[x].x]]]--;
			cnt[a[mo[x].x]]++;
			cntcnt[cnt[a[mo[x].x]]]++;
		}
	}
	else{
		if(op==1) mo[x].pre=a[mo[x].x],a[mo[x].x]=mo[x].to;
		else a[mo[x].x]=mo[x].pre;
	}
}
int main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	ios::sync_with_stdio(0);
	rd(n);rd(m);
	len=(int)pow(n,2./3.);
	for(re i=1;i<=n;i++) rd(a[i]),lsh[i]=a[i];
	for(re i=1;i<=m;i++){
		int op;rd(op);
		if(op==2) ++qaq,rd(mo[qaq].x),rd(mo[qaq].to),lsh[qaq+n]=mo[qaq].to;
		else if(op==1) ++qwq,rd(q[qwq].l),rd(q[qwq].r),q[qwq].id=qwq,q[qwq].pl=(q[qwq].l-1)/len+1,q[qwq].pr=(q[qwq].r-1)/len+1,q[qwq].t=qaq;
	}
	sort(q+1,q+qwq+1,cmp);sort(lsh+1,lsh+n+qaq+1);
	ll awa=unique(lsh+1,lsh+n+qaq+1)-lsh-1;
	for(re i=1;i<=n;i++) a[i]=lower_bound(lsh+1,lsh+awa+1,a[i])-lsh;
	for(re i=1;i<=qaq;i++) mo[i].to=lower_bound(lsh+1,lsh+awa+1,mo[i].to)-lsh; 
	for(re i=1;i<=qwq;i++){
		while(l>q[i].l) --l,update(l,1);
		while(r<q[i].r) ++r,update(r,1);
		while(l<q[i].l) update(l,-1),l++;
		while(r>q[i].r) update(r,-1),r--;
		while(nw<q[i].t) ++nw,modify(nw,1);
		while(nw>q[i].t) modify(nw,-1),nw--;
		for(re k=1;k<N;k++)
			if(cntcnt[k]==0){
				ans[q[i].id]=k;
				break;
			}
	}
	for(re i=1;i<=qwq;i++) wr(ans[i]),puts("");
	return 0;
}