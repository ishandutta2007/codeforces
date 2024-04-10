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
		int n;
		cin>>n;
		string a, b;
		cin>>a>>b;
		bool che=1;
		for(int i=0; i<n; i++){
			if(a[i]-'a'>b[i]-'a'){
				che=0;
				break;
			}
		}
		if(che==0){
			cout<<-1<<endl;
			continue;
		}
		int cnt[20][20];
		int ans=0;
		for(int i=0; i<20; i++){
			for(int j=0; j<20; j++){
				cnt[i][j]=0;
			}
		}
		for(int i=0; i<n; i++){
			cnt[int(a[i]-'a')][int(b[i]-'a')]=1;
		}
		for(int i=0; i<20; i++){
			for(int j=i+1; j<20; j++){
				if(cnt[i][j]){
					che=0;
					ans++;
					for(int k=j; k<20; k++){
						if(cnt[i][k]){
							cnt[j][k]=1;
						}
					}
					break;
				}
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}