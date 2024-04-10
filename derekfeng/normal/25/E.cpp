#include <bits/stdc++.h>
using namespace std;
void read(string &s){
	char ch=getchar();s="";
	for (;ch==' '||ch=='\n';ch=getchar());
	for (;ch!=' '&&ch!='\n';s+=ch,ch=getchar());
}
void write(int x){
	if (x>9) write(x/10);
	putchar(x%10+'0');
}
string S,rS,s[3];
int ans=3e5;
int z[300004];
void Z(){
	int l=0,r=0;
    for (int i=1;i<S.size();i++){
        if (i>r){
            l=i,r=i;
            while (r<S.size() && S[r-l]==S[r]) r++;
            z[i]=r-l,r--;
        }else{
            int k=i-l;
            if (z[k]<r-i+1) z[i]=z[k];
            else{
                l=i;
                while (r<S.size() && S[r-l]==S[r]) r++;
                z[i]=r-l,r--;
        	}
        }
    }
}
void MAIN(string a,string b,string c){
	S=b+"$"+a,Z();
	int Len=a.size()+b.size(),wic=a.size();
	for (int i=0;i<a.size();i++)
		if(z[i+b.size()+1]==b.size() || z[i+b.size()+1]+b.size()+i+1==S.size())
			if (max(a.size(),i+b.size())<Len)
				Len=max(a.size(),i+b.size()),wic=i;
	if (Len==a.size()) rS=a;
	else{
		if (wic>0) rS=a.substr(0,wic);
		rS+=b;
	}
	S=c+"$"+rS,Z();
	Len=rS.size()+c.size();
	for (int i=0;i<rS.size();i++)
		if(z[i+c.size()+1]==c.size() || z[i+c.size()+1]+c.size()+i+1==S.size())
			if (max(rS.size(),i+c.size())<Len)
				Len=max(rS.size(),i+c.size());
	ans=min(ans,Len);
}
int main(){
	for (int i=0;i<3;i++) read(s[i]);
	for (int i=0;i<3;i++)
		for (int j=0;j<3;j++) if (i!=j)
			for (int k=0;k<3;k++) if (k!=i && k!=j)
				MAIN(s[i],s[j],s[k]);
	write(ans);
}