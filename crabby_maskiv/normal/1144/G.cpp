#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=200005;
const ll inf=0x3f3f3f3fll;
const ll mod=998244353ll;
int n,m;
pair<int,int> st1[N],st2[N];
int top1,top2;
int a[N];
bool ans[N];
int main(){
	ios::sync_with_stdio(0);
	int i,j;
	st1[0]={-1,0};st2[0]={inf,0};
	cin>>n;
	for(i=1;i<=n;i++) cin>>a[i];
	for(i=1;i<=n;i++){
		if(a[i]>st1[top1].first) st1[++top1]={a[i],i};
		else if(a[i]<st2[top2].first) st2[++top2]={a[i],i};
		else{
			cout<<"NO";
			return 0;
		}
		if(!top1||!top2) continue;
		if(st1[top1].first<st2[top2-1].first&&st2[top2].first>st1[top1-1].first
		&&st2[top2].first<st1[top1].first&&
		st1[top1].second>st2[top2-1].second&&st2[top2].second>st1[top1-1].second){
			swap(st2[top2],st1[top1]);
		}
		else if(st1[top1].first<st2[top2-1].first&&st1[top1].first>st2[top2].first
		&&st1[top1].second>st2[top2-1].second&&st1[top1].second<st2[top2].second){
			st2[top2+1]=st2[top2];top2++;
			st2[top2-1]=st1[top1];
			top1--;
		}
		else if(st2[top2].first>st1[top1-1].first&&st2[top2].first<st2[top2].first
		&&st2[top2].second>st1[top1-1].second&&st2[top2].second<st1[top1].second){
			st1[top1+1]=st1[top1];top1++;
			st1[top2-1]=st2[top2];
			top2--;
		}
	}
	for(i=1;i<=top2;i++) ans[st2[i].second]=1;
	cout<<"YES"<<endl;
	for(i=1;i<=n;i++) cout<<ans[i]<<" ";
	return 0;
}