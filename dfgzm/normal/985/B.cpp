#include<bits/stdc++.h>
using namespace std;
const int maxn=2010;
int i,j,k,n,m,a[maxn];
string S[maxn];
int main(){
	cin>>n>>m;
	for(i=1;i<=n;i++){
		cin>>S[i];
		for(j=0;j<m;j++)
			if(S[i][j]-'0')a[j+1]++;
	}
	for(i=1;i<=n;i++){
		bool B=true;
		for(j=0;j<m;j++){
			if(a[j+1]-(S[i][j]-'0')==0)B=false;
		}if(B){
			puts("YES");
			return 0;
		}
	}puts("NO");
}