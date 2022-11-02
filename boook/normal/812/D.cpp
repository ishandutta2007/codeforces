#include <bits/stdc++.h>
using namespace std;
#define REP(i , j , k) for(int i = j ; i < k ; i++)
#define pb push_back
#define DBGG(i , j) cout << i << " " << j << endl
#define DB4(i , j , k , l) cout << i << " " << j << " " << k << " " << l << endl
#define IOS cin.tie(0) , cout.sync_with_stdio(0)
//--------------------------------------
#define MAX 100900

int n , m , k , q , ok[MAX];
int root[MAX] , in[MAX] , siz[MAX] , out[MAX] , po = 0;
vector<int> v[MAX];
void DFS(int now){
	in[now] = po ++;
	siz[now] = 1;
	REP(i , 0 , v[now].size()){
		DFS(v[now][i]);
		siz[now] += siz[v[now][i]];
	}
	out[now] = po ++;
}
int help[MAX];
int main(){
	IOS;
	cin >> n >> m >> k >> q;
	REP(i , 1 , k + 1){
		int a , b;
		cin >> a >> b;
		if(help[b] == 0);
		else v[help[b]].pb(a) , ok[a] = 1;
		help[b] = a;
	}
	REP(i , 1 , n + 1) if(ok[i] == 0) DFS(i);
	REP(i , 1 , q + 1){
		int a , b;
		cin >> a >> b;
		int tmp = help[b];
		if(in[tmp] > in[a] && out[a] > out[tmp]){
			cout << siz[a] << endl;
		}
		else {
			cout << 0 << endl;
		}
	}
	return 0;
}