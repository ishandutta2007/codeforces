#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <set>
#define MAXN 2010
typedef unsigned long long ULL;
using namespace std;

int N;
string S;
string A,B;
ULL preH[MAXN];
ULL pot[MAXN];

ULL hh(int i, int j){
	ULL diff=preH[j+1]-preH[i];
	return diff*pot[N-i];
}

vector <ULL> hashi;
vector <int> occA, occB;

int main(){
	cin >> S;
	N=S.size();
	pot[0]=1;
	for(int i=1;i<=N;i++){
		preH[i]=preH[i-1]+(ULL(S[i-1]-'a')+1)*pot[i-1];
		pot[i]=29ull*pot[i-1];
	}
	cin >> A >> B;
	for(int i=0;i<=N-int(A.size());i++){
		bool funge=1;
		for(int j=0;j<int(A.size());j++)if(A[j]!=S[i+j]){
			funge=0;
			break;
		}
		if(funge)occA.push_back(i);
	}
	for(int i=0;i<=N-int(B.size());i++){
		bool funge=1;
		for(int j=0;j<int(B.size());j++)if(B[j]!=S[i+j]){
			funge=0;
			break;
		}
		if(funge)occB.push_back(i);
	}
	for(int i=0;i<int(occA.size());i++)for(int j=0;j<int(occB.size());j++){
		int x=occA[i], y=occB[j];
		if(x>y or x+A.size()>y+B.size())continue;
		hashi.push_back(hh(x,y));
	}
	sort(hashi.begin(),hashi.end());
	int res=0;
	if(!hashi.empty())res++;
	for(int i=1;i<int(hashi.size());i++)if(hashi[i]!=hashi[i-1])res++;
	cout << res << "\n";
}