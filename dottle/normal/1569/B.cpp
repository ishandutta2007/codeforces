#include<bits/stdc++.h>
const int N=200050;
using namespace std;

string s;
int t,n,a[N];

int main(){
	ios::sync_with_stdio(false);
	cin>>t;
	while(t--){
		cin>>n>>s;
		int fl=0,pr=-1,fs=0,cnt=0;
		memset(a,-1,sizeof(a));
		for(int i=0;i<n;i++)
			if(s[i]=='2'){
				cnt++;
				if(~pr)a[pr]=i;
				else fs=i;
				pr=i;
			}
		if(cnt<=2&&cnt)puts("NO");
		else{
			puts("YES");
			a[pr]=fs;
			for(int i=0;i<n;i++,putchar('\n'))
				for(int j=0;j<n;j++)
					if(i==j)putchar('X');else
					if(a[i]==j)putchar('+');
					else if(a[j]==i)putchar('-');
					else putchar('=');
		}
	}
}