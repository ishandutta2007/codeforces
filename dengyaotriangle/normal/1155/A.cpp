#include<bits/stdc++.h>

using namespace std;

const int maxn=300005;


int n;
char s[maxn];
int mxx=0,mxi=-1;

int main(){
	cin>>n>>(s+1);
	for(int i=1;i<=n;i++){
		if(s[i]<mxx){
			cout<<"YES"<<endl<<mxi<<' '<<i;
			return 0;
		}
		if(s[i]>mxx){
			mxx=s[i];
			mxi=i;
		}
	}
	cout<<"NO";
	return 0;
}