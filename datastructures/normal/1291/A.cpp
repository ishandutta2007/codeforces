#include <iostream>
#include <cstdio> 
#include <algorithm>
#include <cstring>
#include <cmath>
#include <vector>
using namespace std;
int t,n;
string s;
signed main(){
//	freopen("a.in","r",stdin);
//	freopen("a.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n;
		cin>>s;
		int x=0,tot=0;
		for (int i=0;i<s.size();i++)
			if ((s[i]-'0')%2==1)tot++;
		if (tot>=2){
			for (int i=0;i<s.size();i++){
				if ((s[i]-'0')%2==1){
					x++;
					if (x>2)break;
					cout<<s[i];
				}
			}
			cout<<endl;
		}
		else cout<<-1<<endl;
	}
	return 0;
}