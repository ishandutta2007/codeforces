#include<bits/stdc++.h>
using namespace std;
int t;string a,b,c;
int main(){
	scanf("%d",&t);
	while(t--){
		cin>>a;
		sort(a.begin(),a.end());
		b.clear();c.clear();
		for(int i=0;i<a.size();i++){
			if(a[i]&1)b+=a[i];
			else c+=a[i];
		}
		if(!b.size())cout<<c<<endl;
		else if(!c.size())cout<<b<<endl;
		else if(abs(b[0]-c[c.size()-1])!=1)cout<<c<<b<<endl;
		else if(abs(c[0]-b[b.size()-1])!=1)cout<<b<<c<<endl;
		else puts("No answer");
	}
	return 0;
}