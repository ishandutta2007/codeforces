#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
#include <string>
#include <iostream>
#define MAXN 1100000
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;

LL N,K;
char s[MAXN];
bool fatti[MAXN];
LL quanti=0;

bool mossa(int i){
	if(i<N-1 and s[i]=='4' and s[i+1]=='7'){
		if(i%2==0)s[i+1]='4';
		else s[i]='7';
		return true;
	}
	return false;
}

int main(){
	cin >> N;
	cin >> K;
	cin >> s;
	for(int i=0;i<N-1;i++){
		if(quanti==K)break;
		if(mossa(i)){
			quanti++;
			if(fatti[i]){
				if((quanti-K)%2==0)break;
				else if(i>0)i-=2;
			}
			else{
				fatti[i]=true;
				if(i>0)i-=2;
			}
		}
	}
	cout << s;
}