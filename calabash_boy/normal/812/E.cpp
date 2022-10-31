#include<bits/stdc++.h>
using namespace std;
int can[17000005];
vector<int> a;
int father[100005];
int n;
bool leaf[100005];
int que[1000000];
int deep[100005];
int aa[100005];
int main(){
	cin>>n;
	memset(leaf,true,sizeof(leaf));
	for (int i=1;i<=n;i++){
		scanf("%d",&aa[i]);
	}
	for (int i=2;i<=n;i++){
		scanf("%d",&father[i]);
		leaf[father[i]]=false;
	}
	int l=0;
	int r=0;
	for (int i=1;i<=n;i++){
		if (leaf[i]){
			r++;
			que[r]=i;
		}
	}
	while (l<r){
		l++;
		int q=que[l];
		//deep[father[q]]=deep[q]+1;
		if (deep[father[q]]==0&&q!=1){
			r++;
			deep[father[q]]=deep[q]+1;
			que[r]=father[q];
		}
	}
	int k=0;
	for (int i=1;i<=n;i++){
//		cout<<"!"<<deep[i]<<endl;
		if ((deep[i]&1)==0){
			k^=aa[i];
			a.push_back(aa[i]);
		}else{
			can[aa[i]]++;
		}
	}
//	cout<<k<<endl;
	long long ans=0;
	if (k==0){
		long long temp = a.size();
		ans+=(temp*(temp-1))/2;
		temp = n-temp;
		ans+=(temp*(temp-1))/2;
	}
	for (vector<int>::iterator it = a.begin();it!=a.end();it++){
//		cout<<(*it)<<endl;
		ans+=can[k^(*it)];
	}
	cout<<ans<<endl;
	return 0;
}