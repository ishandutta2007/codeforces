#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#define MAXN 100000
typedef unsigned long long ULL;
using namespace std;

int prime[MAXN+1];
vector <int> fact[MAXN+1];
int ciSta[10000];
bool presente[MAXN+1];

void erat(){
	int len=0;
	for(int i=2;i<=MAXN;i++){
		if(!fact[i].empty())continue;
		prime[i]=len;
		for(int j=i;j<=MAXN;j+=i)fact[j].push_back(len);
		len++;
	}
	//~ cout << len << endl;
}


int main(){
	erat();
	int N,M;
	cin >> N >> M;
	for(int i=0;i<M;i++){
		char s;
		int x;
		cin >> s >> x; 
		if(s=='+'){
			if(presente[x]==true)cout << "Already on\n";
			else{
				int funge=0;
				for(int j=0;j<int(fact[x].size());j++)if(ciSta[fact[x][j]]!=0)funge=ciSta[fact[x][j]];
				if(funge!=0)cout << "Conflict with " << funge << "\n";
				else{
					cout << "Success\n";
					presente[x]=true;
					for(int j=0;j<int(fact[x].size());j++)ciSta[fact[x][j]]=x;
				}
			}
		}
		else if(s=='-'){
			if(presente[x]==false)cout << "Already off\n";
			else{
				cout << "Success\n";
				presente[x]=false;
				for(int j=0;j<int(fact[x].size());j++)ciSta[fact[x][j]]=0;
			}
		}
	}
}