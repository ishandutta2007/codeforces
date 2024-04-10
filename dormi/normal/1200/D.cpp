#include<bits/stdc++.h>

using namespace std;
typedef long long int lli;
typedef pair<int, int> pii;
typedef pair<lli, lli> pll;

int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	int n,k;
	cin>>n>>k;
	string a[n];
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	int prearr[n][n];
	memset(prearr,0, sizeof(prearr));
	int ans=0;
	for(int i=0;i<n;i++){
		int mi=INT_MAX;
		int ma=-1;
		for(int j=0;j<n;j++){
			if(a[i][j]=='B') {
				mi = min(mi,j);
				ma = max(ma,j);
			}
		}
		if(mi<=ma){
			if(ma-mi+1<=k){
				prearr[max(0,i-k+1)][max(0,ma-k+1)]+=1;
				if(mi+1<n)prearr[max(0,i-k+1)][mi+1]-=1;
				if(i+1<n)prearr[i+1][max(0,ma-k+1)]-=1;
				if(mi+1<n&&i+1<n)prearr[i+1][mi+1]+=1;
			}
		}
		else{
			ans+=1;
		}
		mi=INT_MAX;
		ma=-1;
		for(int j=0;j<n;j++){
			if(a[j][i]=='B') {
				mi = min(mi,j);
				ma = max(ma,j);
			}
		}
		if(mi<=ma){
			if(ma-mi+1<=k){
				prearr[max(0,ma-k+1)][max(0,i-k+1)]+=1;
				if(mi+1<n)prearr[mi+1][max(0,i-k+1)]-=1;
				if(i+1<n)prearr[max(0,ma-k+1)][i+1]-=1;
				if(mi+1<n&&i+1<n)prearr[mi+1][i+1]+=1;
			}
		}
		else{
			ans+=1;
		}
	}
	int fin=0;
	for(int i=0;i<n-k+1;i++){
		for(int j=0;j<n-k+1;j++){
			prearr[i][j]+=(i-1>=0?prearr[i-1][j]:0)+(j-1>=0?prearr[i][j-1]:0)-((i-1>=0&&j-1>=0)?prearr[i-1][j-1]:0);
			fin=max(prearr[i][j],fin);
		}
	}
	printf("%d\n",fin+ans);
	return 0;
}