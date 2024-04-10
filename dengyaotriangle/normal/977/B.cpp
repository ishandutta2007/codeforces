#include<iostream>

using namespace std;

const int maxn=105;

char x[maxn];

int n;

int frq['Z']['Z'];
int maxf,mi,mj;

int main(){
	cin>>n;
	cin>>x;
	for(int i=0;i<n-1;i++) frq[x[i]-'A'][x[i+1]-'A']++;
	for(int i=0;i<'Z';i++){
		for(int j=0;j<'Z';j++){
			if(frq[i][j]>maxf){
				maxf=frq[i][j];
				mi=i;
				mj=j;
			}
		}
	}
	cout<<(char)(mi+'A')<<(char)(mj+'A');
	return 0;
}