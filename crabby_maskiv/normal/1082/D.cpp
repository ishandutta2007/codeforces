#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=505;
const ll mod=998244353ll;
const ll inf=0x3f3f3f3f3f3f3f3fll;
int n,m;
int a[N]; 
int main(){
    int i,j;
    cin>>n;
    int sum=0;
    int flag1=0,flag0=0;
    int cnt=0;
    for(i=1;i<=n;i++){
    	cin>>a[i];
    	sum+=a[i];
    	cnt+=a[i]>1;
    	if(a[i]==1&&!flag1) flag1=i;
    	if(a[i]==1) flag0=i;
	}
	if(sum<2*(n-1)){
		cout<<"NO";
		return 0;
	}
	cout<<"YES "<<cnt+(flag1?(flag1==flag0?1:2):0)-1<<endl;
	cout<<n-1<<endl;
	int last=0;
	for(i=1;i<=n;i++){
		if(i!=last&&a[i]>1){
			if(!last&&flag1) cout<<flag1<<" "<<i<<endl;
			if(last) cout<<i<<" "<<last<<endl;
			last=i;
		}
	}
	if(flag1!=flag0) cout<<last<<" "<<flag0<<endl;
	vector<int> v;
	for(i=1;i<=n;i++){
		if(a[i]>1) v.push_back(i);
	}
	int pos=0;
	for(i=1;i<=n;i++){
		if(i==flag1||i==flag0||a[i]>1) continue;
		while(a[v[pos]]==2) pos++;
		a[v[pos]]--;
		cout<<i<<" "<<v[pos]<<endl;
	}
    return 0;
}