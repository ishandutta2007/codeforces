#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,m;
ll K;
string t[15];
string pre[202],suf[202];
vector<string>S;
ll val[202];
ll f[202];
vector<int>Z(string s){
	vector<int>z;z.push_back(0);
	int l=0,r=0;
	for(int i=1;i<s.size();i++){
		if(i>r){
			l=r=i;
			while(r<s.size()&&s[r-l]==s[r])r++;
            z.push_back(r-l),r--;
		}else{
            int k=i-l;
            if(z[k]<r-i+1)z.push_back(z[k]);
            else{
                l=i;
                while(r<s.size()&&s[r-l]==s[r])r++;
                z.push_back(r-l),r--;
        	}
		}
	}
	return z;
}
ll calc(string s){
	ll cnt=0;
	for(int i=0;i<S.size();i++)if(S[i]<=s)cnt++;
	for(int i=0;i<=n;i++){
		if(i>1){
			f[i]=f[i-2]+f[i-1];
			string S=s+"$"+suf[i-2]+pre[i-1];
			vector<int>z=Z(S);
			for(int l=s.size()+1,r=l+m-1;r<S.size();l++,r++){
				if(z[l]>=s.size()&&s.size()==m)f[i]++;
				else f[i]+=(S[l+z[l]]<S[z[l]]);
			}
			f[i]=min(f[i],(ll)1e18);
		}else f[i]=(m==1&&t[i]<=s);
	}
	return f[n]+cnt;
}
int main(){
	scanf("%d%lld%d",&n,&K,&m);
	t[0]="0",t[1]="1";for(int i=2;i<15;i++)t[i]=t[i-2]+t[i-1];
	for(int i=0;i<=n;i++){
		if(i<15){
			int it;
			pre[i]="";
			it=0;
			while(it<m-1&&it<t[i].size())pre[i]+=t[i][it++];
			reverse(t[i].begin(),t[i].end());
			suf[i]="";
			it=0;
			while(it<m-1&&it<t[i].size())suf[i]+=t[i][it++];
			reverse(suf[i].begin(),suf[i].end());
		}else pre[i]=pre[i-2],suf[i]=suf[i-1];
	}
	if(suf[n].size()+1>=m){
		for(int i=1;i<m;i++)S.push_back(suf[n].substr(suf[n].size()-i,i));
		sort(S.begin(),S.end());
		for(int i=0;i<S.size();i++)val[i]=calc(S[i]);
		string tmp="";
		for(int i=0;i<m;i++){
			string TMP=tmp+"0";
			for(int j=i+1;j<m;j++)TMP+="1";
			if(calc(TMP)<K)tmp+="1";
			else tmp+="0";
		}
		for(int i=0;i<S.size();i++)if(val[i]>=K){
			printf("%s",min(S[i],tmp).c_str());
			return 0;
		}
		printf("%s",tmp.c_str());
	}else{
		for(int i=1;i<=suf[n].size();i++)S.push_back(suf[n].substr(suf[n].size()-i,i));
		sort(S.begin(),S.end());
		for(int i=0;i<S.size();i++)val[i]=calc(S[i]);
		for(int i=0;i<S.size();i++)if(val[i]>=K){
			printf("%s",S[i].c_str());
			return 0;
		}
	}
}