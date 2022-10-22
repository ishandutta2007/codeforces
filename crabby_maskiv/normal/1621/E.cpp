#include<bits/stdc++.h>
#define fr first
#define sc second
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int N=1e5+5;
int n,m;
ll a[N],sz[N];
vector<ll> b[N];
ll s[N];
int t[N],id[N];
int s1[N],s2[N],s3[N];
inline bool cmp(int x,int y){
	return s[x]*sz[y]<s[y]*sz[x];
}
inline bool chk(int x,int y){
	return s[x]<=sz[x]*a[y];
}
int main(){
	int i,j;
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int _;cin>>_;
	while(_--){
		cin>>n>>m;
		for(i=1;i<=n;i++) cin>>a[i];
		sort(a+1,a+n+1);
		for(i=1;i<=m;i++) a[i]=a[n-m+i];
		n=m;
		for(i=1;i<=n;i++){
			cin>>sz[i];
			for(j=0;j<sz[i];j++){
				int x;cin>>x;
				b[i].push_back(x);
				s[i]+=x;
			}
			t[i]=i;
		}
		sort(t+1,t+n+1,cmp);
		for(i=1;i<=n;i++) id[t[i]]=i;
		for(i=1;i<=n;i++){
			s1[i]=s1[i-1]+(!chk(t[i],i));
			s2[i]=s2[i-1]+(!chk(t[i],i-1));
			s3[i]=s3[i-1]+(!chk(t[i],i+1));
		}
		for(i=1;i<=n;i++){
			for(auto x:b[i]){
				s[i]-=x;sz[i]--;
				if(x*sz[i]<=s[i]){
					if(id[i]==n||cmp(i,t[id[i]+1])){
						cout<<(s1[id[i]-1]==0&&s1[n]==s1[id[i]]&&chk(i,id[i]));
					}
					else{
						int l=id[i]+1,r=n;
						while(l<r){
							int mid=l+r+1>>1;
							if(cmp(i,t[mid])) r=mid-1;
							else l=mid;
						}
						cout<<(s2[l]==s2[id[i]]&&s1[n]==s1[l]&&s1[id[i]-1]==0&&chk(i,l));
					}
				}
				else{
					if(id[i]==1||cmp(t[id[i]-1],i)){
						cout<<(s1[id[i]-1]==0&&s1[n]==s1[id[i]]&&chk(i,id[i]));
					}
					else{
						int l=1,r=id[i]-1;
						while(l<r){
							int mid=l+r>>1;
							if(cmp(t[mid],i)) l=mid+1;
							else r=mid;
						}
						cout<<(s3[id[i]-1]==s3[l-1]&&s1[n]==s1[id[i]]&&s1[l-1]==0&&chk(i,l));
					}
				}
				s[i]+=x;sz[i]++;
			}
		}
		cout<<endl;
		for(i=1;i<=n;i++) b[i].clear();
		for(i=1;i<=n;i++) s[i]=s1[i]=s2[i]=s3[i]=0;
	}
	return 0;
}