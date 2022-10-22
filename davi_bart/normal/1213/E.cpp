#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
int main(){
		ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
		int N;
		string a,b;
		cin>>N>>a>>b;
		cout<<"YES"<<endl;
		if(a[0]==b[0] && !(a[0]==a[1] || b[0]==b[1])){
			for(int i=0;i<N;i++)if(a[0]!='a')cout<<'a';
			for(int i=0;i<N;i++)if(a[0]!='b')cout<<'b';
			for(int i=0;i<N;i++)if(a[0]!='c')cout<<'c';
			for(int i=0;i<N;i++)cout<<a[0];
			return 0;
		}
		if(a[1]==b[1] && !(a[0]==a[1] || b[0]==b[1])){
			for(int i=0;i<N;i++)cout<<a[1];
			for(int i=0;i<N;i++)if(a[1]!='a')cout<<'a';
			for(int i=0;i<N;i++)if(a[1]!='b')cout<<'b';
			for(int i=0;i<N;i++)if(a[1]!='c')cout<<'c';
			return 0;
		}
		if(a[0]==b[1] && a[1]==b[0] && a[0]!=a[1]){
      for(int i=0;i<N;i++)cout<<a[1];
			for(int i=0;i<N;i++)if(a[1]!='a' && a[0]!='a')cout<<'a';
			for(int i=0;i<N;i++)if(a[1]!='b'&& a[0]!='b')cout<<'b';
			for(int i=0;i<N;i++)if(a[1]!='c'&& a[0]!='c')cout<<'c';
      for(int i=0;i<N;i++)cout<<a[0];
      return 0;
		}
		vector<char> p;
		p.push_back('a');p.push_back('b');p.push_back('c');
		for(int i=0;i<10;i++){
			if((a[1]!=p[1] || a[0]!=p[0]) &&(a[1]!=p[2] || a[0]!=p[1]) &&(a[1]!=p[0] || a[0]!=p[2]) &&(b[1]!=p[1] || b[0]!=p[0]) &&(b[1]!=p[2] || b[0]!=p[1]) &&(b[1]!=p[0] || b[0]!=p[2])){
				for(int i=0;i<N;i++){
					cout<<p[0]<<p[1]<<p[2];
				}
				return 0;
			}
			next_permutation(p.begin(),p.end());
		}
		return 0;
}