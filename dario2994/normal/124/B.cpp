#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector <int> num[8];
vector <int> perm;
int n,k;

int trans(int x){
	int nuovo[k];
	for(int i=0;i<k;i++)nuovo[i]=num[x][perm[i]];
	int pot=1;
	int res=0;
	for(int i=k-1;i>=0;i--){
		res+=nuovo[i]*pot;
		pot*=10;
	}
	return res;
}

int main(){
	cin >> n >> k;
	for(int i=0;i<n;i++){
		for(int j=0;j<k;j++){
			char x;
			cin >> x;
			num[i].push_back(x-'0');
		}
	}
	//~ for(int i=0;i<n;i++){
		//~ for(int j=0;j<k;j++){
			//~ cout << num[i][j];
		//~ }
		//~ cout << endl;
	//~ }
	for(int i=0;i<k;i++)perm.push_back(i);
	int minimo=1000000000;
	while(1){
		int reali[n];
		for(int i=0;i<n;i++)reali[i]=trans(i);
		sort(reali,reali+n);
		minimo=min(minimo,reali[n-1]-reali[0]);
		if(!next_permutation(perm.begin(),perm.end()))break;
	}
	cout << minimo;
}