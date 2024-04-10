#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1000005;
const ll inf=0x3f3f3f3fll;
const ll mod=998244353ll;
int n,m;
int a[N];
int flag[N];
int b[N];
int main(){
	ios::sync_with_stdio(0);
	int i,j;
	int T;cin>>T;
	while(T--){
		cin>>n;
		int len=0;
		for(i=1;i<=n;i++){
			cin>>a[i];
			if(flag[a[i]]==1){
				b[++len]=a[i];
				flag[a[i]]=0;
			}
			else if(flag[a[i]]==0) flag[a[i]]=1;
		}
		sort(b+1,b+len+1);
		int mna=1,mnb=100000000;
		for(i=1;i<len;i++){
			if(double(b[i+1])/b[i]<double(mnb)/mna){
				mnb=b[i+1];
				mna=b[i];
			}
		}
		cout<<mna<<" "<<mna<<" "<<mnb<<" "<<mnb<<endl;
		for(i=1;i<=n;i++) flag[a[i]]=0;
	}
	return 0;
}