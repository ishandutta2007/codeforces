#include<iostream>

using namespace std;

const int maxn=105;

int n,m;
int x[maxn];

int main(){
    for(int i=0;i<maxn;i++) x[i]=0;
	cin>>n>>m;
	for(int i=0;i<m;i++){
		int tmp;
		cin>>tmp;
		x[tmp]++;
	}
	int ans=0;
	for(int i=1;i<maxn*maxn;i++){
		int c=i;
		int tot=0;
		for(int j=1;j<maxn;j++){
			tot+=x[j]/i;
		}
		if(tot>=n) ans=i;
	}
	cout<<ans;
	return 0;
}