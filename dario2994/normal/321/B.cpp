#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <cmath>
#define MAXM 200
using namespace std;

int M;
vector <int> attacco, difesa;
int F[MAXM];

bool usato[MAXM];
int EliminoTutti(){
	int it=0;
	for(int i=0;i<int(difesa.size());i++){
		while(it<M and (difesa[i]>=F[it] or usato[it]) )it++;
		if(it==M)break;
		usato[it]=1;
	}
	if(it==M)return 0; //non riesco neanche a battere la difesa!
	
	it=0;
	int res=0;
	for(int i=0;i<int(attacco.size());i++){
		while(it<M and (attacco[i]>F[it] or usato[it]))it++;
		if(it==M)break;
		usato[it]=1;
		res+=F[it]-attacco[i];
	}
	
	if(it==M)return 0; //non riesco a battere l'attacco
	for(int i=0;i<M;i++)if(!usato[i])res+=F[i];
	
	return res;
}

int main(){
	//~ ifstream cin("input.txt");
	ios_base::sync_with_stdio(false);
	int N;
	cin >> N >> M;
	string S;
	for(int i=0;i<N;i++){
		int forza;
		cin >> S >> forza;
		if(S=="ATK")attacco.push_back(forza);
		else difesa.push_back(forza);
	}
	for(int i=0;i<M;i++)cin >> F[i];
	sort(attacco.begin(), attacco.end());
	sort(difesa.begin(), difesa.end());
	sort(F,F+M);
	int val=EliminoTutti();
	
	int val2=0;
	for(int l=1;l<=min(int(attacco.size()), M);l++){
		bool funge=1;
		int res=0;
		for(int i=0;i<l;i++){
			if(attacco[i]<=F[M-i-1])res+=F[M-i-1]-attacco[i];
			else{
				funge=0;
				break;
			}
		}
		if(!funge)break;
		val2=max(val2, res);
	}
	cout << max(val, val2) << "\n";
}