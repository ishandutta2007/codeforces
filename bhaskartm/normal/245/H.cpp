#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
const int N=5005;
int num[N][N];
bool is[N][N];
string s;
int q;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin>>s;
	int n=s.size();
	
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			num[i][j]=0;
			is[i][j]=0;
		}
	}
	for(int i=0; i<n; i++){
		num[i][i]=1;
		is[i][i]=1;
	}
	for(int i=0; i<n-1; i++){
		if(s[i]==s[i+1]){
			num[i][i+1]=3;
			is[i][i+1]=1;
		}
		else{
			num[i][i+1]=2;
			is[i][i+1]=0;
		}
	}
	for(int l=3; l<=n; l++){
		for(int i=0; i<=n-l; i++){
			is[i][i+l-1]=((s[i]==s[i+l-1]) & is[i+1][i+l-2]);
			num[i][i+l-1]=num[i][i+l-2]+num[i+1][i+l-1]-num[i+1][i+l-2];
			if(is[i][i+l-1]){
				num[i][i+l-1]++;
			}
		}
	}
	
	cin>>q;
	while(q--){
		int l, r;
		cin>>l>>r;
		l--;
		r--;
		cout<<num[l][r]<<endl;
	}
	return 0;
}