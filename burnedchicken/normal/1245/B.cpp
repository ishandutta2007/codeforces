#include <bits/stdc++.h>
 
#define ll long long
#define loop(a) loopi(i,a)
#define loopi(i,a) for(ll i=0; i<a; i++)
#define pll pair<ll,ll>
 
using namespace std;

int main(){
	ios_base::sync_with_stdio(0),cin.tie(0);
	ll t,n,a,b,c,d,e,f,ans,x;
	cin >> t;
	string s;
	loop(t){
		cin >> n >> a >> b >> c >> s;
		d=e=f=0;
		loopi(j,n){
			if(s[j]=='R') d++;
			else if(s[j]=='P') e++;
			else f++;
		}
		ans=min(a,f)+min(b,d)+min(c,e);
		if(n%2==0) x=n/2;
		else x=n/2+1;
		if(ans<x) cout << "NO" << endl;
		else{
			cout << "YES" << endl;
			loopi(j,n){
				if(s[j]=='R'){
					d--;
					if(b>0){
						cout << 'P';
						b--;
					}
					else if(a-f>0){
						cout << 'R';
						a--;
					}
					else{
						cout << 'S';
						c--;
					}
				}
				else if(s[j]=='P'){
					e--;
					if(c>0){
						cout << 'S';
						c--;
					}
					else if(b-d>0){
						cout << 'P';
						b--;
					}
					else{
						cout << 'R';
						a--;
					}
				}
				else{
					f--;
					if(a>0){
						cout << 'R';
						a--;
					}
					else if(c-e>0){
						cout << 'S';
						c--;
					}
					else{
						cout << 'P';
						b--;
					}
				}
			}
			cout << endl;
		}
	}
	return 0;
}