#include <cstdio>
#include <algorithm>
#include <cstring>
#include <deque>
#include <iostream>
#include <map>
#define maxn 509
using namespace std;
int n,m;
int a[maxn],b[maxn];
vector<pair<int,int> >ans;
bool doit(int L,int R,int pre){
	if(L==R)
		return 1;
	int ma=0;
	for(int i=L;i<=R;i++)
		ma=max(ma,a[i]);
	int pos=-1;
	for(int i=L;i<=R;i++){
		if(ma==a[i]){
			if(i-1>=L&&a[i]>a[i-1]){
				pos=i;
				break;
			}
			if(i+1<=R&&a[i]>a[i+1]){
				pos=i;
				break;
			}
		}
	}
	if(pos==-1)
		return 0;
	if(pos+1<=R&&a[pos]>a[pos+1]){
		for(int i=pos+1;i<=R;i++){
			ans.push_back(make_pair(1,pre-1+pos-L+1));
		}
		int cur=pre-1+pos-L+1;
		for(int i=pos-1;i>=L;i--){
			ans.push_back(make_pair(0,cur));
			cur--;
		}
	}
	else{
		int cur=pre-1+pos-L+1;
		for(int i=pos-1;i>=L;i--){
			ans.push_back(make_pair(0,cur));
			cur--;
		}
		for(int i=pos+1;i<=R;i++){
			ans.push_back(make_pair(1,pre));
		}
	}
	return 1;
}
bool solve(){
	int last=0;
	for(int i=1;i<=m;i++){
		int sum=0,pos=-1;
		for(int j=last+1;j<=n&&sum<b[i];j++){
			sum+=a[j];
			pos=j;
		}
		if(sum!=b[i])
			return 0;
		if(!doit(last+1,pos,i))
			return 0;
		last=pos;
	}
	if(last!=n)
		return 0;
	return 1;
}
int main(){
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	cin>>m;
	for(int i=1;i<=m;i++)
		cin>>b[i];
	if(!solve())
		puts("NO");
	else{
		puts("YES");
		for(int i=0;i<(int)ans.size();i++){
			if(ans[i].first==0){
				printf("%d L\n",ans[i].second);
			}
			else{
				printf("%d R\n",ans[i].second);
			}
		}
	}
	//system("pause");
	return 0;
}