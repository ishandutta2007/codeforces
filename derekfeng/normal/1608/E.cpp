#include<bits/stdc++.h>
using namespace std;
int n,a[100004],b[100004],t[100004];
int ord[100004],ans;
vector<int>allx,ally;
vector<int>X[100004][3],Y[100004][3];
int b1[100004],b2[100004];
void upd1(int i,int w){
	for(;i<=n;i+=i&-i)b1[i]+=w;
}
int bs1(int w){
	int p=0,c=0;
	for(int i=16;~i;i--){
		int np=p+(1<<i);
		if(np>n||c+b1[np]>=w)continue;
		p=np,c+=b1[np];
	}
	return p+1;
}
void upd2(int i,int w){
	for(;i;i-=i&-i)b2[i]+=w;
}
int qry2(int i){
	int ret=0;
	for(;i<=n;i+=i&-i)ret+=b2[i];
	return ret;
}
bool cmpx(int A,int B){
	return a[A]<a[B];
}
bool cmpy(int A,int B){
	return b[A]<b[B];
}
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d%d%d",&a[i],&b[i],&t[i]),--t[i];
		allx.push_back(a[i]),ally.push_back(b[i]);
		ord[i]=i;
	}
	sort(allx.begin(),allx.end()),allx.erase(unique(allx.begin(),allx.end()),allx.end());
	sort(ally.begin(),ally.end()),ally.erase(unique(ally.begin(),ally.end()),ally.end());
	for(int i=1;i<=n;i++){
		a[i]=lower_bound(allx.begin(),allx.end(),a[i])-allx.begin()+1;
		b[i]=lower_bound(ally.begin(),ally.end(),b[i])-ally.begin()+1;
		X[a[i]][t[i]].push_back(i);
		Y[b[i]][t[i]].push_back(i);
	}
	for(int A=0;A<3;A++)for(int B=0;B<3;B++)for(int C=0;C<3;C++)if(A!=B&&A!=C&&B!=C){
		int N,cur,R1,R2;
		sort(ord+1,ord+n+1,cmpx);
		for(int i=1;i<=n;i++){
			if(t[i]==B)upd1(b[i],1);
			if(t[i]==C)upd2(b[i],1);
		}
		N=0;
		for(int i=1;i<=n;i++){
			if(i==1||a[ord[i]]!=a[ord[i-1]]){
				for(auto x:X[a[ord[i]]][B])upd1(b[x],-1);
				for(auto x:X[a[ord[i]]][C])upd2(b[x],-1);
			}
			if(t[ord[i]]!=A)continue;
			++N;
			int pos=bs1(N);
			if(pos>n)continue;
			if(qry2(pos+1)>=N)ans=max(ans,N);
		}
		for(int i=1;i<=n;i++){
			if(t[i]==B)upd1(b[i],1);
			if(t[i]==C)upd2(b[i],1);
		}
		N=0;
		for(int i=n;i;i--){
			if(i==n||a[ord[i]]!=a[ord[i+1]]){
				for(auto x:X[a[ord[i]]][B])upd1(b[x],-1);
				for(auto x:X[a[ord[i]]][C])upd2(b[x],-1);
			}
			if(t[ord[i]]!=A)continue;
			++N;
			int pos=bs1(N);
			if(pos>n)continue;
			if(qry2(pos+1)>=N)ans=max(ans,N);
		}
		N=0;
		for(int i=1;i<=n;i++){
			if(t[i]==B)b1[a[i]]++;
			if(t[i]==C)b2[a[i]]++;
		}
		for(int i=1;i<=n;i++)b1[i]+=b1[i-1],b2[i]+=b2[i-1];
		cur=0,R1=0,R2=0;
		for(int i=1;i<=n;i++){
			if(i==1||a[ord[i]]!=a[ord[i-1]])cur=a[ord[i]];
			if(t[ord[i]]!=A)continue;
			++N;
			while(b1[R1]-b1[cur]<N&&R1<=n)R1++;
			while(b2[R2]-b2[R1]<N&&R2<=n)R2++;
			if(R1<=n&&R2<=n)ans=max(ans,N);
		}
		for(int i=1;i<=n;i++)b1[i]=b2[i]=0;
		sort(ord+1,ord+n+1,cmpy);
		for(int i=1;i<=n;i++){
			if(t[i]==B)upd1(a[i],1);
			if(t[i]==C)upd2(a[i],1);
		}
		N=0;
		for(int i=1;i<=n;i++){
			if(i==1||b[ord[i]]!=b[ord[i-1]]){
				for(auto x:Y[b[ord[i]]][B])upd1(a[x],-1);
				for(auto x:Y[b[ord[i]]][C])upd2(a[x],-1);
			}
			if(t[ord[i]]!=A)continue;
			++N;
			int pos=bs1(N);
			if(pos>n)continue;
			if(qry2(pos+1)>=N)ans=max(ans,N);
		}
		for(int i=1;i<=n;i++){
			if(t[i]==B)upd1(a[i],1);
			if(t[i]==C)upd2(a[i],1);
		}
		N=0;
		for(int i=n;i;i--){
			if(i==n||b[ord[i]]!=b[ord[i+1]]){
				for(auto x:Y[b[ord[i]]][B])upd1(a[x],-1);
				for(auto x:Y[b[ord[i]]][C])upd2(a[x],-1);
			}
			if(t[ord[i]]!=A)continue;
			++N;
			int pos=bs1(N);
			if(pos>n)continue;
			if(qry2(pos+1)>=N)ans=max(ans,N);
		}
		N=0;
		for(int i=1;i<=n;i++){
			if(t[i]==B)b1[b[i]]++;
			if(t[i]==C)b2[b[i]]++;
		}
		for(int i=1;i<=n;i++)b1[i]+=b1[i-1],b2[i]+=b2[i-1];
		cur=0,R1=0,R2=0;
		for(int i=1;i<=n;i++){
			if(i==1||b[ord[i]]!=b[ord[i-1]])cur=b[ord[i]];
			if(t[ord[i]]!=A)continue;
			++N;
			while(b1[R1]-b1[cur]<N&&R1<=n)R1++;
			while(b2[R2]-b2[R1]<N&&R2<=n)R2++;
			if(R1<=n&&R2<=n)ans=max(ans,N);
		}
		for(int i=1;i<=n;i++)b1[i]=b2[i]=0;
	}
	printf("%d",ans*3);
}