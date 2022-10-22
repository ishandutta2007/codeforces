#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int MN = 1e5+3, A = 2e6+3;
int pfreq[A], lz, a[MN],  SQ, k, tot;
ll cnt, ans[MN];
struct Q {
	int l,r,bl,ind;
	void read(int i) {scanf ("%d%d",&l,&r);bl=l/SQ;ind=i;}
};
void push (int i) {
	tot ^= a[i];
	cnt += pfreq[tot^k^lz];
	++pfreq[tot^lz];
}
void del (int i) {
	lz ^= a[i];
	tot ^= a[i];
	--pfreq[a[i]^lz];
	cnt -= pfreq[a[i]^k^lz];
}
void front (int i) {
	cnt += pfreq[a[i]^k^lz];
	++pfreq[a[i]^lz];
	lz ^= a[i];
	tot ^= a[i];
}
int main () { //REEEEEE
    int n,m;
	scanf ("%d %d %d",&n,&m,&k);
	for (int i = 1; i <= n; i++) scanf ("%d",a+i);
	vector<Q> queries(m);
	SQ = max(1,(int)(n/sqrt(m)));
	for (int i = 0; i < m; i++) queries[i].read(i); 
	sort(queries.begin(),queries.end(),[](Q aa,Q b){return aa.bl==b.bl?aa.r<b.r:aa.bl<b.bl;});
	int lastl=-1,lastr=-1,lastb=-1;
	for (auto &q : queries) {
		if (q.bl > lastb) {
			memset(pfreq,0,sizeof pfreq);
			lz = cnt = tot = 0; pfreq[0] = 1;
			for (int i = q.l; i <= q.r; i++) push(i);
			ans[q.ind] = cnt; lastl=q.l,lastr=q.r,lastb=q.bl;
			continue;
		}
		while(lastr<q.r) push(++lastr);
		while(lastl<q.l) del(lastl++);
		while(lastl>q.l) front(--lastl);
		ans[q.ind] = cnt;
		lastl=q.l,lastr=q.r,lastb=q.bl;
	}
	for (int i = 0; i < m; i++) printf ("%lld\n",ans[i]);
    return 0;
}