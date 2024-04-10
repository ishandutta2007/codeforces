#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=2.5e5+5;
int n,m;
vector<int> a[N],b[N],pre[N],suf[N];
int mx[N],cnt[N];
int f[N],ans[N];
int x[N],len;
void print(){
	int i,j;
	cout<<"Yes"<<endl;
	for(i=1;i<=m;i++) cout<<x[ans[i]]<<" ";
	exit(0);
}
vector<int> t;
void chk3(int x,int y,int z){
	x=t[x-1];y=t[y-1];z=t[z-1];
	int i,j;
	for(i=1;i<=m;i++) ans[i]=mx[i];
	ans[x]=a[1][x];
	for(i=2;i<=n;i++) if(a[i][x]!=a[1][x]) break;
	ans[y]=a[i][y];ans[z]=0;
	for(i=1;i<=n;i++){
		if(a[i][x]!=ans[x]&&a[i][y]!=ans[y]){
			if(ans[z]==0||ans[z]==a[i][z]) ans[z]=a[i][z];
			else return;
		}
	}
	print();
}
int main(){
	ios::sync_with_stdio(0);
	srand((unsigned)time(NULL));
	int i,j,k;
	cin>>n>>m;
	for(i=0;i<=n+2;i++){
		a[i].resize(m+2);
		b[i].resize(m+2);
		pre[i].resize(m+2);suf[i].resize(m+2);
	}
	for(i=1;i<=n;i++)
		for(j=1;j<=m;j++){
			cin>>a[i][j];
			x[++len]=a[i][j];
		}
	sort(x+1,x+len+1);
	len=unique(x+1,x+len+1)-(x+1);
	for(i=1;i<=n;i++)
		for(j=1;j<=m;j++)
			a[i][j]=lower_bound(x+1,x+len+1,a[i][j])-x;
	x[0]=1;
	for(i=1;i<=m;i++){
		for(j=1;j<=n;j++){
			cnt[a[j][i]]++;
			if(cnt[a[j][i]]>cnt[mx[i]]) mx[i]=a[j][i];
		}
		if(cnt[mx[i]]!=n) t.push_back(i);
		for(j=1;j<=n;j++) cnt[a[j][i]]--;
	}
	if(t.size()<=2){
		for(i=1;i<=m;i++) ans[i]=mx[i];
		print();
		return 0;
	}
	if(t.size()==3){
		chk3(1,2,3);chk3(1,3,2);chk3(2,1,3);chk3(2,3,1);chk3(3,1,2);chk3(3,2,1);
		cout<<"No";
		return 0;
	}
	t.resize(4);
	double S=clock();
	for(auto pos:t){
		for(i=1;i<=m;i++) ans[i]=0;
		ans[pos]=mx[pos];
		for(i=1;i<=n;i++)
			if(a[i][pos]!=ans[pos]) break;
		int row=i;
		for(i=1;i<=n;i++){
			fill(pre[i].begin(),pre[i].end(),0);
			fill(suf[i].begin(),suf[i].end(),0);
		}
		for(i=1;i<=m;i++)
			if(i!=pos) ans[i]=a[row][i];
		for(i=1;i<=m;i++){
			for(j=1;j<=n;j++)
				pre[j][i]=pre[j][i-1]+(a[j][i]!=ans[i]);
		}
		for(i=m;i;i--){
			for(j=1;j<=n;j++)
				suf[j][i]=suf[j][i+1]+(a[j][i]!=ans[i]);
		}
		int ta;
		for(i=1;i<=m;i++){
			if(i==pos) continue;
			ta=0;
			bool flag=1;
			for(j=1;j<=n;j++){
				if(pre[j][i-1]+suf[j][i+1]>2) flag=0;
				else if(pre[j][i-1]+suf[j][i+1]==2){
					if(ta==0||ta==a[j][i]) ta=a[j][i];
					else flag=0;
				}
			}
			if(flag){
				ans[i]=ta;
				print();
			}
		}
	}
	cout<<"No";
	return 0;
}