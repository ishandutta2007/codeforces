#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <cmath>
#define MAXN 305
#define MAXS 100100
#define INF 1<< 30
typedef unsigned long long ULL;
typedef long long LL;
using namespace std;

const unsigned int mod=1e9+7;
int N,Q;
LL T;
LL a[MAXN];
int f[MAXN];
bool toAdd[MAXN];
bool usato[MAXN];

unsigned int cxx[MAXS];

int main(){
	cin >> N >> Q >> T;
	for(int i=1;i<=N;i++)cin >> a[i];
	for(int i=0;i<Q;i++){
		int uu,vv;
		cin >> uu >> vv;
		f[uu]=vv;
		toAdd[vv]=true;
	}
	for(int i=1;i<=N;i++){
		if(!toAdd[i]){
			int j=i;
			usato[j]=1;
			while(f[j]!=0){
				T-=a[j];
				a[f[j]]+=a[j];
				j=f[j];
				usato[j]=1;
			}
		}
	}
	for(int i=1;i<=N;i++)if(!usato[i]){
		cout << 0 << "\n";
		return 0;
	}
	//~ for(int i=1;i<=N;i++)cout << a[i] << " ";
	//~ cout << " = " << T << "\n";
	if(T<0){
		cout << 0 << "\n";
		return 0;
	}
	cxx[0]=1;
	for(int i=1;i<=N;i++){
		if(a[i]>T)continue;
		for(int j=a[i];j<=T;j++)cxx[j]=(cxx[j]+cxx[j-a[i]])%mod;
	}
	cout << cxx[T] << "\n";
}