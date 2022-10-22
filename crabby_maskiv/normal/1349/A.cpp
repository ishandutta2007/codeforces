#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=200005;
const ll mod=99824353;
const int inf=0x3f3f3f3f;
int n,m;
int a[N],mn1[N],mn2[N];
int occ[N];
int main(){
	ios::sync_with_stdio(0);
	int i,j;
	cin>>n;
	memset(mn1,0x3f,sizeof(mn1));
	memset(mn2,0x3f,sizeof(mn2));
	for(i=1;i<=n;i++){
		cin>>a[i];
		for(j=2;j*j<=a[i];j++){
			int cnt=0;
			if(a[i]%j==0)
				occ[j]++;
			else continue;
			while(a[i]%j==0){
				cnt++;
				a[i]/=j;
			}
			if(cnt<=mn1[j]){
				mn2[j]=mn1[j];
				mn1[j]=cnt;
			}
			else if(cnt<mn2[j])
				mn2[j]=cnt;
		}
		if(a[i]>1){
			occ[a[i]]++;
			if(1<=mn1[a[i]]){
				mn2[a[i]]=mn1[a[i]];
				mn1[a[i]]=1;
			}
			else if(1<mn2[a[i]])
				mn2[a[i]]=1;
		}
	}
	ll ans=1;
	for(i=1;i<N;i++){
		if(occ[i]<n-1) continue;
		else if(occ[i]==n-1){
			while(mn1[i]--)
				ans*=i;
		}
		else{
			while(mn2[i]--)
				ans*=i;			
		}
	}
	cout<<ans;
	return 0;
}