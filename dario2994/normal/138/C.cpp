#include <iostream>
#include <cmath>
#include <algorithm>
#define MAXM int(1<<14)
#define MAXN 100010
using namespace std;

int N,M;
pair <int,double> mush[MAXM];
int pos[MAXN];
int ord[MAXM];
int h[MAXN];
double pL[MAXN];
double pR[MAXN];
double temp[MAXM];

double Tree[2*MAXM];

int after(int x){
	if(mush[M-1].first<=x)return -1;
	int i=0;
	int j=M-1;
	while(i<j){
		int media=(i+j)/2;
		if(x<mush[media].second){
			j=media;
		}
		else{
			i=media+1;
		}
	}
	return i;
}

void aggiorna(int v, int a,int b,int i,int  j,double value){
	//~ cout << a << " " << b << endl;
	if(i<=mush[a].first and mush[b].first<=j){
		Tree[v]*=double(1)-value;
		return;
	}
	if(mush[b].first<i or j<mush[a].first)return;
	int media=(a+b)/2;
	aggiorna(2*v,a,media,i,j,value);
	aggiorna(2*v+1,media+1,b,i,j,value);
}

int main(){
	cin >> N >> M;
	for(int i=0;i<N;i++){
		cin >> pos[i];
		cin >> h[i];
		cin >> pL[i];
		cin >> pR[i];
		pL[i]/=double(100);
		pR[i]/=double(100);
	}
	for(int i=0;i<M;i++){
		cin >> mush[i].first >> mush[i].second;
	}
	sort(mush,mush+M);
	for(int i=0;i<M;i++)temp[i]=1;
	//~ for(int i=0;i<N;i++){
		//~ int a1=after(pos[i]-h[i]-1);
		//~ int a2=after(pos[i]-1);
		//~ if(pL[i]==1)pL[i]=0.99999999999999;
		//~ if(a1!=-1)temp[a1]*=double(double(1)-pL[i]);
		//~ if(a2!=-1)temp[a2]/=double(double(1)-pL[i]);
		//~ int b1=after(pos[i]);
		//~ int b2=after(pos[i]+h[i]);
		//~ if(pR[i]==1)pR[i]=0.99999999999999;
		//~ if(b1!=-1)temp[b1]*=double(double(1)-pR[i]);
		//~ if(b2!=-1)temp[b2]/=double(double(1)-pR[i]);
	//~ }
	for(int i=M;i<MAXM;i++){
		mush[i].first=1000000100;
		mush[i].second=0;
	}
	for(int i=1;i<2*MAXM;i++)Tree[i]=1;
	for(int i=0;i<N;i++){
		aggiorna(1,0,MAXM-1,pos[i]-h[i],pos[i]-1,pL[i]);
		aggiorna(1,0,MAXM-1,pos[i]+1,pos[i]+h[i],pR[i]);
	}
	double res=0;
	for(int i=0;i<M;i++){
		double yo=1;
		int act=MAXM+i;
		while(act!=0){
			yo*=Tree[act];
			act/=2;
		}
		res+=yo*mush[i].second;
	}
	cout.precision(10);
	cout << res;
}