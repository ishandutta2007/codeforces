#include <bits/stdc++.h>
using namespace std;

#pragma optimize("-O3")
 
#define pb push_back
#define f first
#define s second
#define endl '\n'



int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t;
	cin>>t;
	while(t--){
		string s;
		cin>>s;
		int n=s.size();
		int arr[n];
		int cnt[10];
		for(int i=0; i<10; i++){
			cnt[i]=0;
		}
		int maxi=0;
		for(int i=0; i<n; i++){
			arr[i]=int(s[i]-'0');
			cnt[arr[i]]++;
			maxi=max(maxi, cnt[arr[i]]);
		}
		for(int i=0; i<=9; i++){
			for(int j=0; j<=9; j++){
				if(i==j){
					continue;
				}
				bool b=0;
				int num=0;
				for(int k=0; k<n; k++){
					if(b==0 && arr[k]==i){
						num++;
						b=1;
						continue;
					}
					if(b==1 && arr[k]==j){
						num++;
						b=0;
						continue;
					}
				}
				num=(num/2)*2;
				maxi=max(maxi, num);
			}
		}
		cout<<n-maxi<<endl;
	}
	return 0;
}