#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <cmath>
#define MAXN 200
using namespace std;

int a,b;
string SS;
int S[MAXN];
int N;

int dx[4]={0,0,-1,1};
int dy[4]={1,-1,0,0};

int f(char A){
	if(A=='U')return 0;
	if(A=='D')return 1;
	if(A=='L')return 2;
	if(A=='R')return 3;
	return -1;
}

int calcola(int x, int y){
	if(x==0 and y==0)return -1;
	if(x==0 and y!=0)return -2;
	if(y%x!=0)return -2;
	if(y/x<0)return -2;
	return y/x;
}

int main(){
	cin >> a >> b;
	cin >> SS;
	N=SS.size();
	for(int i=0;i<N;i++)S[i]=f(SS[i]);
	int u=0,v=0;
	for(int i=0;i<N;i++)u+=dx[S[i]], v+=dy[S[i]];
	int x=0,y=0;
	for(int i=0;i<N;i++){
		int ar=a-x;
		int br=b-y;
		int rap1=calcola(u,ar);
		int rap2=calcola(v,br);
		
		if(rap1!=-2 and rap2!=-2){
			if(rap1==rap2 or rap1==-1 or rap2==-1){
				cout << "Yes\n";
				return 0;
			}
		}
		
		x+=dx[S[i]];
		y+=dy[S[i]];
	}
	cout << "No\n";
}