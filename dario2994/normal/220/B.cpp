#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
#include <string>
#include <queue>
#include <tr1/unordered_map>
#define MAXN 100010
#define INF 1000000100
#define rp(i,n) for(int i=0;i<n;i++)
#define rp1(i,n) for(int i=1;i<=n;i++)
using namespace std;
using namespace tr1;
typedef long long LL;
typedef unsigned long long ULL;

int n,m;
int a[MAXN];
vector <int> buoni;
int b;
int sum[500][MAXN];//sum[i][u] quanti buoni[i] ci sono tra 0 e u (compresi)?
int res[MAXN];

int main(){
	cin >> n >> m;
	unordered_map <int,int>  quanti;
	rp(i,n){
		cin >> a[i];
		quanti[a[i]]++;
	}
	vector <pair <int,int> > v(quanti.begin(),quanti.end());
	//rp(i,int(v.size()))cout << v[i].first << " " << v[i].second << endl;
	rp(i,int(v.size()))if(v[i].first<=v[i].second)buoni.push_back(v[i].first);
	b=buoni.size();
	//rp(i,int(buoni.size()))cout << buoni[i] << " ";
	rp1(i,n){
		rp(j,b){
			if(a[i-1]==buoni[j])sum[j][i]=sum[j][i-1]+1;
			else sum[j][i]=sum[j][i-1];
		}
	}
	//~ rp(j,b){
		//~ cout << buoni[j] << ": ";
		//~ rp(i,n+1)cout << sum[j][i] << " ";
		//~ cout << endl;
	//~ }
	rp(i,m){
		int x,y;
		cin >> x >> y;
		rp(j,b)if(buoni[j]==sum[j][y]-sum[j][x-1])res[i]++;
	}
	rp(i,m)cout << res[i] << "\n";
}