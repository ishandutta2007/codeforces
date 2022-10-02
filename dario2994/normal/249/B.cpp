#include <iostream>
#include <fstream>
#define MAXN 500010
#define INF 1<< 30
using namespace std;

int t,N;
char A[MAXN];
int last=0;
int Q[MAXN];

int tempo(int cnt){
	int tLast=N-1;
	int res=0;
	for(int i=0;i<N;i++){
		if(cnt>=0 and i>last){
			tLast=i-1;
			break;
		}
		Q[i]=1;
		if(cnt<0)Q[i]++;
		if(A[i]=='H')cnt--;
		else if(A[i]=='S')cnt++;
		if(cnt<0)Q[i]++;
		res+=Q[i];
	}
	if(cnt<0)return INF;
	int res2=res;
	for(int i=tLast;i>=0;i--){
		if(i==tLast)res+=1-Q[i];
		else res+=2-Q[i];
		res2=min(res2,res);
	}
	return res2;
}

int main(){
	cin >> N >> t;
	cin >> A;
	for(int i=0;i<N;i++)if(A[i]=='H')last=i;
	int l=0;
	int r=N+1;
	while(l<r){
		int m=(l+r)/2;
		if(tempo(m)<=t)r=m;
		else l=m+1;
	}
	if(l==N+1)cout << -1;
	else cout << l;
}