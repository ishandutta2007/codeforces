#include <bits/stdc++.h>
using namespace std;
int n,K,z[500005];
string s;
void Z(){
    int l=0,r=0;
    for(int i=1;i<n;i++){
        if(i>r){
            l=i,r=i;
            while(r<n&&s[r-l]==s[r])r++;
            z[i]=r-l,r--;
		}else{
            int k=i-l;
            if(z[k]<r-i+1)z[i]=z[k];
            else{
                l=i;
                while(r<n&&s[r-l]==s[r])r++;
                z[i]=r-l,r--;
        	}
        }
    }
}
int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    cin>>n>>K>>s;Z();
	int cur=1;
	for(int i=1;i<n;i++){
		if(s[i]>s[i%cur])break;
		if(s[i]<s[i%cur]){cur=i+1;continue;}
		int m=i-cur+1;
		if(m==cur){cur=i+1;continue;}
		if(z[m]<=cur-m){
			if(s[m+z[m]]>s[z[m]])cur=i+1;
			continue;
		}
		if(z[cur-m]<m){
			if(s[cur-m+z[cur-m]]<s[z[cur-m]])cur=i+1;
			continue;
		}
		cur=i+1;
	}
	for(int i=0;i<K;i++)cout<<s[i%cur];
}