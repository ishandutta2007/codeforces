#include<iostream>
#include<set>
using namespace std;
#define R register int
#define N 50001
int a[N],q[N],lf[N],f[N];
long long b[N];
inline void Solve(){
	int n,x,t=-1,ans;
	cin>>n;
	for(R i=1;i<=n;i++){
		cin>>a[i];
	}
	cin>>x;
	for(R i=1;i<=n;i++){
		b[i]=b[i-1]+a[i]-x;
		int l=0,r=t,mid,res=-1;
		while(l<=r){
			mid=l+r>>1;
			if(b[i]<b[q[mid]]){
				res=mid;
				l=mid+1;
			}else{
				r=mid-1;
			}
		}
		if(res==-1){
			lf[i]=-1;
		}else{
			lf[i]=q[res];
		}
		while(t!=-1&&b[q[t]]<=b[i-1]){
			t--;
		}
		t++;
		q[t]=i-1;
	}
	/*for(R i=1;i<=n;i++){
		printf("%d ",lf[i]);
	}
	puts("");*/
	multiset<int>S;
	S.insert(0);
	int curL=0,curR=0;
	f[1]=1;
	for(R i=2;i<=n;i++){
		//fprintf(stderr,"I%d\n",i);
		while(curL<=lf[i-1]){
			//fprintf(stderr,"E%d\n",f[curL]);
			S.erase(S.find(f[curL]));
			curL++;
		}
		f[i]=f[i-1]+1;
		if(curL<=curR){
			int x=*S.begin()+1;
			if(x<f[i]){
				f[i]=x;
			}
		}
		curR++;
		S.insert(f[curR]);
	}
	/*for(R i=1;i<=n;i++){
		printf("%d ",f[i]);
	}
	puts("");*/
	ans=f[n];
	int suf=-1;
	for(R i=n;i!=0;i--){
		if(lf[i]>suf){
			suf=lf[i];
		}
		if(suf<i-1&&f[i-1]<ans){
			ans=f[i-1];
		}
	}
	cout<<n-ans<<endl;
}
int main(){
	//freopen("1.txt","w",stdout);
	int t;
	cin>>t;
	for(R i=0;i!=t;i++){
		Solve();
	}
	return 0;
}
/*
1
1
2
1
*/