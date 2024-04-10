#include<bits/stdc++.h>
using namespace std;
int n,m,t;
string s[103];
int sum[103][103];
int main(){cin>>t;
	while(t--){
		cin>>n>>m;
		for(int i=0;i<n;i++)
			cin>>s[i];
		for(int i=1;i<=n;i++)
			for(int j=1;j<=m;j++)
				sum[i][j]=(s[i-1][j-1]-'0');
		for(int i=1;i<=n;i++)
			for(int j=0;j<=m;j++)
				sum[i][j]+=sum[i-1][j];
		for(int i=0;i<=n;i++)
			for(int j=1;j<=m;j++)
				sum[i][j]+=sum[i][j-1]; 
		bool ok=1;
		for(int i=0;i<n;i++)
			for(int j=0;j<m;j++)
				if(s[i][j]=='1'&&(i==0||s[i-1][j]=='0')&&(j==0||s[i][j-1]=='0')){
					int k,l;
					for(k=i;k<n;k++)
						if(s[k][j]=='0')
							break;
					for(l=j;l<m;l++)
						if(s[i][l]=='0')
							break;
					k--;l--;
					if(sum[k+1][l+1]-sum[k+1][j]-sum[i][l+1]+sum[i][j]!=(k-i+1)*(l-j+1))
						ok=0;
					//[i,k] [j,l]
					for(int o=i;o<=k;o++){
						if(j>0)
							if(s[o][j-1]=='1')
								ok=0;
						if(l<m-1)
							if(s[o][l+1]=='1')
								ok=0;
					}
					for(int o=j;o<=l;o++){
						if(i>0)
							if(s[i-1][o]=='1')
								ok=0;
						if(k<n-1)
							if(s[k+1][o]=='1')
								ok=0;
					}
				}
		if(ok)
			cout<<"Yes\n";
		else
			cout<<"No\n";
	}
}