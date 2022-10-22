#include <bits/stdc++.h> 
using namespace std;
int n,s,now,a[100004];
long long cnt;
int main(){
	int T;cin>>T;
	while (T--){
		cnt=0;
		cin>>n>>s;
		for (int i=1;i<=n;i++) scanf("%d",&a[i]),cnt+=a[i]; 
		if (cnt<=s){
			puts("0");continue;
		}
		int maxn=0,wic,go;
		cnt=0;
		for (int i=1;i<=n;i++){
			cnt+=a[i];
			if (a[i]>maxn){
				maxn=a[i];
				wic=i;
			}
			if (cnt-maxn<=s) go=wic;
		}
		cout<<go<<"\n";
	}
}