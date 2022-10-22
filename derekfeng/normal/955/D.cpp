#include<bits/stdc++.h>
using namespace std;
void read(int &x){
	register char ch=getchar();x=0;
	for(;ch<'0'||ch>'9';ch=getchar());
	for(;ch>='0'&&ch<='9';x=x*10+ch-'0',ch=getchar());
}
void reads(string &s){
	register char ch=getchar();s="";
	for(;ch<'a'||ch>'z';ch=getchar());
	for(;ch>='a'&&ch<='z';s+=ch,ch=getchar());
}
void write(int x){
	if(x>9)write(x/10);
	putchar(x%10+'0');
}
void output(int pos1,int pos2){
	puts("Yes");
	write(pos1),putchar(' '),write(pos2);
	exit(0); 
}
int n,m,K,z[1000004],z_[500004],lft[500005],rit[500005];
string s,t,S;
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
                while (r<=S.size() && S[r-l]==S[r]) r++;
                z[i]=r-l,r--;
        	}
        }
    }
    for(int i=0;i<n;i++)
    	z_[i+1]=z[m+1+i];
}
int cnt,L[1000004],R[1000004],dat[1000004];
int make_tree(int l,int r){
	int id=++cnt;
	if(l==r) return id;
	L[id]=make_tree(l,(l+r)/2);
	R[id]=make_tree((l+r)/2+1,r);
	return id;
}
void memset_tree(int id,int l,int r,int x){
	dat[id]=x;
	if(l!=r)memset_tree(L[id],l,(l+r)/2,x),memset_tree(R[id],(l+r)/2+1,r,x);
}
void upd_min(int id,int l,int r,int a,int b,int x){
	if(b<l||r<a||dat[id]<x)return;
	if(a<=l&&r<=b){
		dat[id]=x;
		return;
	}
	upd_min(L[id],l,(l+r)/2,a,b,x),upd_min(R[id],(l+r)/2+1,r,a,b,x);
}
void put_min(int id,int l,int r,int x,int *a){
	x=min(x,dat[id]);
	if(l==r)a[l]=x+l;
	else put_min(L[id],l,(l+r)/2,x,a),put_min(R[id],(l+r)/2+1,r,x,a);
}
int main(){
	read(n),read(m),read(K),reads(s),reads(t),S=t+"|"+s;
	Z();
	for(int i=1;i<=n;i++)if(z_[i]>=m)
		for(int j=1;j+2*K-1<=n;j++)if(j<=i&&i+m-1<=j+2*K-1){
			output(j,j+K);
		}
	for(int i=1;i<=n;i++)z_[i]=min(z_[i],K);
	make_tree(1,m),memset_tree(1,1,m,1e7);
	for(int i=1;i<=n;i++)if(z_[i]>0&&i+z_[i]-1>=K){
		int num=i-K,L=(num<0?K-i+1:1);
		upd_min(1,1,m,L,z_[i],num);
	}
	put_min(1,1,m,1e7,lft);
	reverse(s.begin(),s.end()),reverse(t.begin(),t.end()),S=t+"|"+s;
	Z(),memset_tree(1,1,m,1e7);
	for(int i=1;i<=n;i++)z_[i]=min(z_[i],K);
	for(int i=1;i<=n;i++)if(z_[i]>0&&i+z_[i]-1>=K){
		int num=i-K,L=(num<0?K-i+1:1);
		upd_min(1,1,m,L,z_[i],num);
	}
	put_min(1,1,m,1e7,rit);
	for(int i=1;i<m;i++)if(lft[i]+rit[m-i]+2*K-2<=n)output(lft[i],n-rit[m-i]-K+2);
	puts("No");
}