#include<bits/stdc++.h>
using namespace std;
const int N=3000;
int n,p[N];
int ans[N][N];
int ask(int x,int y){
	assert(x!=y);
	if(ans[x][y]!=-1)return ans[x][y];
	if(ans[y][x]!=-1)return ans[y][x];
	cout<<'?'<<' '<<x<<' '<<y<<endl;cout.flush();
	cin>>ans[x][y];return ans[x][y];
}
int arr[N];
signed main(){
	srand('S'+'J'+'Y'+'A'+'K'+'I'+'O'+'I');
	memset(ans,-1,sizeof ans);
	cin>>n;
	for(int i=1;i<=n;i++)p[i]=i;
	random_shuffle(p+1,p+1+n);
	int a=p[1],b=p[2],v=ask(a,b);
	for(int i=3;i<=n;i++){
		int c=p[i],_=ask(a,c);
		if(v<_)continue;
		else if(v==_)
			a=c,v=ask(a,b);
		else if(v>_)
			b=c,v=_;
	}
	random_shuffle(p+1,p+1+n);
	int z;
	for(int i=1;i<=n;i++){
		if(p[i]==a||p[i]==b)continue;
		int va=ask(p[i],a),vb=ask(p[i],b);
		if(va!=vb){
			z=va<vb?a:b;
			break;
		}
	}
	for(int i=1;i<=n;i++)
		arr[i]=(i==z?0:ask(i,z));
	cout<<'!'<<' ';
	for(int i=1;i<=n;i++)
		cout<<arr[i]<<' ';
	cout<<endl;cout.flush();
}