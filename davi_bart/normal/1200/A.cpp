#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
set<int> sx;
set<int> dx;
bool p[20];
int main(){
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
		ios_base::sync_with_stdio(0);
		int N;
		cin>>N;
		for(int i=0;i<10;i++){
			sx.insert(i);
			dx.insert(-i);
		}
		string a;
		cin>>a;
		for(int i=0;i<N;i++){
			if(a[i]=='L'){
				for(int x:sx){
					sx.erase(x);
					p[x]=1;
					dx.erase(-x);
					break;
				}
				continue;
			}
			if(a[i]=='R'){
				for(int x:dx){
					sx.erase(-x);
					p[-x]=1;
					dx.erase(x);
					break;
				}
				continue;
			}
			int o=a[i]-'0';
			p[o]=0;
			sx.insert(o);
			dx.insert(-o);
		}
		for(int i=0;i<10;i++)cout<<p[i];
		return 0;
}