#include <iostream>
#include <fstream>
#define MAXN 5010
using namespace std;

int N;
string S;
int nim[MAXN]={0,1,1,2};
bool xx[16];

int main(){
	cin >> S;
	N=S.size();
	for(int l=4;l<=N;l++){
		for(int i=0;i<16;i++)xx[i]=0;
		xx[nim[l-2]]=1;
		for(int i=1;i<=l/2;i++)xx[nim[i-1]^nim[l-2-i]]=1;
		while(xx[nim[l]])nim[l]++;
		//~ cout << l << ": " << nim[l] << "\n";
	}
	int axel=0;
	for(int i=1;i<N-1;i++){
		int j=i;
		while(j<N-1 and S[j-1]==S[j+1])j++;
		axel^=nim[(j-i)];
		i=j;
	}
	if(axel==0){
		cout << "Second\n";
		return 0;
	}
	cout << "First\n";
	for(int i=1;i<N-1;i++){
		int j=i;
		while(j<N-1 and S[j-1]==S[j+1])j++;
		int l=j-i;
		int t=axel^nim[l];
		for(int a=0;a<l;a++)if( (nim[max(0,a-1)]^nim[max(0,l-2-a)]) ==t ){
			cout << i+a+1 << "\n";
			return 0;
		}
		i=j;
	}
}