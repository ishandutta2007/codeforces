#include <bits/stdc++.h>
using namespace std;
#define mp(a,b) make_pair(a,b)
#define ff first
#define setp(a) setprecision(a)<<fixed
#define ss second
#define fori(v) for(int i=0; i<v; i++)
#define forj(v) for(int j=0; j<v; j++)
#define fork(v) for(int k=0; k<v; k++)
#define forl(v) for(int l=0; l<v; l++)
#define fort(v) for(int t=0; t<v; t++)
#define forz(v) for(int z=0; z<v; z++)
#define forx(v) for(int x=0; x<v; x++)
#define fory(v) for(int y=0; y<v; y++)
#define ll long long 
#define double long double
#define MAX 1010
#define MAX2 220
#define pb(a) push_back(a)
double eps = 1e-12;
const ll INF = 0x3f3f3f3f;
const ll inf = INF;
ll modulo = 998244353;

struct cube{
	int x,y,col;
};
vector<cube > cur, final;
vector<vector<int> > moves;
bool occ_x[55];
bool occ_y[55];
bool J(cube& a,cube& b){
	return a.y < b.y;
}
bool J1(cube& a, cube& b){
	return a.y > b.y;
}
void add_move(cube& a, cube& b, vector<vector<int> >& moves){
	vector<int> yen(4);
	yen[0] = a.x, yen[1] = a.y, yen[2] = b.x, yen[3] = b.y;
	moves.pb(yen);
}
void make_closer(int& x, int& y){ // make x closer to y
	if(y>x)
		++x;
	else
		--x;
}
bool in_between(int& a,int& b,int& c){
	return a >= min(b,c) && a<=max(b,c);	
}
void deal(){
	int n,m;
	cin>>n>>m;
	cur.resize(m);
	final = cur;
	fori(m)
		cin>>cur[i].x>>cur[i].y, cur[i].col = i;
	fori(m)
		cin>>final[i].x>>final[i].y, final[i].col = i;
	sort(cur.begin(), cur.end(), J);
	fori(m){
		int mx = 0;
		forj(i)
			if(cur[j].x == cur[i].x)
				mx = max(mx, cur[j].y);
		++mx;
		occ_x[cur[i].x] = 1;
		while(cur[i].y!=mx){
			cube pv = cur[i];
			make_closer(cur[i].y, mx);
			add_move(pv, cur[i], moves);
		}
	}
//	cout<<"histograms finished "<<endl;
	sort(cur.begin(), cur.end(), J1);
	fori(m){
		if(cur[i].y == 1)
			continue;
		if(cur[i].y!=n){
			cube pv = cur[i];
			make_closer(cur[i].y, n);
			add_move(pv, cur[i], moves);
		}
		int j = cur[i].x;
		while(j<=n && occ_x[j])
			++j;
		if(j==n+1){
			--j;
			while(j && occ_x[j])
				--j;
		}
		occ_x[j] = 1;
		while(cur[i].x != j){
			cube pv = cur[i];
			make_closer(cur[i].x, j);
			add_move(pv, cur[i], moves);
		}
		while(cur[i].y != 1){
			cube pv = cur[i];
			int req=  1;
			make_closer(cur[i].y, req);
			add_move(pv, cur[i], moves);
		}
	}
//	cout<<"line made"<<endl;
	sort(final.begin(), final.end(), J1);
	fori(final.size()){
		int need = -1;
		forj(cur.size())
			if(cur[j].col == final[i].col)
				need = j;
//		cout<<cur[need].y<<" "<<n-i<<endl;
		while(cur[need].y != n-i){
//			cout<<cur[need].y<<" "<<n-i<<endl;
			cube pv = cur[need];
			int pt = n-i;
			make_closer(cur[need].y, pt);
			add_move(pv, cur[need], moves);
		}
	}
//	cout<<"everyone in their column "<<endl;
	fori(final.size()){
		int need = -1;
		forj(cur.size())
			if(cur[j].col == final[i].col)
				need = j;
		while(cur[need].x != final[i].x){
			cube pv = cur[need];
			make_closer(cur[need].x, final[i].x);
			add_move(pv, cur[need], moves);
		}
	}
//	cout<<"everyone in their row "<<endl;
	forl(100){
		fori(final.size()){
			int need = -1;
			forj(cur.size())
				if(cur[j].col == final[i].col)
					need = j;
			bool fucked = 0;
			forj(cur.size()){
				if(j == need)
					continue;
				if(cur[j].x == final[i].x && in_between(cur[j].y, final[i].y, cur[need].y))
					fucked = 1;
			}
			if(fucked)
				continue;
			while(cur[need].y != final[i].y){
				cube pv = cur[need];
				make_closer(cur[need].y, final[i].y);
				add_move(pv, cur[need], moves);
			}
		}
	}
	assert(moves.size() <= 10800);
	cout<<moves.size()<<endl;
	fori(moves.size()){
		forj(4)
			cout<<moves[i][j]<<' ';
		cout<<endl;
	}
}



int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	deal();
}