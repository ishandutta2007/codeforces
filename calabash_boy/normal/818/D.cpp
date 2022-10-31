#include<bits/stdc++.h>
using namespace std;
#define MAXN 1000005
int m,n,a; 
int cnt [MAXN];
int main(){
	cin>>n>>a;
	for (int i=0;i<n;i++){
		int temp ;
		cin>>temp;
		if (temp == a){
			cnt[temp]++;
		}else {
			if (cnt[temp]>=cnt[a]){
				cnt[temp]++;
			}
		}
	}
	for (int i=1;i<MAXN;i++){
		if (i!=a&&cnt[i]>=cnt[a]){
			cout<<i<<endl;
			return 0;
		}
	}
	cout<<"-1"<<endl;
	return 0;
}