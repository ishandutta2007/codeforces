#include<bits/stdc++.h>
using namespace std;
int s,n,a[2003],S;
vector<int>v;
int pa[2][2003],dp[2][2003],dir[2][2003],val[2003];
bool vis[2003];
vector<int>fnd(int x){
	vector<int>ret;
	for(int i=0;i<n;i++)
		if(a[i]==x)
			ret.push_back(i);
	return ret;
} 
int main(){
	memset(dp,31,sizeof(dp));
	cin>>n>>s;s--;S=s;
	for(int i=0;i<n;i++){
		cin>>a[i];a[i]--;
		v.push_back(a[i]);
	}sort(v.begin(),v.end());
	v.erase(unique(v.begin(),v.end()),v.end());
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
			if(a[i]>a[j])
				val[i]++;
	vector<int>nw=fnd(v[0]);
	for(int i=0;i<nw.size();i++){
		pa[0][nw[i]]=-1;
		int val=(nw[i]-s+n)%n;
		if(dp[0][nw[i]]>val)
			dp[0][nw[i]]=val,pa[0][nw[i]]=s,dir[0][nw[i]]=1;
		val=(s-nw[i]+n)%n;
		if(dp[0][nw[i]]>val)
			dp[0][nw[i]]=val,pa[0][nw[i]]=s,dir[0][nw[i]]=-1;
	}
	for(int i=0;i<nw.size();i++){
		int l=nw[(i+nw.size()-1)%nw.size()],r=nw[(i+1)%nw.size()];
		int lval=dp[0][l]+(l-nw[i]+n)%n,rval=dp[0][r]+(nw[i]-r+n)%n;
		if(lval<rval)
			dp[1][nw[i]]=lval,pa[1][nw[i]]=l,dir[1][nw[i]]=-1;
		else
			dp[1][nw[i]]=rval,pa[1][nw[i]]=r,dir[1][nw[i]]=1;
	}
	for(int i=1;i<v.size();i++){
		vector<int>lst=nw;nw=fnd(v[i]);
		for(int j=0;j<lst.size();j++){
			s=lst[j];
			for(int k=0;k<nw.size();k++){
				int val=(nw[k]-s+n)%n+dp[1][s];
				if(dp[0][nw[k]]>val)
					dp[0][nw[k]]=val,pa[0][nw[k]]=s,dir[0][nw[k]]=1;
				val=(s-nw[k]+n)%n+dp[1][s];
				if(dp[0][nw[k]]>val)
					dp[0][nw[k]]=val,pa[0][nw[k]]=s,dir[0][nw[k]]=-1;
			}
		}
		for(int j=0;j<nw.size();j++){
			int l=nw[(j+nw.size()-1)%nw.size()],r=nw[(j+1)%nw.size()];
			int lval=dp[0][l]+(l-nw[j]+n)%n,rval=dp[0][r]+(nw[j]-r+n)%n;
			if(lval<rval)
				dp[1][nw[j]]=lval,pa[1][nw[j]]=l,dir[1][nw[j]]=-1;
			else
				dp[1][nw[j]]=rval,pa[1][nw[j]]=r,dir[1][nw[j]]=1;
		}
	}
	int t=-1;
	for(int i=0;i<nw.size();i++)
		if(t==-1||dp[1][t]>dp[1][nw[i]])
			t=nw[i];
	cout<<dp[1][t]<<endl;
	vector<int>opt;
	for(int i=0;i<v.size();i++){
		int nw=pa[1][t],nd=dir[1][t];
		while(t!=nw){
			opt.push_back(nd);
			t=(t-nd+n)%n;
		}
		nw=pa[0][t];nd=dir[0][t];
		while(t!=nw){
			opt.push_back(nd);
			t=(t-nd+n)%n;
		}
	}
	reverse(opt.begin(),opt.end());
	opt.push_back(1);
	int sum=0,ans=0;
	for(int i=0;i<opt.size();i++){
		if(!vis[S]&&sum>=val[S]){
			if(ans<0)
				cout<<ans<<endl;
			else
				cout<<'+'<<ans<<endl;
			ans=0;
			vis[S]=1;
			sum++;
		}
		ans=ans+opt[i];
		S=(S+opt[i]+n)%n;
	}
}