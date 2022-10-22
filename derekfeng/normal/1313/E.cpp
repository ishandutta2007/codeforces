#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,m,lcp[500005],lcs[500005];
char a[500005],b[500005],s[1000005];
vector<int>posa[1000005],posb[1000005];
int N,z[1500005];
char S[1500005];
void Z(){
    int l=0,r=0;
    for(int i=1;i<N;i++){
        if(i>r){l=i,r=i;while(r<N&&S[r-l]==S[r])r++;z[i]=r-l,r--;}
		else{
        	int k=i-l;if(z[k]<r-i+1)z[i]=z[k];
            else{l=i;while(r<N&&S[r-l]==S[r])r++;z[i]=r-l,r--;}
        }
    }
}
ll ans,r1,r2;
ll B1[500005],B2[500005];
void upd(int i,ll x){
	for(;i<=n;i+=i&-i)B1[i]++,B2[i]+=x;
}
void qry(int i,int t){
	for(;i;i-=i&-i)r1+=B1[i]*t,r2+=B2[i]*t;
}
void ask(int l,int r){
	r1=r2=0;
	qry(l-1,-1),qry(r,1);
}
int main(){
	scanf("%d%d%s%s%s",&n,&m,a+1,b+1,s+1);
	N=0;for(int i=1;i<=m;i++)S[N++]=s[i];S[N++]='$';for(int i=1;i<=n;i++)S[N++]=a[i];
	Z();for(int i=1;i<=n;i++)lcp[i]=z[m+i];
	N=0;for(int i=m;i;i--)S[N++]=s[i];S[N++]='$';for(int i=n;i;i--)S[N++]=b[i];
	Z();for(int i=0;i<n;i++)lcs[n-i]=z[m+1+i];
	for(int i=1;i<=n;i++)posa[min(m-1,lcp[i])].push_back(i);
	for(int i=1;i<=n;i++)posb[min(m-1,lcs[i])].push_back(i);
	for(int i=1;i<m;i++){
		for(auto x:posb[m-i])upd(x,m-i);
		for(auto x:posa[i]){
			int L=x,R=x+m-2;R=min(R,n);
			ask(L,R);
			ans+=r1*(i-m+1)+r2;
		}
	}
	printf("%lld",ans);
}