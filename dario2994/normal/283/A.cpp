#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <cmath>
#define MAXN 200100
#define INF 1<< 30
typedef unsigned long long ULL;
typedef long long LL;
using namespace std;

int N;
int aggiunto[MAXN];
int valore[MAXN];
double res[MAXN];

int main(){
	LL somma=0;
	int q=1;
	cin >> N;
	for(int i=0;i<N;i++){
		int t;
		cin >> t;
		if(t==1){
			LL x;
			int a;
			cin >> a >> x;
			aggiunto[a-1]+=x;
			somma+=(LL)(a*x);
		}
		else if(t==2){
			int k;
			cin >> k;
			somma+=(LL)k; 
			valore[q]=k;
			q++;
		}
		else if(t==3){
			somma-=(LL)(aggiunto[q-1]+valore[q-1]);
			q--;
			aggiunto[q-1]+=aggiunto[q];
			aggiunto[q]=0;
		}
		res[i]=((double)somma)/((double)q);
	}
	cout.precision(7);
	for(int i=0;i<N;i++)cout << fixed << res[i] << "\n";
}