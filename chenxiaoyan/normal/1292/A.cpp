/*




D P 




 l l
*/
#include<bits/stdc++.h>
using namespace std;
#define mp make_pair
const int N=100000;
int n,qu;
bool a[2][N+1];
set<pair<int,int> > s;
void erase(pair<int,int> x){
	set<pair<int,int> >::iterator fd=s.find(x);
	if(fd!=s.end())s.erase(fd);
}
int main(){
	cin>>n>>qu;
	while(qu--){
		int x,y;
		cin>>x>>y;
		a[x-1][y]^=1;
		x=y;
		if(a[0][x]&&a[1][x])s.insert(mp(x,0));
		if(x>1&&(a[0][x-1]&&a[1][x]||a[1][x-1]&&a[0][x]))s.insert(mp(x-1,x));
		if(x<n&&(a[0][x+1]&&a[1][x]||a[1][x+1]&&a[0][x]))s.insert(mp(x,x+1));
		if(!(a[0][x]&&a[1][x]))erase(mp(x,0));
		if(!(x>1&&(a[0][x-1]&&a[1][x]||a[1][x-1]&&a[0][x])))erase(mp(x-1,x));
		if(!(x<n&&(a[0][x+1]&&a[1][x]||a[1][x+1]&&a[0][x])))erase(mp(x,x+1));
		puts(s.size()?"No":"Yes");
	}
	return 0;
}