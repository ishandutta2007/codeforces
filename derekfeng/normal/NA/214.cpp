#include<bits/stdc++.h>
using namespace std;
string s;
string a,b,c;
void go(string s){
	int cur=0;
	while(isdigit(s[cur]))a+=s[cur],cur++;
	cur++;
	while(isdigit(s[cur]))b+=s[cur],cur++;
	cur++;
	while(cur<s.size())c+=s[cur],cur++;
}
int fr[15][8][8][8][2],fo[15][8][8][8][2],fm[15][8][8][8][2];
int n1,n2,n3,len=1e9;
string ans,S1,S2,S3;
int A[15][8][8][8][2],B[15][8][8][8][2],C[15][8][8][8][2];
int main(){
	cin>>s;
	go(s);
	int n1=a.size(),n2=b.size(),n3=c.size();
	reverse(a.begin(),a.end()),reverse(b.begin(),b.end()),reverse(c.begin(),c.end());
	a="!"+a,b="@"+b,c="#"+c;
	for(int i=1;i<=n1;i++)a[i]-='0'; 
	for(int i=1;i<=n2;i++)b[i]-='0';
	for(int i=1;i<=n3;i++)c[i]-='0';
	for(int i=n1;i<=14;i++)for(int j=n2;j<=14;j++)for(int k=max(max(i,j),n3);k<=14&&k-max(i,j)<2;k++){
		if(len<i+j+k)continue;
		memset(fr,-1,sizeof(fr));
		fr[0][0][0][0][0]=0;
		for(int l=1;l<=k;l++){
			int c1=(l<=i?9:0),c2=(l<=j?9:0);
			for(int o=0;o<=n1;o++)for(int p=0;p<=n2;p++)for(int q=0;q<=n3;q++)for(int i1=0;i1<2;i1++)if(fr[l-1][o][p][q][i1]>-1){
				for(int j1=0;j1<=c1;j1++)for(int k1=0;k1<=c2;k1++){
					int rim=o,mrs=p,ilc=q;
					if(rim<n1&&l<=i&&a[rim+1]==j1)rim++;
					if(mrs<n2&&l<=j&&b[mrs+1]==k1)mrs++;
					int getnum=j1+k1+i1;
					int ygl=getnum/10;
					if(ilc<n3&&getnum%10==c[ilc+1])ilc++;
					fr[l][rim][mrs][ilc][ygl]=j1,fo[l][rim][mrs][ilc][ygl]=k1,fm[l][rim][mrs][ilc][ygl]=i1;
					A[l][rim][mrs][ilc][ygl]=o,B[l][rim][mrs][ilc][ygl]=p,C[l][rim][mrs][ilc][ygl]=q;
				}
			}
		}
		if(fr[k][n1][n2][n3][0]>-1){
			len=i+j+k;
			S1=S2=S3="";
			int fbk=k,aqua=n1,mst=n2,wtm=n3,sora=0;
			while(fbk>0){
				if(fbk<=i)S1+=(char)(fr[fbk][aqua][mst][wtm][sora]+'0');
				if(fbk<=j)S2+=(char)(fo[fbk][aqua][mst][wtm][sora]+'0');
				int rbc=fr[fbk][aqua][mst][wtm][sora]+fo[fbk][aqua][mst][wtm][sora]+fm[fbk][aqua][mst][wtm][sora];
				S3+=(char)(rbc%10+'0');
				int sui=fbk,bok=aqua,luna=mst,towa=wtm,azki=sora;
				fbk--;
				aqua=A[sui][bok][luna][towa][azki],mst=B[sui][bok][luna][towa][azki],wtm=C[sui][bok][luna][towa][azki],sora=fm[sui][bok][luna][towa][azki];
			}
			ans=S1+"+"+S2+"="+S3;
		}
	}
	cout<<ans;
}