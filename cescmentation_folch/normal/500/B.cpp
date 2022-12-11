#include<iostream>
#include<vector>
#include<map>
#include<queue>
#include<math.h>
#include<set>
#include<algorithm>
#include<string>
#include<stack>
#include<iomanip>
#include<stdio.h>
#include<bits/stdc++.h>

using namespace std;

#define X first
#define Y second
#define forl(i,a,f) for(int i = (int)a;i <= (int)f;++i)
#define rofl(i,a,f) for(int i = (int)a;i >= (int)f;--i)
#define pb push_back
#define pi 3.14159265
#define inf 2e9
#define INF 9e18
#define minll(a,b) ((long long)a < (long long)b)? a : b
#define maxll(a,b) ((long long)a > (long long)b)? a : b

typedef vector<double> VD;
typedef vector<VD> VVD;
typedef vector<int> VI;
typedef vector<VI> VVI;
typedef long long ll;
typedef vector<ll> Vll;
typedef vector<Vll> VVll;
typedef pair<ll ,ll> Pll;
typedef vector<Pll> VPll;
typedef vector<VPll> VVPll;
typedef pair<int, int> PI;
typedef pair<bool , int> PBI;
typedef pair<PI,PBI> PIB;
typedef vector<PI> VPI;
typedef vector<VPI> VVPI;
typedef queue<int> QI;
typedef priority_queue<PI> PQPI;
typedef queue<PI> QPI;
typedef queue<PIB> QPIB;
typedef vector<bool> VB;
typedef vector<char> VC;
typedef vector<VC> VVC;
typedef stack<int> SI;

VVI G;
VI A;
VB T;

int pare(int x){
	//cout<<"A-"<<x<<"="<<A[x]<<endl;
	if(A[x] == x) return x;
	return A[x] = pare(A[x]);
}

void dfs(int x){
	//cout<<"->"<<x<<endl;
	if(T[x]) return;
	T[x] = true;
	forl(i,0,G[x].size()-1){
		//cout<<"<"<<i<<endl;
		int y = G[x][i];
		//cout<<" <"<<y<<endl;
		A[pare(y)] = pare(x);
		//cout<<x<<endl;
		dfs(y);
	}
}

int main(){
	int n;
	cin>>n;
	int p[n];
	G = VVI(n);
	A = VI(n);
	T = VB(n,false);
	forl(i,0,n-1){ 
		cin>>p[i];
		A[i] = i;
	}
	forl(i,0,n-1){
		forl(j,0,n-1){
			char a;
			cin>>a;
			if(a == '1'){
				G[i].pb(j);
			}
		}
	}
	//cout<<0<<endl;
	forl(i,0,n-1){
		if(!T[i]) dfs(i);
	}
	//cout<<1<<endl;
	forl(i,0,n-2){
		forl(j,i+1,n-1){
			if(p[j] < p[i] && pare(j) == pare(i)){
				int c = p[j];
				p[j] = p[i];
				p[i] = c;
			}
		}
	}
	forl(i,0,n-1){
		if(i > 0) cout<<" ";
		cout<<p[i];
	}
	cout<<endl;
}