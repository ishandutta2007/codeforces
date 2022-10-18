#include<bits/stdc++.h>

using namespace std;

const int maxn =105;

int n,k;
bool vis[maxn];
int cl,cp;
int a;

int main(){
	cin>>n>>k;
	cl=n;
	for(int i=0;i<k;i++){
		cin>>a;
		a=a%cl;
		for(int j=0;j<a;j++){
			cp++;
			if(cp==n) cp=0;
			while(vis[cp]){
				cp++;
				if(cp==n) cp=0;
			}
		}
		vis[cp]=1;
		cout<<cp+1<<' ';
		cp++;
		if(cp==n) cp=0;
		while(vis[cp]){
			cp++;
			if(cp==n) cp=0;
		}
		cl--;
	}
	return 0;
}