#include <iostream>
#include <fstream>
#include <cstring>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>
#define INF 2000000000
#define MAXN 100010
#define MAXM 1000000
typedef unsigned long long ULL;
typedef long long LL;
using namespace std;

ifstream in("input.txt");
int n,len;
LL a[MAXN];
int k;
bool active[MAXN];
priority_queue <pair <LL,int> > used;
priority_queue <pair <LL,int> > unused;
int i=0;

bool out(pair <LL,int> x){
	if(x.second>i-len and x.second <=i)return false;
	return true;
}

void clean(){
	while(!unused.empty() and out(unused.top()))unused.pop();//pulisco dalle cose vecchie
	while(!used.empty() and out(used.top()))used.pop();
}

void init(){
	i=-1;
	clean();
}

LL check(){
	vector <LL> act;
	act.assign(a+max(i-len+1,0),a+i+1);
	sort(act.begin(),act.end());
	int i=act.size()-1;
	LL vera=0;
	int scelti=0;
	while(i>=0 and act[i]>0 and scelti<k){
		scelti++;
		vera+=act[i];
		i--;
	}
	return vera;
}


vector <LL> f(){//la maggior somma di alpi k elementi in un intervallo lungo len.
	vector <LL> res;
	LL somma=0;
	int quanti=0;
	for(i=0;i<n;i++){
		if(a[i]>0)unused.push(make_pair(a[i],i));//aggiungo l'ultimo arrivato
		if(i-len>=0 and active[i-len]){//levo quello appena uscito
			quanti--;
			somma-=a[i-len];
			active[i-len]=false;
		}
		clean();
		while(!used.empty() and !unused.empty() and -used.top().first<unused.top().first){//scambio con i migliori
			pair <LL,int> x,y;
			x=used.top();
			y=unused.top();
			used.pop();
			unused.pop();
			somma+=y.first+x.first;
			x.first*=-1;
			y.first*=-1;
			clean();
			used.push(y);
			unused.push(x);
			active[x.second]=false;
			active[y.second]=true;
		}
		while(quanti<k and !unused.empty()){//aggiungo se posso
			pair <LL,int> y=unused.top();
			unused.pop();
			somma+=y.first;
			y.first*=-1;
			used.push(y);
			quanti++;
			active[y.second]=true;
			clean();
		}
		if(i>=len-1)res.push_back(somma);
		//controllo
		//~ if(somma+1!=check()){
			//~ cout << "WRONG";
			//~ return res;
		//~ }
	}
	return res;
}

int main(){
	cin >> n >> len;
	LL b[n];
	for(i=0;i<n;i++)cin >> b[i];
	cin >> k;
	for(i=0;i<n;i++)a[i]=b[i];
	init();
	vector <LL> toSottr=f();
	for(i=0;i<n;i++)a[i]=-b[i];
	init();
	vector <LL> toSum=f();
	for(i=1;i<n;i++)b[i]+=b[i-1];
	vector <LL> valori;
	LL maximum=0;
	for(int i=0;i<=n-len;i++){
		LL s;
		if(i>0)s=b[i+len-1]-b[i-1];
		else s=b[i+len-1];
		//~ valori.push_back(abs(s-2*toSottr[i]));
		//~ valori.push_back(abs(s+2*toSum[i]));
		maximum=max(abs(s-2*toSottr[i]),maximum);
		maximum=max(abs(s+2*toSum[i]),maximum);
	}
	//~ sort(valori.begin(),valori.end());
	//~ cout << valori[valori.size()-1];
	cout << maximum;
}