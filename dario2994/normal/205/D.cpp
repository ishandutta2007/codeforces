#include <stdio.h>
#include <stdlib.h>
#include <cmath>
#include <fstream>
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <string>
#include <queue>
#include <set>
#include <stack>
#include <tr1/unordered_map>
#define MAXH 100000
#define INF 200000000
typedef unsigned long long int ULL;
typedef long long int LL;
using namespace std;
using namespace tr1;

unordered_map <int,int> quanti;
unordered_map <int,int> girati;
int n;
int main(){
	cin >> n;
	for(int i=0;i<n;i++){
		int x,y;
		cin >> x >> y;
		if(x==y){
			quanti[x]++;
			girati[x]++;
		}
		else{
			quanti[x]++;
			girati[x]++;
			quanti[y]++;
		}
	}
	vector <pair <int,int> > col(quanti.begin(),quanti.end());
	int risultato=INF;
	int obj=n/2;
	if(n%2)obj++;
	for(int i=0;i<int(col.size());i++){
		if(col[i].second<obj)continue;
		int c=col[i].first;
		if(girati[c]>=obj)risultato=0;
		else{
			risultato=min(risultato,obj-girati[c]);
		}
	}
	if(risultato==INF)cout << -1;
	else cout << risultato;
}