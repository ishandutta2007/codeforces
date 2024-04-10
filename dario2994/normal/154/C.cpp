#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#define MAXN 1000000
#define P ULL(173)
typedef unsigned long long ULL;
using namespace std;

int inizi[MAXN+1];
int fini[MAXN+1];
vector <int> amici[MAXN+1];
pair <int,int> hashi[MAXN+1];
int N,M;

pair <ULL,ULL> hasha(int id){
	ULL pot=1;
	ULL res=0;
	ULL ss=0;
	for(int i=0;i<int(amici[id].size());i++){
		res+=pot*ULL(amici[id][i]);
		pot*=P;
		ss+=amici[id][i];
	}
	return make_pair(res,ss);
}
//~ 
//~ bool testa(int x,int y){
	//~ ULL pot=1;
	//~ ULL hash1=0;
	//~ for(int i=0;i<int(amici[x].size());i++){
		//~ if(amici[x][i]==y)continue;
		//~ hash1+=pot*ULL(amici[x][i]);
		//~ pot*=P;
	//~ }
	//~ pot=1;
	//~ ULL hash2=0;
	//~ for(int i=0;i<int(amici[y].size());i++){
		//~ if(amici[y][i]==x)continue;
		//~ hash2+=pot*ULL(amici[y][i]);
		//~ pot*=P;
	//~ }
	//~ return hash1==hash2;
//~ }

int main(){
	ios_base::sync_with_stdio(false);
	//~ ifstream in("input.txt");
	cin >> N >> M;
	for(int i=0;i<M;i++){
		int x,y;
		cin >> x >> y;
		amici[x].push_back(y);
		amici[y].push_back(x);
		inizi[i]=x;
		fini[i]=y;
	}
	for(int i=1;i<=N;i++)sort(amici[i].begin(),amici[i].end());
	for(int i=1;i<=N;i++)hashi[i]=hasha(i);
	
	ULL res=0;
	int i=1;
	sort(hashi+1,hashi+N+1);
	while(i<=N){
		int j=i;
		pair <int,int> act=hashi[i];
		while(j<=N and hashi[j]==act)j++;
		ULL q=j-i;
		res+=q*(q-1)/2;
		i=j;
	}
	
	for(int i=1;i<=N;i++)amici[i].push_back(i);
	for(int i=1;i<=N;i++)sort(amici[i].begin(),amici[i].end());
	for(int i=1;i<=N;i++)hashi[i]=hasha(i);
	for(int i=0;i<M;i++){
		int x=inizi[i];
		int y=fini[i];
		if(hashi[x]==hashi[y])res++;
	}
	
	//~ for(int i=1;i<=3;i++)cout << hashi[i].second << " " ;
	//~ cout << endl;
	
	cout << res << endl;
}