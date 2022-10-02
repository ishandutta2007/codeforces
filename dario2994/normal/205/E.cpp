#include <stdio.h>
#include <stdlib.h>
#include <cmath>
#include <fstream>
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <string>
#include <queue>
#include <set>
#include <stack>
#include <tr1/unordered_map>
#define MAXN 200100
#define INF 200000000
#define abc 26
#define REP for(int id=0;id<2;id++)
#define REPN for(int i=0;i<N;i++)
#define REPN1 for(int i=0;i<N-1;i++)
typedef unsigned long long int ULL;
typedef long long int LL;
using namespace std;
using namespace tr1;

double tot;
string s[2];
char c;
LL q[2][MAXN];
LL Sq[2][MAXN];
LL sq[MAXN];
LL Ssq[MAXN];
LL N;
double res[26][MAXN];

int main(){
	cin >> N;
	cin >> s[0];
	cin >> s[1];
	tot=(N)*(N+1)*(2*N+1)/6;
	for(int j=0;j<abc;j++){
		c=j+'A';
		//~ cout << endl << c << ": ";
		for(int i=1;i<=N;i++){
			REP{
				q[id][i]=q[id][i-1];
				if(s[id][i-1]==c)q[id][i]++;
			}
		}
		//~ for(int i=0;i<=N;i++)cout << q[0][i] << " ";
		for(int i=0;i<=N;i++)sq[i]=q[0][i]*q[1][i];
		for(int i=N;i>=0;i--){
			REP Sq[id][i]=Sq[id][i+1]+q[id][i];
			Ssq[i]=Ssq[i+1]+sq[i];
			//~ cout <<  Sq[0][i] << " ";
		}
		for(int i=0;i<N;i++) {//posizione i-esima
			LL rex=0;
			rex+=(N-i+1)*sq[i];
			rex+=Ssq[i];
			REP rex-=q[id][i]*Sq[(id+1)%2][i];
			//~ cout << c << " " << i << ": " << rex << endl;
			res[j][i]=double(rex)/tot;
		}
	}
	double result=0;
	for(int j=0;j<abc;j++)for(int i=0;i<N;i++)result+=res[j][i];
	cout.precision(100);
	//~ cout << tot << endl;
	cout << result;
}