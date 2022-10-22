#pragma GCC optimize(3)//O3
#include<bits/stdc++.h>
using namespace std;
#define SG 100//SG
#define DIF 200000//2
#define pb push_back
int taboo/*f*/,sg[DIF+1]/*sg[i]iSG*/;
vector<int> pr;//
bitset<DIF+1> npr/**/,ok/**/,hav[SG+1]/*hav[i][j]j
SGi*/;
void eratosthenes(){//Eratosthenes
	for(int i=2;i<=DIF;i++){
		if(!npr[i])pr.pb(i);
		else continue;
		for(int j=i<<1;j<=DIF;j+=i)npr.set(j);
	}
}
void ok_prework(){//ok
	int i;
	for(i=0;i<pr.size();i++)ok.set(pr[i]);//
	for(i=0;i<pr.size();i++)for(int j=i;j<pr.size();j++){//
		if(1ll*pr[i]*pr[j]>1ll*DIF)break;
		ok.set(pr[i]*pr[j]);
	}
	ok.reset(taboo);//taboo
}
void sg_prework(){//SG
	for(int i=1;i<=DIF;i++){
		while(hav[sg[i]][i])sg[i]++;//mex
		hav[sg[i]]|=ok<<i;//
	}
}
int main(){
	eratosthenes();
	int n,totsg=0/*2nICGSG*/;scanf("%d%d",&n,&taboo);
	ok_prework();
	sg_prework();
	while(n--){
		int a,b,c;scanf("%d%d%d",&a,&b,&c);
		totsg^=sg[b-a/**/]^sg[c-b/**/];//\

	}
	printf(totsg?"Alice\nBob":"Bob\nAlice");//0
	return 0;
}
/*1
1 6
0 3 9
*/
/*2
1 2
0 3 9
*/
/*3
10 133
-248 -193 -187
97 101 202
-72 67 91
23 89 215
-129 -108 232
-223 -59 236
-99 86 242
-137 -109 -45
-105 173 246
-44 228 243
*/