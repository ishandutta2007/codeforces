#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <cmath>
#define MAXN
#define INF 1<< 30
typedef unsigned long long ULL;
typedef long long LL;
using namespace std;

int N,M;
int cc[30];
int b[1000010];

int main(){
	ios_base::sync_with_stdio(false);
	cin >> N >> M;
	int a;
	for(int i=0;i<N;i++){
		cin >> a;
		int it=0;
		while(a){
			if(a&1)cc[it]++;
			it++;
			a>>=1;
		}
		//~ if(i%10000==9999)cout << i << "\n";
	}
	
	for(int i=0;i<M;i++)cin >> b[i];
	sort(b,b+M);
	
	//~ if(N==918286){
		//~ cout << "YO\n";
		//~ return 0;
	//~ }
	
	int res=0;
	int vv=0;
	int it=0;
	while(it<30 and res<M){
		int x=1<<b[res];
		if(vv>=x){
			vv-=x;
			res++;
			continue;
		}
		else{
			if(cc[it]>0 and (1<<it)>=x){
				vv=(1<<it)-x;
				cc[it]--;
				res++;
			}
			else it++;
		}
	}
	cout << res << "\n";
}