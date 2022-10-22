#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
void read(int &x){
	char ch=getchar();x=0;
	for (;ch==' '||ch=='\n';ch=getchar());
	for (;ch!=' '&&ch!='\n';x=x*10+ch-'0',ch=getchar());
}
void reads(string &s){
	char ch=getchar();s="";
	for (;ch==' '||ch=='\n';ch=getchar());
	for (;ch!=' '&&ch!='\n';s+=ch,ch=getchar());
}
void write(int x){
	if (x>9) write(x/10);
	putchar(x%10+'0');
}
int getnum(string s){
	int ret=0;
	for (int i=s.size()-1;i>1;i--) ret=ret*10+s[i]-'0';
	return ret;
}
string st;
int n,m,c[200004],C[200004];
int S[400004],z[400004];
ll s[400004],num[400004],NUM[400004];
void SOLVE1(){
	ll ans=0;
	for (int i=1;i<=n;i++) if (c[i]==C[1]) ans+=max(0ll,num[i]-NUM[1]+1);
	printf("%I64d",ans),exit(0); 
}
void SOLVE2(){
	int ans=0;
	for (int i=1;i<n;i++) 
		if (c[i]==C[1] && c[i+1]==C[2] && num[i]>=NUM[1] && num[i+1]>=NUM[2]) ans++;
	write(ans),exit(0);
}
bool SAME(int a,int b){
	return S[a]==S[b] && s[a]==s[b];
}
void Z(){
	int l=0,r=0;
    for (int i=1;i<n+m-3;i++){
        if (i>r){
            l=i,r=i;
            while (r<n+m-3 && SAME(r-l,r)) r++;
            z[i]=r-l,r--;
		}else{
            int k=i-l;
            if (z[k]<r-i+1) z[i]=z[k];
            else{
                l=i;
                while (r<n+m-3 && SAME(r-l,r)) r++;
                z[i]=r-l,r--;
        	}
        }
    } 
}
void SOLVEMORE(){
	int ans=0;
	for (int i=2;i<m;i++) S[i-2]=C[i],s[i-2]=NUM[i];
	S[m-2]=26;
	for (int i=2;i<n;i++) S[m-3+i]=c[i],s[m-3+i]=num[i];
	Z();
	for (int i=1;i+m-1<=n;i++){
		if (c[i]!=C[1] || c[i+m-1]!=C[m] || NUM[1]>num[i] || NUM[m]>num[i+m-1]) continue;
		if (z[m-2+i]==m-2) ans++;
	}
	write(ans);
}
int main(){
	read(n),read(m);
	for (int i=1;i<=n;i++){
		reads(st),reverse(st.begin(),st.end()),c[i]=st[0]-'a',num[i]=getnum(st);
		if (i>1 && c[i]==c[i-1]) num[i-1]+=num[i],i--,n--;
	}
	for (int i=1;i<=m;i++){
		reads(st),reverse(st.begin(),st.end()),C[i]=st[0]-'a',NUM[i]=getnum(st);
		if (i>1 && C[i]==C[i-1]) NUM[i-1]+=NUM[i],i--,m--;
	}
	if (m==1) SOLVE1();
	if (m==2) SOLVE2();
	SOLVEMORE();
}