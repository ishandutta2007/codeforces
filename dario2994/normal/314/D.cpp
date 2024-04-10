#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <cmath>
#define MAXN 100100
#define INF 1<< 30
typedef unsigned long long ULL;
typedef long long LL;
using namespace std;

int N;
pair <LL,LL> boh[MAXN];
LL a[MAXN];
LL b[MAXN];

LL pref[MAXN], PREF[MAXN]; //non compreso
LL suf[MAXN] , SUF[MAXN]; //compreso

bool solve(LL M){
	int it=0;
	for(int i=0;i<N;i++){
		while(it!=N and a[i]+M>=a[it])it++;
		//~ cout << i << "-> " << it << "\n";
		if(i==0 and it==N)return true;
		if(a[i]+M>=a[it-1]){
			LL mm=min(pref[i],suf[it]);
			LL MM=max(PREF[i],SUF[it]);
			//~ cout << MM << " " << mm << "\n";
			if(MM-mm<=M)return true;
		}
	}
	return false;
}

int main(){
	//~ ifstream cin("input.txt");
	ios_base::sync_with_stdio(false);
	cin >> N;
	LL x,y;
	for(int i=0;i<N;i++){
		cin >> x >> y;
		boh[i].first=x-y;
		boh[i].second=x+y;
	}
	sort(boh,boh+N);
	for(int i=0;i<N;i++){
		a[i]=boh[i].first;
		b[i]=boh[i].second;
		//~ cout << a[i] << " " << b[i] << "\n";
	}
	//~ cout << "\n";
	
	pref[0]=1e10;
	PREF[0]=-1e10;
	for(int i=1;i<=N;i++){
		pref[i]=min(pref[i-1],b[i-1]);
		PREF[i]=max(PREF[i-1],b[i-1]);
	}
	suf[N]=1e10;
	SUF[N]=-1e10;
	for(int i=N-1;i>=0;i--){
		suf[i]=min(suf[i+1],b[i]);
		SUF[i]=max(SUF[i+1],b[i]);
	}
	
	//~ cout << SUF[3] << "\n";
	
	//~ cout << solve(171568073) << "\n";
	//~ return 0;
	
	LL ll=0;
	LL rr=1e10;
	while(ll<rr){
		LL mm=(ll+rr)/2;
		if(solve(mm))rr=mm;
		else ll=mm+1;
	}
	cout.precision(10);
	cout << fixed << ((double)ll)/2.0 << "\n";
}