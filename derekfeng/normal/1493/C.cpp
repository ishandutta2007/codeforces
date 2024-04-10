#include<bits/stdc++.h>
using namespace std;
int T,n,k,lst;
string s;
int num[26];
int calc(){
	int ret=0;
	for(int i=0;i<26;i++)ret+=num[i];
	return ret;
}
vector<int>sm[26],bg[26];
int main(){
	cin>>T;
	while(T--){
		cin>>n>>k>>s;
		if(n%k){
			puts("-1");
			continue;
		}
		for(int i=0;i<26;i++)sm[i].clear(),bg[i].clear();
		lst=n;
		for(int i=0;i<n;i++){
			for(int j=s[i]-'a'+1;j<26;j++)sm[j].push_back(i);
			for(int j=s[i]-'a'-1;j>=0;j--)bg[j].push_back(i);
		}
		for(int i=0;i<26;i++)sm[i].push_back(n),bg[i].push_back(n);
		bool sam=1;
		for(int i=0;i<n;i++){
			if(sam){
				lst--;
				s[i]-='a';
				num[s[i]]=(num[s[i]]+k-1)%k;
				int tmp=calc();
				if(lst>=tmp&&(lst-tmp)%k==0){
					bool ok=1;
					int l=i+1;
					num[25]+=lst-tmp;
					for(int j=25;j>=0;j--){
						int r=l+num[j]-1;
						int lb=lower_bound(sm[j].begin(),sm[j].end(),l)-sm[j].begin();
						int rb=lower_bound(bg[j].begin(),bg[j].end(),l)-bg[j].begin();;
						lb=sm[j][lb],rb=bg[j][rb];
						if(lb>r)lb=n;
						if(rb>r)rb=n;
						if(lb>rb){ok=0;break;}
						if(lb<rb)break;
						l+=num[j];
					}
					num[25]-=lst-tmp;
					if(ok){
						putchar(s[i]+'a');
						continue;
					}
					if(!ok)num[s[i]]=(num[s[i]]+1)%k;
				}else num[s[i]]=(num[s[i]]+1)%k;
				for(int j=s[i]+1;j<26;j++){
					num[j]=(num[j]+k-1)%k;
					int tmp=calc();
					if(lst>=tmp&&(lst-tmp)%k==0){
						putchar(j+'a');
						sam=0,num[0]+=lst-tmp;
						break;
					}
					num[j]=(num[j]+1)%k;
				}
			}else{
//				for(int j=0;j<26;j++)cout<<num[j]<<" ";puts("");
				for(int j=0;j<26;j++)if(num[j]>0){
					putchar(j+'a');
					num[j]--;
					break;
				}
			}
		}
		puts("");
	}
}