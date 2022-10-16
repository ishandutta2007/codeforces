#include<bits/stdc++.h>
using namespace std;
int T,n,a[200003];
int main(){
	cin>>T;
	while(T--){
		cin>>n;
		for(int i=0;i<n;i++)
			cin>>a[i];
		sort(a,a+n);
		int cnt[2]={0,0};
		for(int i=0;i<n;i++){
			int j;
			for(j=i;j<n;j++)
				if(a[i]!=a[j])
					break;
			cnt[min(1,j-i-1)]++;
			i=j-1;
		}
		cout<<(cnt[0]+1)/2+cnt[1]<<endl;
	}
}