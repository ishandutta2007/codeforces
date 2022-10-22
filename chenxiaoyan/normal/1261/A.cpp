/*




D P 




 l l
*/
#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define X first
#define Y second
const int N=2000;
int n,m;
char a[N+1];
char b[N+1];
void mian(){
	cin>>n>>m>>a+1;
	memset(b,0,sizeof(b));
	for(int i=1;i<m;i++)b[2*i-1]='(',b[2*i]=')';
	for(int i=2*m-1;i<=2*m-2+n>>1;i++)b[i]='(';
	for(int i=(2*m-2+n>>1)+1;i<=n;i++)b[i]=')';
//	printf("b=%s\n",b+1);
	vector<pair<int,int> > ans;
	for(int i=1;i<=n;i++)if(a[i]!=b[i]){
		int fst;
		for(int j=i+1;j<=n;j++)if(a[j]==b[i]){fst=j;break;}
		ans.pb(mp(i,fst));
		reverse(a+i,a+fst+1);
	}
//	printf("a=%s\n",a+1);
	cout<<ans.size()<<"\n";
	for(int i=0;i<ans.size();i++)cout<<ans[i].X<<" "<<ans[i].Y<<"\n";
}
int main(){
	int testnum;
	cin>>testnum;
	while(testnum--)mian();
	return 0;
}
/*1
4
8 2
()(())()
10 3
))()()()((
2 1
()
2 1
)(
*/