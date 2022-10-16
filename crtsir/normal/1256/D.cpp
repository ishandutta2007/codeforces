#include<bits/stdc++.h>
using namespace std;
long long T,n,k;
string s;
int main(){
	cin>>T;
	while(T--){
		cin>>n>>k>>s;
		long long i=1,last=(s[0]=='0')?0:-1;
		while(k>0&&i!=n){
			if(s[i]=='0'){
				if(s[i-1]=='1')
					if(k>=i-last-1)
						swap(s[last+1],s[i]);
					else
						swap(s[i-k],s[i]);
				k-=(i-last-1);
				last++;
			}
			i++; 
		}
		cout<<s<<endl;
	}
}