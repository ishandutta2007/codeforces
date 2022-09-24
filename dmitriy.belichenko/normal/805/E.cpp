#include<bits/stdc++.h>
using namespace std;
#define err(x) cout<<#x<<"= "<<x<<endl;
#define FOR(i,a,b) for(int i =a; i< b; ++i)
#define rep(i,n) FOR(i,0,n)
#define pb push_back
#define INF 1000000000
#define TRVI(it,it1,it2) for(vi::iterator it = it1; it!= it2; it++)
#define ff first
#define ss second
#define mp make_pair
#define pq priority_queue<int, vector<int>, greater<int> >
#define ll long long
const ll PR = 1000000009;
#define SIZE 300009
#define vi vector<int>
#define pii pair<int,int>
#define endl '\n'
int n,m;
vi vis(SIZE,0), cinv[SIZE],llist[SIZE],color(SIZE,0);
int cm=1;


void colr(int v){
	vis[v]=1;
	set<int> present;
//	cout<<"For vertex: "<<v<<endl;
	rep(i, cinv[v].size()){
//		cout<<cinv[v][i]<<' '<<
		if(color[cinv[v][i]]!=0)
		present.insert(color[cinv[v][i]]);
	}
	int cnow= 1;
	rep(i,cinv[v].size()){
		if(color[cinv[v][i]]==0){
		while(present.find(cnow)!= present.end())cnow++;
//		cout<<cinv[v][i]<<' '<<cnow<<endl;
		color[cinv[v][i]]=cnow;
		cm = max(cm,cnow);
		cnow++;
		}
	}
	present.clear();
	rep(i, llist[v].size()){
		int nxt = llist[v][i];
		if(vis[nxt]==0){
			colr(nxt);
		}
	}
}




int main(){
//	#ifdef ONLINE_JUDGE
//	freopen("a.in", "r" , stdin);
//	freopen("a.out", "w", stdout);
//      cin.tie(false); cout.tie(false);	
//	#endif
	ios::sync_with_stdio(false);
	cin>>n>>m;
	rep(i,n){
		int no;
		cin>>no;
		rep(j, no){
			int a;cin>>a;
			cinv[i].pb(a-1);
		}
	}
	rep(i,n-1){
		int a,b;
		cin>>a>>b;
		a--;b--;
		llist[a].pb(b);llist[b].pb(a);
	}
	colr(0);
	cout<<cm<<endl;
	rep(i,m){
		cout<<max(color[i],1)<<' ';
	}
	cout<<endl;
	return 0;
};