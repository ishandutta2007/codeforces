#include <bits/stdc++.h>
 
#define ll long long
#define loop(a) loopi(i,a)
#define loopi(i,a) for(int i=0; i<a; i++)
#define pll pair<ll,ll>
 
using namespace std;

const int mod=1e9+7;
const int maxn=200005;

int main(){
	ios_base::sync_with_stdio(0),cin.tie(0);
	int t,n,num;
	string str;
	cin >> t;
	bool boo;
	loopi(ahlfai,t){
		cin >> n;
		num=0;
		boo=false;
		loop(n){
			cin >> str;
			if(str.size()%2==1){
				boo=true;
			}
			loopi(j,str.size()) if(str[j]=='1') num++;
		}
		if(boo||num%2==0) cout << n << "\n";
		else cout << n-1 << "\n";
	}
	return 0;
}