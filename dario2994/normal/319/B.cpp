#include <iostream>
#include <fstream>
#include <queue>
#define MAXN 100100
using namespace std;

int N;
int id[MAXN], nn[MAXN];

int main(){
	ios_base::sync_with_stdio(false);
	cin >> N;
	for(int i=0;i<N;i++)cin >> id[i];
	id[N]=N+1;
	for(int i=0;i<N;i++)nn[i]=i+1;
	queue <int> coda;
	for(int i=N-1;i>=0;i--)if(id[i]>id[i+1])coda.push(i);
	int res=0;
	while(!coda.empty()){
		res++;
		int ll=coda.size();
		for(int i=0;i<ll;i++){
			int x=coda.front();
			coda.pop();
			nn[x]=nn[nn[x]];
			if(id[x]>id[nn[x]])coda.push(x);
		}
	}
	cout << res << "\n";
}