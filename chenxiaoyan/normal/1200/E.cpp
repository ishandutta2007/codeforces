#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
const int N=100000,LEN=1000000;
int n;
string s[N+1];
const int hbase1=131,hbase2=13331,hmod1=1000000007,hmod2=998244353;
int Hsh1[LEN+1],Hsh2[LEN+1],Hshall1[LEN+1],Hshall2[LEN+1];
int pw1[LEN+1],pw2[LEN+1];
void hsh_init(string &str,int H1[],int H2[]){
	for(int i=0;i<str.size();i++)
		H1[i+1]=(1ll*H1[i]*hbase1+str[i])%hmod1,H2[i+1]=(1ll*H2[i]*hbase2+str[i])%hmod2;
}
pair<int,int> hsh(int H1[],int H2[],int l,int r){
	return mp((H1[r]-1ll*H1[l-1]*pw1[r-l+1]%hmod1+hmod1)%hmod1,(H2[r]-1ll*H2[l-1]*pw2[r-l+1]%hmod2+hmod2)%hmod2);
}
int main(){
	pw1[0]=pw2[0]=1;
	for(int i=1;i<=1000000;i++)pw1[i]=1ll*pw1[i-1]*hbase1%hmod1,pw2[i]=1ll*pw2[i-1]*hbase2%hmod2;
	cin>>n;
	for(int i=1;i<=n;i++)cin>>s[i],hsh_init(s[i],Hsh1,Hsh2);
	string now=s[1];
	hsh_init(s[1],Hshall1,Hshall2);
	for(int i=2;i<=n;i++){
		hsh_init(s[i],Hsh1,Hsh2);
		for(int j=min(now.size(),s[i].size());~j;j--)
			if(hsh(Hshall1,Hshall2,now.size()-j+1,now.size())==hsh(Hsh1,Hsh2,1,j)){
				for(int k=j;k<s[i].size();k++)
					now+=s[i][k],
					Hshall1[now.size()]=(1ll*Hshall1[now.size()-1]*hbase1+now[now.size()-1])%hmod1,Hshall2[now.size()]=(1ll*Hshall2[now.size()-1]*hbase2+now[now.size()-1])%hmod2;
				break;
			}
	}
	cout<<now;
	return 0;
}
/*1
5
I want to order pizza
*/
/*2
5
sample please ease in out
*/