#include <bits/stdc++.h>
 
#define ll long long
#define loop(a) loopi(i,a)
#define loopi(i,a) for(int i=0; i<a; i++)
#define pii pair<int,int>
#define pll pair<ll,ll>
 
using namespace std;
 
const int Mod=1e9+7;
 
int main(){
	ios_base::sync_with_stdio(0),cin.tie(0);
	int q;
	cin >> q;
	loopi(noob,q){
		string str,ans;
		cin >> str;
		int r,l,u,d;
		r=l=u=d=0;
		loop(str.size()){
			if(str[i]=='R') r++;
			else if(str[i]=='D') d++;
			else if(str[i]=='U') u++;
			else if(str[i]=='L') l++;
		}
		int len,wid;
		len=min(l,r);
		wid=min(u,d);
		if(len==0) wid=min(wid,1);
		if(wid==0) len=min(len,1);
		cout << len*2+wid*2 << "\n";
		loop(len) cout << 'R';
		loop(wid) cout << 'U';
		loop(len) cout << 'L';
		loop(wid) cout << 'D';
		cout << "\n";
	}
	return 0;
}