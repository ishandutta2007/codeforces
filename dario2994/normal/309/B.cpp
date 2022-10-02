#include <iostream>
#include <cmath>
#define MAXW 5000010
using namespace std;

int N,r,c;
string ww[MAXW];
int ll[MAXW];
int ff[MAXW];
int vero[MAXW];


int main(){
	ios_base::sync_with_stdio(false);
	cin >> N >> r >> c;
	for(int i=0;i<N;i++){
		cin >> ww[i];
		ll[i]=ww[i].size();
	}
	ll[N]=2000000;
	
	int d=ll[0];
	int a=0, b=0;
	while(a<=N){
		if(d<=c){
			b++;
			d+=1+ll[b];
		}
		else{
			ff[a]=b;
			d-=1+ll[a];
			a++;
		}
	}
	
	for(int i=0;i<=N;i++)vero[i]=i;
	int s=r;
	while(r>0){
		if(r&1) for(int i=0;i<=N;i++)vero[i]=ff[vero[i]];
		r>>=1;
		for(int i=0;i<=N;i++)ff[i]=ff[ff[i]];
	}
	
	int it=0;
	for(int i=0;i<N;i++){
		if(vero[i]-i>vero[it]-it)it=i;
	}
	
	for(int i=0;i<s;i++){
		int qq=-1;
		while(qq+ll[it]+1<=c){
			if(qq>=0)cout << " ";
			cout << ww[it];
			qq+=ll[it]+1;
			it++;
		}	
		cout << "\n";
	}
}