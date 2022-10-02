#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <cmath>
#define MAXN 100010
#define mod LL((1e9)+7)
#define INF 1<< 30
typedef unsigned long long ULL;
typedef unsigned long long LL;
using namespace std;

const int cc=10;
const LL M=1<<cc;
LL U=0;
LL cnt[M];
//~ vector <LL> cntL;
LL binL[M][M];
LL binLucky[M];
LL bin[MAXN];

LL fatt(LL x){
	if(x==0)return 1;
	return (fatt(x-1)*x)%mod;
}

LL inverso(LL x){
	if(x==1)return 1;
	return ((mod/x)*(mod-inverso(mod%x)))%mod;
}

LL binomial(LL n,LL m){
	if(m>n or m<0)return 0;
	LL sopra=fatt(n);
	LL sotto=(fatt(n-m)*fatt(m))%mod;
	return (sopra*inverso(sotto))%mod;
}

int main(){
	LL N,k;
	cin >> N >> k;
	for(LL i=0;i<N;i++){
		int x;
		cin >> x;
		int y=x;
		bool lucky=true;
		int c;
		while(x>0){
			c=x%10;
			if(c!=4 and c!=7){
				lucky=false;
				break;
			}
			x/=10;
		}
		if(!lucky){
			U++;
			continue;
		}
		int pot=1;
		int t=0;
		while(y>0){
			if(y%10==7)t+=pot;
			y/=10;
			pot<<=1;
		}
		t+=pot;
		cnt[t]++;
	}
	//~ for(int i=0;i<(1<<cc);i++)if(cnt[i]>0)cntL.push_back(cnt[i]);
	//~ cout << "Sfortunati: " << U << "\n Fortunati: ";
	//~ for(int i=0;i<int(cntL.size());i++)cout << cntL[i] << ", ";
	for(LL i=0;i<M;i++)binL[i][0]=1;
	for(LL i=1;i<M;i++)for(LL j=1;j<=i;j++)binL[i][j]=(binL[i-1][j]+binL[i-1][j-1]*cnt[i])%mod;
	for(LL i=0;i<M;i++)binLucky[i]=binL[M-1][i];
	//~ for(int i=1;i<=N;i++)bin[i]
	LL res=0;
	LL binomiale;
	bool funge=false;
	for(LL i=0;i<M;i++){
		if(k-i<0 or k-i>U)continue;
		if(!funge){
			binomiale=binomial(U,k-i);
			funge=true;
		}
		else{
			//~ cout << inverso(U-k+i) << endl;
			binomiale=(binomiale*(((k-i+1)*inverso(U-k+i))%mod))%mod;
		}
		//~ cout << binomiale << endl;
		res+=(binLucky[i]*binomiale)%mod;
	}
	cout << res%mod;
	//~ (N su 2)*2/(N-1)
}