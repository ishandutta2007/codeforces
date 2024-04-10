#include<bits/stdc++.h>

using namespace std;

const int maxn=60;

int n,k;
char x[maxn];
int ans=0;

int main(){
	cin>>n>>k;
	cin>>x;
	sort(x,x+n);
	char minp='a';
	int csn=0;
	for(int i=0;i<n;i++){
		if(x[i]>=minp){
			csn++;
			ans+=x[i]+1-'a';
			minp=x[i]+2;
		}
		if(csn==k){
			cout<<ans;
			return 0;
		}
	}
	cout<<-1;
	return 0;
}