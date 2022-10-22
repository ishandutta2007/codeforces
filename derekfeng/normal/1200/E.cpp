#include<bits/stdc++.h>
using namespace std;
void read(string &s){
	s="";char ch=getchar();
	for (;ch==' '||ch=='\n';ch=getchar());
	for (;ch!=' '&&ch!='\n';s+=ch,ch=getchar());
}
int z[1000004];
void z_function(string go){
    int l=0,r=0;
    for (int i=1;i<go.size();i++){
        if (i>r){
            l=i,r=i;
            while (r<go.size() && go[r-l]==go[r]) r++;
            z[i]=r-l,r--;
        }else{
            int k=i-l;
            if (z[k]<r-i+1) z[i]=z[k];
            else{
                l=i;
                while (r<go.size() && go[r-l]==go[r]) r++;
                z[i]=r-l,r--;
        	}
        }
    } 
}
int n;
string s,ans;
int main(){
	cin>>n;
	while (n--){
		read(s);
		string go=s+"?"+ans.substr(ans.size()-min(ans.size(),s.size())); 
		z_function(go);
		int a=0;
		for (int i=s.size()+1;i<go.size();i++) if (z[i]+i==go.size()) a=max(a,z[i]);
		ans+=s.substr(a); 
	}
	printf("%s",ans.c_str());
}