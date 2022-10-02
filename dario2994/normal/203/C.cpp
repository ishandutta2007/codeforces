#include <iostream>
#include <fstream>
#include <cstring>
#include <vector>
#include <stack>
#include <set>
#include <algorithm>
#include <tr1/unordered_map>
#define INF 2000000000
#define MAXN 1500
#define MAXM 1500
typedef long long LL;
typedef unsigned long long ULL;
using namespace std;
using namespace tr1;
ofstream in("input.txt");

ULL N,d,a,b;
ULL clienti[100003];

bool compare(int x,int y){
	if(clienti[x]<clienti[y])return true;
	return false;
}
int Qcompare (const void * a, const void * b)
{
  return ( clienti[*(int*)a] - clienti[*(int*)b] );
}

int main(){
	cin >> N >> d;
	cin >> a >> b;
	for(int i=1;i<=N;i++){
		ULL x,y;
		cin >> x >>y;
		clienti[i]=x*a+y*b;
	}
	int o[N+1];
	for(int i=1;i<=N;i++)o[i]=i;
	sort(o+1,o+N+1,compare);
	//qsort(o+1,N,sizeof(int),compare);
	ULL somma=0;
	int quanti=0;
	vector <int> scelti;
	while(quanti<N and somma+clienti[o[quanti+1]]<=d){
		quanti++;
		scelti.push_back(o[quanti]);
		somma+=clienti[o[quanti]];
	}
	cout << quanti << endl;
	for(int i=0;i<quanti;i++)cout << scelti[i] << " ";
}