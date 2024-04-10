#include<bits/stdc++.h>
using namespace std;
int n,a[100004],b[100004];
set<int>st;
int main(){
	cin>>n;for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	for(int i=0;i<=1e6;i++)st.insert(i);
	memset(b,-1,sizeof(b));
	for(int i=n;i>=2;i--){
		if(a[i]!=a[i-1])b[i]=a[i-1],st.erase(st.find(b[i]));
	}
	for(int i=1;i<=n;i++)
		if(a[i]>i){
			puts("-1");return 0;
		}
	st.erase(a[n]);
	for(int i=1;i<=n;i++){
		if(b[i]>=0)continue;
		b[i]=(*(st.begin()));st.erase(st.begin());
	}
	for(int i=1;i<=n;i++)cout<<b[i]<<" ";
}