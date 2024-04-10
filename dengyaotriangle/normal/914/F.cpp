#include<iostream>
#include<cstring>
#include<vector>
#include<queue>
#include<bitset>

using namespace std;

const int maxn=100005;
const int maxm=27;
bitset<maxn> st[27],ans;
int n;
char c[maxn];

int main(){
	ios::sync_with_stdio(0);
	cin>>(c+1);
	n=strlen(c+1);
	for(int i=1;i<=n;i++) st[c[i]-'a'][i]=1;
	int q;
	cin>>q;
	while(q--){
		int op;
		cin>>op;
		if(op==1){
			int i;
			char c;
			cin>>i>>c;
			for(int j=0;j<='z'-'a';j++) st[j][i]=0;
			st[c-'a'][i]=1;
		}else{
			int l,r,e;
			cin>>l>>r>>(c+1);
			e=strlen(c+1);
			ans.set();
			for(int i=1;i<=e;i++){
				ans=ans&(st[c[i]-'a']>>(i-1));
			}
			cout<<max(0,(int)((ans>>l).count()-(ans>>(r-e+2)).count()))<<endl;
		}
	}
	return 0;
}