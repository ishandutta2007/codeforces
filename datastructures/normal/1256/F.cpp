#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
int t,n,book1[26],book2[26];
char a[200005],b[200005];
int main(){
	cin>>t;
	while(t--){
		cin>>n;
		scanf("%s",a+1);
		scanf("%s",b+1);
		memset(book1,0,sizeof(book1));
		memset(book2,0,sizeof(book2));
		for (int i=1;i<=n;i++)book1[a[i]-'a']++,book2[b[i]-'a']++;
		int flag;
		flag=1;
		for (int i=0;i<26;i++)
			if (book1[i]!=book2[i])flag=0;
		if (flag==0){
			cout<<"NO"<<endl;
			continue;
		} 
		flag=0;
		for (int i=0;i<26;i++)
			if (book1[i]>=2)flag=1;
		if (flag==1){
			cout<<"YES"<<endl;
			continue;
		}
		flag=1;
		for (int i=1;i<=n;i++){
			int j;
			for (j=i;j<=n;j++)
				if (b[j]==a[i])break;
			for (int k=j-1;k>=i;k--)swap(b[k],b[k+1]),flag=(flag+1)%2;
		}
		if (flag==1){
			cout<<"YES"<<endl;
			continue;
		}
		else{
			cout<<"NO"<<endl;
			continue;
		}
	}
	return 0;
}