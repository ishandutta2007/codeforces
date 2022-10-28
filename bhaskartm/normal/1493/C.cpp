#include <bits/stdc++.h>
using namespace std;
#pragma optimize("-O3")

#define f first
#define s second
#define pb push_back
#define endl '\n'
const int N=1e5+5;

int num[N][26];


 
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t;
	cin>>t;
	while(t--){
		int n, k;
		cin>>n>>k;
		string st;
		cin>>st;
		if(n%k!=0){
			cout<<-1<<endl;
			continue;
		}
		for(int i=0; i<=n; i++){
			for(int j=0; j<26; j++){
				num[i][j]=0;
			}
		}
		num[1][st[0]-'a']++;
		for(int i=1; i<n; i++){
			for(int j=0; j<26; j++){
				num[i+1][j]=num[i][j];
			}
			num[i+1][st[i]-'a']++;
		}
		bool che=1;
		for(int i=0; i<26; i++){
			if(num[n][i]%k!=0){
				che=0;
			}
		}
		if(che){
			cout<<st<<endl;
			continue;
		}
		vector<int>fin;
		bool don=0;
		for(int i=n-1; i>=0; i--){
			if(don){
				break;
			}
			int val=st[i]-'a';
			for(int j=val+1; j<26; j++){
				if(don){
					break;
				}
				int add=0;
				num[i][j]++;
				for(int j2=0; j2<26; j2++){
					if(num[i][j2]%k!=0){
						add+=(k-(num[i][j2]%k));	
					}	
				}
				if(add>n-i-1){
					num[i][j]--;
					continue;
				}
				vector<int>vec;
				for(int j2=0; j2<26; j2++){
					if(num[i][j2]%k!=0){
						int rem=(k-(num[i][j2]%k));
						while(rem){
							vec.pb(j2);
							rem--;
						}
					}
				}
				int rem=(n-i-1)-vec.size();
				
				while(rem){
					vec.pb(0);
					rem--;
				}
				
				sort(vec.begin(), vec.end());
				for(int j2=0; j2<i; j2++){
					fin.pb(st[j2]-'a');
				}
				fin.pb(j);
				for(auto u:vec){
					fin.pb(u);
				}
				don=1;
				if(don){
					break;
				}
			}
			if(don){
				break;
			}
		}
		for(auto u:fin){
			cout<<char(u+'a');
		}
		cout<<endl;
	}
	
	return 0;
}