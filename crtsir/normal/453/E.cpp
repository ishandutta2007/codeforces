#include<bits/stdc++.h>
using namespace std;
const int len=100,inf=1926081724;
int n,s[100003],r[100003],m[100003],lazy[1003];
bool Lazy[1003];
struct piiivector{
	int imp[len+3],sz;
	long long k[len+3],b[len+3];
}v[1003];
struct piivector{
	int sz,imp[len+3],idx[len+3];
}tmp;
piivector quicksort(int L,int R){
	piivector ret,a,b;ret.sz=R-L+1;
	if(L==R){
		ret.idx[0]=tmp.idx[L];
		ret.imp[0]=tmp.imp[L];
		return ret;
	}
	a=quicksort(L,(L+R)/2);
	b=quicksort((L+R)/2+1,R);
	for(register int i=0,j=0;i+j<ret.sz;){
		if(i==a.sz){
			ret.imp[i+j]=b.imp[j];
			ret.idx[i+j]=b.idx[j];
			j++;continue;
		}if(j==b.sz){
			ret.imp[i+j]=a.imp[i];
			ret.idx[i+j]=a.idx[i];
			i++;continue;
		}
		if(a.imp[i]<b.imp[j]){
			ret.imp[i+j]=a.imp[i];
			ret.idx[i+j]=a.idx[i];
			i++;
		}else{
			ret.imp[i+j]=b.imp[j];
			ret.idx[i+j]=b.idx[j];
			j++;
		}
	}return ret;
}
void update(int x){
	v[x].sz=0;
	int L=x*len,R=min(x*len+len,n);
	tmp.sz=0;
	for(int i=L;i<R;i++){
		if(r[i]==0)
			tmp.imp[tmp.sz]=inf;
		else
			tmp.imp[tmp.sz]=(m[i]-s[i])/r[i];
		tmp.idx[tmp.sz++]=i;
	}tmp=quicksort(0,tmp.sz-1);
	long long k=0,b=0;
	for(register int i=L;i<R;i++){
		k+=r[i];
		b+=s[i];
	}
	for(register int i=0;i<tmp.sz;i++){
		int X=tmp.idx[i];
		if(tmp.imp[i]!=inf&&(i==0||tmp.imp[i]!=tmp.imp[i-1])){
			v[x].imp[v[x].sz]=tmp.imp[i];
			v[x].k[v[x].sz]=k;
			v[x].b[v[x].sz++]=b;
		}
		if(r[X]){
			b+=(m[X]-s[X]);
			k-=r[X];
		}
	}
	v[x].imp[v[x].sz]=inf;
	v[x].k[v[x].sz]=0;
	v[x].b[v[x].sz++]=b;
}
int read(){
	int ret=0;
		char c='?';
	while(c>'9'||c<'0')
		c=getchar();
	while(c>='0'&&c<='9'){
		ret=ret*10+c-'0';
		c=getchar();
	}
	return ret;
}
void write(long long x){
	string s="\n";
	while(x){
		s+=(x%10|48);
		x/=10;
	}
	if(s.size()==1)s+="0";
	for(int i=s.size()-1;i>=0;i--)
		putchar(s[i]);
}
int main(){
	n=read();
	for(register int i=0;i<n;i++){
		s[i]=read();
		m[i]=read();
		r[i]=read();
	}
	for(int i=0;i<(n+len-1)/len;i++)
		update(i);
	int T=read(),t,L,R;
	while(T--){
		t=read();
		L=read();
		R=read();
		L--;
		R--;
		long long ans=0;
		int to=(L/len+1)*len,qaqq=L/len;
		long long dt=t-lazy[qaqq];
		if(L/len==R/len){
			int frm=(L/len)*len,to=min(n-1,(R/len+1)*len-1);
			for(register int i=frm;i<L;i++)
				s[i]=min(1ll*m[i],s[i]+dt*r[i]);
			for(register int i=L;i<=R;i++){
				ans+=min(1ll*m[i],dt*r[i]+s[i]);
				s[i]=0;
			}
			for(register int i=to;i>R;i--)
				s[i]=min(1ll*m[i],s[i]+dt*r[i]);
			Lazy[qaqq]=0;
			lazy[qaqq]=t;
			update(qaqq);
			write(ans);
			continue;
		}
		for(register int i=to-len;i<L;i++)
			s[i]=min(1ll*m[i],s[i]+dt*r[i]);
		bool go=0;
		while(L!=to&&L<=R){
			ans+=min(r[L]*dt+s[L],1ll*m[L]);
			s[L++]=0;
			go=1;
		}
		if(go){
			update(qaqq);
			Lazy[qaqq]=0;
			lazy[qaqq]=t;
			go=0;
		}
		to=(R/len)*len-1,qaqq=R/len;dt=t-lazy[qaqq];
		for(register int i=to+len;i>R;i--)
			s[i]=min(1ll*m[i],s[i]+dt*r[i]);
		while(R!=to&&R>=L){
			ans+=min(r[R]*dt+s[R],1ll*m[R]);
			s[R--]=0;
			go=1;
		}
		if(go){
			update(qaqq);
			lazy[qaqq]=t;
			Lazy[qaqq]=0;
		}
		int ll,rr,mid,fad=L/len,now;
		for(;L+len-1<=R;L+=len){
			now=t-lazy[fad];
			ll=0;rr=v[fad].sz-1;
			while(ll!=rr){
				mid=(ll+rr)>>1;
				if(now<=v[fad].imp[mid])
					rr=mid;
				else
					ll=mid+1;
			}
			ans+=v[fad].k[ll]*now+v[fad].b[ll];
//			for(int i=0;i<v[fad].sz;i++)
//				cout<<v[fad].imp[i]<<' '<<v[fad].k[i]<<' '<<v[fad].b[i]<<'|';
//			cout<<endl;
			lazy[fad]=t;
			if(!Lazy[fad]){
				for(register int i=L;i<min(n,L+len);i++)
					s[i]=0;
				Lazy[fad]=1;
				update(fad); 
			}
			fad++;
		}
		write(ans);
	}
}