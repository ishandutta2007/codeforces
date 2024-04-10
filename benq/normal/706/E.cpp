#include <bits/stdc++.h>
using namespace std;
 
typedef pair <int, int> pii;

#define mp make_pair
#define FOR(i, a, b) for (int i=a; i<b; i++)
#define F0R(i, a) for (int i=0; i<a; i++)
#define f first
#define s second

struct elem{
	pii pr, pc, nr, nc;
};

int val[1001][1001];
int n,m1,q; 
elem m[1002][1002];

void prep() {
	ios_base::sync_with_stdio(0);cin.tie(0);
	cin >> n >> m1 >> q;
	FOR(i,1,n+1) FOR(j,1,m1+1) cin >> val[i][j];
	F0R(i,n+2) F0R(j,m1+2) {
		m[i][j].pr = mp(i-1,j), m[i][j].nr = mp(i+1,j);
		m[i][j].pc = mp(i,j-1), m[i][j].nc = mp(i,j+1);
	}
}

void modify(int a, int b, int c, int d, int h, int w) {
	pii cur = mp(a,0), cur1 = mp(c,0);
	F0R(j,b-1) cur = m[cur.f][cur.s].nc;
	F0R(j,d-1) cur1 = m[cur1.f][cur1.s].nc;
	F0R(j,h) {
		pii c = m[cur.f][cur.s].nc,c1 = m[cur1.f][cur1.s].nc;
		swap(m[c.f][c.s].pc, m[c1.f][c1.s].pc);
		swap(m[cur.f][cur.s].nc,m[cur1.f][cur1.s].nc);
		if (j != (h-1)) cur = m[cur.f][cur.s].nr,cur1 = m[cur1.f][cur1.s].nr;
	}
	cur = m[cur.f][cur.s].nc,cur1 = m[cur1.f][cur1.s].nc;
	cur = m[cur.f][cur.s].nr,cur1 = m[cur1.f][cur1.s].nr;
	F0R(j,w) {
		pii c = m[cur.f][cur.s].pr,c1 = m[cur1.f][cur1.s].pr;
		swap(m[c.f][c.s].nr, m[c1.f][c1.s].nr);
		swap(m[cur.f][cur.s].pr,m[cur1.f][cur1.s].pr);
		if (j != (w-1)) cur = m[cur.f][cur.s].nc,cur1 = m[cur1.f][cur1.s].nc;
	}
	cur = m[cur.f][cur.s].pr,cur1 = m[cur1.f][cur1.s].pr;
	cur = m[cur.f][cur.s].nc,cur1 = m[cur1.f][cur1.s].nc;
	F0R(j,h) {
		pii c = m[cur.f][cur.s].pc,c1 = m[cur1.f][cur1.s].pc;
		swap(m[c.f][c.s].nc, m[c1.f][c1.s].nc);
		swap(m[cur.f][cur.s].pc,m[cur1.f][cur1.s].pc);
		if (j != (h-1)) cur = m[cur.f][cur.s].pr,cur1 = m[cur1.f][cur1.s].pr;
	}
	cur = m[cur.f][cur.s].pc,cur1 = m[cur1.f][cur1.s].pc;
	cur = m[cur.f][cur.s].pr,cur1 = m[cur1.f][cur1.s].pr;
	F0R(j,w) {
		pii c = m[cur.f][cur.s].nr,c1 = m[cur1.f][cur1.s].nr;
		swap(m[c.f][c.s].pr, m[c1.f][c1.s].pr);
		swap(m[cur.f][cur.s].nr,m[cur1.f][cur1.s].nr);
		if (j != (w-1)) cur = m[cur.f][cur.s].pc,cur1 = m[cur1.f][cur1.s].pc;
	}
}

void print() {
	FOR(i,1,n+1) {
		pii cur = mp(i,0);
		F0R(j,m1) {
			cur = m[cur.f][cur.s].nc;
			cout << val[cur.f][cur.s] << " ";
		}
		cout << "\n";
	}
}

int main() {
	prep();
	F0R(i,q) {
		int a,b,c,d,h,w; cin >> a >> b >> c >> d >> h >> w;
		modify(a,b,c,d,h,w);
	}
	print();
}