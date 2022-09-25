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
		int n,k;
		string s,str1,str2;
		cin >> n >> k >> s;
		int x,y,val;
		vector<pii> ans;
		pii p;
		ans.clear();
		val=0;
		loop(n){
			if(s[i]=='('){
				val++;
				if(val==0){
					str1=s.substr(x,i-x+1);
					loopi(j,str1.size()){
						s[x+j]=str1[i-x-j];
					}
					p.first=x+1;
					p.second=i+1;
					ans.push_back(p);
				}
			}
			else if(s[i]==')'){
				val--;
				if(val==-1) x=i;
			}
		}
		y=0;
		val=0;
		set<int> good;
		set<int>::iterator it;
		good.clear();
		loop(n){
			if(s[i]=='('){
				val++;
			}
			else if(s[i]==')'){
				val--;
				if(val==0){
					y++;
					good.insert(i);
				}
				//cout << "i is " << i << "\n";
			}
		}
		int z,z1;
		while(1){
			if(y==k){
				cout << ans.size() << "\n";
				loop(ans.size()) cout << ans[i].first << " " << ans[i].second << "\n";
				break;
			}
			else if(y>k){
				z=*good.begin();
				swap(s[z],s[z+1]);
				p.first=z+1;
				p.second=z+2;
				ans.push_back(p);
				good.erase(z);
				y--;
			}
			else{
				z=*good.begin();
				it=good.begin();
				//cout << z << "\n";
				if(z==1){
					while(1){
						it++;
						if(*it>z+2){
							z=*it;
							break;
						}
						z=*it;
					}
				}
				z1=z;
				while(1){
					if(s[z1]=='('){
						swap(s[z1],s[z-1]);
						p.first=z1+1;
						p.second=z;
						ans.push_back(p);
						good.insert(z-2);
						break;
					}
					z1--;
				}
				y++;
			}
		}
	}
	return 0;
}