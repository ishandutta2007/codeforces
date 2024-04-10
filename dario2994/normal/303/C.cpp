#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <set>
#define MAXV 1000000
#define INF 1<< 30
typedef unsigned long long ULL;
typedef long long LL;
using namespace std;

int N, k;
int a[5010];

int ll[MAXV+1];
int val[MAXV+1][5];

int main(){
	//~ ifstream cin("input.txt");
	cin >> N >> k;
	for(int i=0;i<N;i++)cin >> a[i];
	sort(a,a+N);
	//~ for(int * i=a;i<a+N;i++)for(int * j=i+1;j<a+N;j++) cc[(*j)-(*i)].push_back(*i);
	for(int * i=a;i<a+N;i++)for(int * j=i+1;j<a+N;j++){
		int x=(*j)-(*i);
		if(ll[x]==5)continue;
		val[x][ll[x]]=*i;
		ll[x]++;
	}
	//~ if(N==5000){
		//~ cout << "YO\n";
		//~ return 0;
	//~ }
	
	for(int m=max(1,N-2*k);m<=MAXV+1;m++){
		set <int> qq;
		for(int j=m;j<=1e6;j+=m){
			for(int i=0;i<ll[j];i++){
				int x=val[j][i];
				//~ if(m==13)cout << x << " " << j << "\n";
				qq.insert(x);
			}
			if(int(qq.size())>k)break;
		}
		if(int(qq.size())<=k){
			cout << m << "\n";
			break;
		}
	}
}