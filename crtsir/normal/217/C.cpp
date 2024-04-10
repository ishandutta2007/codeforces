#include<bits/stdc++.h>
using namespace std;
int a[18][18],x[18][18],o[18][18],cnt,st[1000003],tor[1000003],tol[1000003];
string s;
int dfs(int p){
	if(s[p]!='('){
		if(s[p]=='1')return 8;
		if(s[p]=='0')return 1;
		return 6;
	}
	int l=p+1,r=((s[p+1]=='(')?tor[p+1]+1:p+2)+1;
	int sjc_ak_ioi=dfs(l),zxb_ak_ioi=dfs(r);
	if(s[r-1]=='|')return o[sjc_ak_ioi][zxb_ak_ioi];
	if(s[r-1]=='^')return x[sjc_ak_ioi][zxb_ak_ioi];
	if(s[r-1]=='&')return a[sjc_ak_ioi][zxb_ak_ioi];
}
int pdq(){
	for(int i=0,j;i<s.size();i++)
		if(s[i]=='(')
			st[cnt++]=i;
		else
			if(s[i]==')')
				j=st[--cnt],
				tor[j]=i,
				tol[i]=j;
	return dfs(0);
}
int main(){
	ios_base::sync_with_stdio(0);
	cin>>s>>s;
	//if(s[0]!='(')s='('+s+')';
	for(int i=0;i<16;i++)
		for(int j=0;j<16;j++)
			for(int x1=0;x1<2;x1++)
				for(int x2=0;x2<2;x2++)
					for(int y1=0;y1<2;y1++)
						for(int y2=0;y2<2;y2++){
							if(x1==0&&x2==0&&!(i&1))continue;
							if(x1==0&&x2==1&&!(i&2))continue;
							if(x1==1&&x2==0&&!(i&4))continue;
							if(x1==1&&x2==1&&!(i&8))continue;
							if(y1==0&&y2==0&&!(j&1))continue;
							if(y1==0&&y2==1&&!(j&2))continue;
							if(y1==1&&y2==0&&!(j&4))continue;
							if(y1==1&&y2==1&&!(j&8))continue;
							{
								int z1=(x1&y1),z2=(x2&y2);
								if(z1==0&&z2==0)a[i][j]|=1;
								if(z1==0&&z2==1)a[i][j]|=2;
								if(z1==1&&z2==0)a[i][j]|=4;
								if(z1==1&&z2==1)a[i][j]|=8;
							}
							{
								int z1=(x1|y1),z2=(x2|y2);
								if(z1==0&&z2==0)o[i][j]|=1;
								if(z1==0&&z2==1)o[i][j]|=2;
								if(z1==1&&z2==0)o[i][j]|=4;
								if(z1==1&&z2==1)o[i][j]|=8;
							}
							{
								int z1=(x1^y1),z2=(x2^y2);
								//if(i==6&&j==6)cout<<z1<<' '<<z2<<endl;
								if(z1==0&&z2==0)x[i][j]|=1;
								if(z1==0&&z2==1)x[i][j]|=2;
								if(z1==1&&z2==0)x[i][j]|=4;
								if(z1==1&&z2==1)x[i][j]|=8;
							}
						}
	if(pdq()&6)
		cout<<"YES";
	else
		cout<<"NO";
}