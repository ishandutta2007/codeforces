#include <iostream>
#include <cstdio> 
#include <algorithm>
#include <cstring>
#include <cmath>
#include <vector>
using namespace std;
int ttt,n,m,q[100][100005],len[100],book[100][2];
char s[1000005],t[1000005];
signed main(){
	cin>>ttt;
	while(ttt--){
		scanf("%s%s",s+1,t+1);
		n=strlen(s+1),m=strlen(t+1);
		memset(book,0,sizeof(book));
		memset(len,0,sizeof(len));
		for (int i=1;i<=n;i++)book[s[i]-'a'][0]++;
		for (int i=1;i<=m;i++)book[t[i]-'a'][1]++;
		int flag=1;
		for (int i=0;i<26;i++){
			if (book[i][1]>0&&book[i][0]==0){
				cout<<-1<<endl;
				flag=0;
				break;
			}
		}
		if (flag==0)continue;
		for (int i=1;i<=n;i++){
			len[s[i]-'a']++;
			q[s[i]-'a'][len[s[i]-'a']]=i;
		}
		int ans=1,pos=0;
		for (int i=1;i<=m;i++){
			int w=t[i]-'a';
			int l=1,r=len[w],sss=-1;
			while(l<=r){
				int mid=(l+r)/2;
				if (q[w][mid]>pos)sss=mid,r=mid-1;
				else l=mid+1;
			}
			if (sss==-1){
				pos=0,ans++;
				l=1,r=len[w],sss=-1;
				while(l<=r){
					int mid=(l+r)/2;
					if (q[w][mid]>pos)sss=mid,r=mid-1;
					else l=mid+1;
				}
				pos=q[w][sss];
			}
			else pos=q[w][sss];
		}
		cout<<ans<<endl;
	}
}