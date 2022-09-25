#include <bits/stdc++.h>
 
#define ll long long
#define loop(a) loopi(i,a)
#define loopi(i,a) for(int i=0; i<a; i++)
#define pii pair<int,int>
#define pll pair<ll,ll>
 
using namespace std;
 
const int mod=1e9+7;
const int maxn=100005;
 
int main(){
	ios_base::sync_with_stdio(0),cin.tie(0);
	int t;
	cin >> t;
	loopi(noob,t){
		int n;
		cin >> n;
		string str[n];
		loop(n) cin >> str[i];
		set<string> s,s1;
		s.clear();
		loop(n) s.insert(str[i]);
		s1.clear();
		string str1;
		bool boo=false;
		int ans=n-s.size();
		loop(n){
			if(s1.count(str[i])==1){
				loopi(k,4){
					str1=str[i];
					loopi(j,10){
						str1[k]=char(48+j);
						if(s.count(str1)==0){
							s.insert(str1);
							s1.insert(str1);
							str[i]=str1;
							boo=true;
							break;
						}
					}
					if(boo) break;
				}
			}
			else s1.insert(str[i]);
		}
		cout << ans << "\n";
		loop(n) cout << str[i] << "\n";
	}
	return 0;
}