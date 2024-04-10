#include <iostream>
#include <cmath>
#include <tr1/unordered_map>
#include <vector>
#include <queue>
#include <algorithm>
typedef long long LL;
using namespace std;
using namespace tr1;

int main(){
	int n;
	cin >> n;
	unordered_map <int,int> palle;
	for(int i=0;i<n;i++){
		int x;
		cin >> x;
		palle[x]++;
	}
	vector <pair <int,int> > numeri(palle.begin(),palle.end());
	priority_queue <pair <int,int> > coda;
	for(int i=0;i<int(numeri.size());i++){
		pair <int,int> nuova;
		nuova.first=numeri[i].second;
		nuova.second=numeri[i].first;
		coda.push(nuova);
	}
	vector <int> res[3];
	while(coda.size()>=3){
		pair <int,int> a[3];
		for(int i=0;i<3;i++){
			a[i]=coda.top();
			coda.pop();
			a[i].first--;
			res[i].push_back(a[i].second);
		}
		for(int i=0;i<3;i++)if(a[i].first>0)coda.push(a[i]);
	}
	cout << res[0].size() << endl;
	for(int i=0;i<int(res[0].size());i++){
		int u[3]={res[0][i],res[1][i],res[2][i]};
		sort(u,u+3);
		for(int x=2;x>=0;x--)cout << u[x] << " ";
		cout << "\n";
	}
}