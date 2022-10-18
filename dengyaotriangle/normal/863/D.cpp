#include<bits/stdc++.h>

using namespace std;

const int maxn=200005;

int n,q,m;
int x[maxn];
int t[maxn],l[maxn],r[maxn];
int nq;

int main(){
	cin>>n>>q>>m;
	for(int i=1;i<=n;i++){
		cin>>x[i];
	}
	for(int i=0;i<q;i++){
		cin>>t[i]>>l[i]>>r[i];
	}
	for(int i=0;i<m;i++){
		cin>>nq;
		for(int j=q-1;j>=0;j--){
			//cout<<nq<<endl;
			if(l[j]<=nq&&nq<=r[j]){
				if(t[j]==2) nq=r[j]-nq+l[j];
				if(t[j]==1){
					if(nq==l[j]) nq=r[j];
					else nq--;
				}
			}
		}
		cout<<x[nq]<<' ';
	}
	return 0;
}