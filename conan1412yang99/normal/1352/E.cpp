#include <bits/stdc++.h>

using namespace std;

int main(){
	int t;
	cin>>t;
	while(t--){
		int n , cnt = 0;
		cin>>n;
		vector<int> a(n) , cc(n + 1);
		for(int i = 0 ; i < n ; i++) cc[i] = 0;
		for(int i = 0 ; i < n ; i++) cin>>a[i];
		for(int i = 0 ; i < n - 1 ; i++){
			int ccc = a[i];
			for(int tt = i + 1 ; tt < n ; tt++){
				ccc+=a[tt];
				if(ccc <= n)cc[ccc] = 1;
			}
		}
		for(int i = 0 ; i < n ; i++) if(cc[a[i]] == 1) cnt++;
		cout<<cnt<<endl;
	}
}